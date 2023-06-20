#include "Mainwindow.h"
#include "qdatetime.h"
#include "ui_mainwindow.h"
#include "Game.h"
#include <QSignalMapper>

Game *gameboard;

int MainWindow::levelTime[LEVELS_NUM]={0,0,0,0,0,0};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameButtonsClickMapping();

    QMainWindow::setStatusBar(nullptr);
    this->setFixedSize(this->width(),this->height()); //showFullScreen();
    this->setWindowTitle("Snakes Commander");
    createLevelTimeLabels();
    showLevelTime();
}

void MainWindow::startGame(int level)
{
   Game *gameboard = new  Game(nullptr, level);
   this->hide();
   gameboard->exec();

   this->show();
   showLevelTime();
}

void MainWindow::createLevelTimeLabels()
{
   for (int i=0;i<LEVELS_NUM;i++)
   {
       lbLevelTime[i]=new QLabel(this);
       lbLevelTime[i]->setGeometry(120+(i%3)*330,(i/3)*340+355,120,31);
       lbLevelTime[i]->setAlignment(Qt::AlignCenter);
       lbLevelTime[i]->setFont(QFont("Segoe Print",22,QFont::Bold,false));
       lbLevelTime[i]->setStyleSheet("color: rgb(255, 0, 0); background-color: rgb(252, 221, 223);");
       lbLevelTime[i]->show();
   }
}


void MainWindow::showLevelTime()
{
   for (int i=0;i<LEVELS_NUM;i++)
   {
       if (levelTime[i]==LEVEL_TIME)
       {
           lbLevelTime[i]->setStyleSheet("color: rgb(255, 255, 127); background-color: rgb(0, 85, 0);");
           lbLevelTime[i]->setFont(QFont("Segoe Print",16,QFont::Bold,false));
           lbLevelTime[i]->setText("Completed");
       }
       else
       {
         lbLevelTime[i]->setText(QTime(0,0,0,0).addSecs(levelTime[i]).toString("m:ss"));
       }
   }
}


void MainWindow::gameButtonsClickMapping()
{
   QSignalMapper *signalMapper = new QSignalMapper;

   connect(ui->pbLevel1, SIGNAL(clicked()), signalMapper, SLOT (map()));
   connect(ui->pbLevel2, SIGNAL(clicked()), signalMapper, SLOT (map()));
   connect(ui->pbLevel3, SIGNAL(clicked()), signalMapper, SLOT (map()));
   connect(ui->pbLevel4, SIGNAL(clicked()), signalMapper, SLOT (map()));
   connect(ui->pbLevel5, SIGNAL(clicked()), signalMapper, SLOT (map()));
   connect(ui->pbLevel6, SIGNAL(clicked()), signalMapper, SLOT (map()));

   signalMapper->setMapping(ui->pbLevel1, 1);
   signalMapper->setMapping(ui->pbLevel2, 2);
   signalMapper->setMapping(ui->pbLevel3, 3);
   signalMapper->setMapping(ui->pbLevel4, 4);
   signalMapper->setMapping(ui->pbLevel5, 5);
   signalMapper->setMapping(ui->pbLevel6, 6);

   connect(signalMapper, &QSignalMapper::mappedInt,this, &MainWindow::startGame);
}


MainWindow::~MainWindow()
{
    delete ui;
}
