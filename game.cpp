#include "Game.h"
#include "ui_game.h"
#include "Mainwindow.h"

#include <QPainter>
#include <QTime>
#include <QMessageBox>
#include <QRectF>
#include <QSqlRecord>
#include <QSqlQuery>

Game::Game(QWidget *parent, int level)
    : QDialog(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height()); //showFullScreen();
    this->setWindowTitle("Snakes Commander");
    this->setWindowFlags(Qt::Window);
    QString boardPic = "./gamedata/boards/board"+QString::number(level)+".png";
    field.load(boardPic);

    bool isSet = setLevelData(level);

    if (!isSet)
        {
            QMessageBox::information(this, QString::number(snakesQty), "Cannot level data");
            this->close();
        }

    inGame = true;

    QTime startTimeC = QTime::currentTime();
    startTime = startTimeC.msecsSinceStartOfDay();
    timerId = this->startTimer(initSpeed);
}

Game::~Game()
{
    delete ui;
}

void Game::timerEvent(QTimerEvent *timeEvent)
{
    Q_UNUSED(timeEvent);

    if (inGame)
    {

        QTime qtime = QTime::currentTime();
        int ms = qtime.msecsSinceStartOfDay();

        inGameTime = ms-startTime;

        if (inGameTime>LEVEL_TIME*1000)
        {
            inGame=false;
        }
    }

    if (inGame)
    {
        for(int i=0; i<snakesQty;i++)
        {
            if (!snake[i]->move()) inGame=false;
        }
        if (shakesCollision()) inGame=false;
    }

    update();//repaint();
}


void Game::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();

    if (((key == Qt::Key_Left)||(key == Qt::Key_A))&&(snake[currentSnake]->direction!=RIGHT))
        snake[currentSnake]->changeDirection(LEFT);
    if (((key == Qt::Key_Right)||(key == Qt::Key_D))&&(snake[currentSnake]->direction!=LEFT))
        snake[currentSnake]->changeDirection(RIGHT);
    if (((key == Qt::Key_Up)||(key == Qt::Key_W))&&(snake[currentSnake]->direction!=DOWN))
        snake[currentSnake]->changeDirection(UP);
    if (((key == Qt::Key_Down)||(key == Qt::Key_S))&&(snake[currentSnake]->direction!=UP))
        snake[currentSnake]->changeDirection(DOWN);

    if (key == Qt::Key_Escape) QCoreApplication::quit();

    if ((!inGame)&&(key == Qt::Key_Space)) this->close();
}

void Game::mousePressEvent(QMouseEvent *eventPress)
{
    int cursorPosX=eventPress->x();
    int cursorPosY=eventPress->y();

    for(int snakeNum=0; snakeNum<snakesQty;snakeNum++)
    {
        if (snake[snakeNum]->headCollision(cursorPosX,cursorPosY))
        {
            snake[currentSnake]->passiveSnakeImage();
            currentSnake=snakeNum;
            snake[currentSnake]->activeSnakeImage();
            break;
        }
    }
}


void Game::paintEvent(QPaintEvent *e)
{
    setCursor(Qt::PointingHandCursor);

    Q_UNUSED(e);
    QPainter qp(this);

    qp.drawImage(0, 0, field);

    for (int i=0; i<snakesQty; i++)
        snake[i]->draw(qp);

    currentStatusIndication(qp);
}


bool Game::setLevelData(int level)
{
    db = QSqlDatabase::addDatabase("QSQLITE", "local");
    db.setDatabaseName("./gamedata/levels.db");

    if (!db.open()) return false;

    QSqlQuery query(db);
    QString queryStr = "SELECT * FROM LevelSnakes WHERE levelNo = " + QString::number(level);
    query.exec(queryStr);

    int snakenum=0;
    while (query.next())
    {
        QSqlRecord rec = query.record();

        int posX=rec.value(2).toInt();
        int posY=rec.value(3).toInt();
        int direction=rec.value(4).toInt();
        int length=rec.value(5).toInt();

        snake[snakenum] = new Snake(posX, posY, direction, length);

        if (rec.value(1).toInt()==1) this->initSpeed=rec.value(6).toInt();

        snakenum++;
    }
    snakesQty=snakenum;

    this->level=level;

    snake[0]->activeSnakeImage();

    db.close();

    return true;
}

void Game::currentStatusIndication(QPainter &qp)
{
    QString inGameTimeStr=QTime(0,0,0,0).addSecs(inGameTime/1000).toString("m:ss");

    qp.setFont(QFont("Courier", 35, QFont::DemiBold));

    qp.setPen(QColor(Qt::yellow));

    qp.drawText(QRectF(1030,250,91,61), Qt::AlignCenter,inGameTimeStr);
    qp.drawText(QRectF(1030,345,91,61), Qt::AlignCenter, QString::number(level));
    qp.drawText(QRectF(1030,440,91,61), Qt::AlignCenter, QString::number(1000/initSpeed));
    qp.drawText(QRectF(1030,535,91,61), Qt::AlignCenter, QString::number(snakesQty));

    if(!inGame) // GAME OVER
    {

        killTimer(timerId);timerId = 0;

        if (MainWindow::levelTime[level-1]<inGameTime/1000)
            MainWindow::levelTime[level-1]=inGameTime/1000; // return level's game time to main window


        QImage endframe;
        endframe.load("./gamedata/boards/endframe.jpg");
        qp.drawImage(220, 380, endframe);


        QString gameTimeMsg = "Your time is "+inGameTimeStr;

        qp.drawText(QRectF(0,0,B_WIDTH,B_HEIGHT), Qt::AlignCenter, gameTimeMsg);
        qp.drawText(QRectF(0,0,B_WIDTH,B_HEIGHT+100), Qt::AlignCenter, "Press any key to continue...");

        if(inGameTime>LEVEL_TIME*1000)
        {
            qp.setPen(QColor(Qt::green));
            qp.drawText(QRectF(0,0,B_WIDTH,B_HEIGHT-100), Qt::AlignCenter, "YOU'VE COMPLETED THE LEVEL!");
        }
        else
        {
            qp.setPen(QColor(Qt::red));
            qp.drawText(QRectF(0,0,B_WIDTH,B_HEIGHT-100), Qt::AlignCenter, "GAME OVER");
        }

    }
}


bool Game::shakesCollision()
{
    for (int i=0; i<snakesQty;i++)
        for (int j=0;j<snakesQty;j++)
        {
            if (i!=j)
            {
                if (checkSnakePairCollision(i,j)) return true;
            }
        }
    return false;
}

bool Game::checkSnakePairCollision(int headSnake,int bodySnake)
{
    for (int i=0; i<=snake[bodySnake]->bodyLength; i++)
    {
        int bodySnakeXpos=snake[bodySnake]->body_X[i]+DOT_SIZE/2;
        int bodySnakeYpos=snake[bodySnake]->body_Y[i]+DOT_SIZE/2;

        if (snake[headSnake]->headCollision(bodySnakeXpos,bodySnakeYpos))
            return true;
    }
    return false;
}
