#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlQuery>
#include <QLabel>

const int B_WIDTH = 960;  // game field width in pixels
const int B_HEIGHT = 960; // game field height in pixels
const int DOT_SIZE = 30;  // body "thickness" in pixels
const int ALL_DOTS = 960;
const int STEP = 1; // redraw frequency 1=best
const int SHOW_STEP = DOT_SIZE*2/3; // body part to show, DOT_SIZE=full body
const int LEVELS_NUM =6;
const int LEVEL_TIME = 120;

enum dir
{
    UP=1,
    DOWN=2,
    LEFT=3,
    RIGHT=4
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    static int levelTime [LEVELS_NUM];
    //static const int levelSpeed;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    void gameButtonsClickMapping();

    QLabel *lbLevelTime[LEVELS_NUM];

    void startGame(int level);
    void showLevelTime();
    void createLevelTimeLabels();
};

#endif // MAINWINDOW_H
