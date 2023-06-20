#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include "Mainwindow.h"


class Snake : public QWidget
{
    Q_OBJECT
public:
    //explicit Snake(QWidget *parent = nullptr);
    Snake (int startX, int startY, int direction, int length);
    int direction;

    int body_X[ALL_DOTS];
    int body_Y[ALL_DOTS];
    int bodyLength;
    void draw(QPainter &qp);
    void passiveSnakeImage();
    void activeSnakeImage();

    bool move();
    bool headCollision (int objXpos, int objYpos);
    void changeDirection(int direction);


private:

    QImage bodyPic;
    QImage headPic;


    void loadSnakeImages(int colorScheme);
    void initPosition(int startX, int startY, int direction);
    bool checkBorderCrossing();
    bool checkSelfBiting();

signals:

};

#endif // SNAKE_H
