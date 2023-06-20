#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QWidget>
#include <QKeyEvent>

#include <QSqlDatabase>

#include "Snake.h"
//#include "Mainwindow.h"




//QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
//QT_END_NAMESPACE

class Game : public QDialog

{
    Q_OBJECT

public:
    explicit Game(QWidget *parent, int level);
    ~Game();

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *eventPress);

private:
    Ui::Game *ui;

    QSqlDatabase db;
    bool setLevelData(int level);

    Snake *snake[10];

    int startTime;
    int inGameTime=0;
    int timerId;

    int initSpeed;
    int currentSpeed;

    QImage field;

    int snakesQty;
    int currentSnake=0;
    int level;

    void changeDirection(int key, int currentSnake);
    void currentStatusIndication(QPainter &);

    bool inGame;

    bool shakesCollision();
    bool checkSnakePairCollision(int headSnake,int bodySnake);
};

#endif // GAME_H
