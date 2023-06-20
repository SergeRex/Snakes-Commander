#include "Snake.h"
#include <qPainter>
#include <QMessageBox>
#include <math.h>

Snake::Snake(int startX, int startY, int direction, int bodyLength)
{
    this->bodyLength=bodyLength;
    this->direction=direction;
    passiveSnakeImage();
    initPosition(startX, startY, direction);
}

void Snake::passiveSnakeImage()
{
    bodyPic.load("./gamedata/snakeimg/bodyYE");
    headPic.load("./gamedata/snakeimg/headyellow"+QString::number(direction)+".png");
}

void Snake::activeSnakeImage()
{
    bodyPic.load("./gamedata/snakeimg/bodyRED");
    headPic.load("./gamedata/snakeimg/headred"+QString::number(direction)+".png");
}

void Snake::changeDirection(int direction)
{
    this->direction=direction;
    activeSnakeImage();
}

void Snake::initPosition(int startX, int startY, int direction)
{
    for (int n = 0; n < bodyLength; n++)
    {
        if (direction==RIGHT){body_X[n] = startX - n*STEP; body_Y[n] = startY;}
        if (direction==LEFT) {body_X[n] = startX + n*STEP; body_Y[n] = startY;}
        if (direction==UP)   {body_X[n] = startX; body_Y[n] = startY+n*STEP;}
        if (direction==DOWN) {body_X[n] = startX; body_Y[n] = startY-n*STEP;}
    }
}

bool Snake::move()
{
    if (checkBorderCrossing()) return false;
    if (checkSelfBiting()) return false;

    for (int z = bodyLength; z > 0; z--) {
        body_X[z] = body_X[(z - 1)];
        body_Y[z] = body_Y[(z - 1)];
    }

    if (direction==LEFT) body_X[0]-=STEP;
    if (direction==RIGHT) body_X[0]+=STEP;
    if (direction==UP) body_Y[0]-=STEP;
    if (direction==DOWN) body_Y[0]+=STEP;

    return true;
}

void Snake::draw(QPainter &qp)
{
    for (int z = 1; z < bodyLength; z+=SHOW_STEP*2/3)
        qp.drawImage(body_X[z], body_Y[z], bodyPic);

    qp.drawImage(body_X[0]-10, body_Y[0]-10, headPic);
}

bool Snake::checkBorderCrossing()
{
    if ((body_Y[0] >= B_HEIGHT-10)||(body_Y[0] < 25)||(body_X[0] >= B_WIDTH-10)||(body_X[0] < 25))
        return true;
    else
        return false;
}

bool Snake::headCollision (int objXpos, int objYpos)
{
    // X&Y distanse between centers of head and other object
    int distX=abs(body_X[0]+DOT_SIZE/2-objXpos);
    int distY=abs(body_Y[0]+DOT_SIZE/2-objYpos);

    if ((distX<DOT_SIZE)&&(distY<DOT_SIZE)) return true; // if centers close than object size
    return false;
}

bool Snake::checkSelfBiting()
{
    for (int n = bodyLength; n > 0; n--)
    {
        if ((n > 4) && (body_X[0] == body_X[n]) && (body_Y[0] == body_Y[n]))
        {
            return true;
        }
    }
    return false;
}
