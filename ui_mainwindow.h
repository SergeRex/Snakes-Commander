/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lbbackground;
    QPushButton *pbLevel1;
    QPushButton *pbLevel2;
    QPushButton *pbLevel3;
    QPushButton *pbLevel4;
    QPushButton *pbLevel5;
    QPushButton *pbLevel6;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 759);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lbbackground = new QLabel(centralwidget);
        lbbackground->setObjectName(QString::fromUtf8("lbbackground"));
        lbbackground->setGeometry(QRect(0, 0, 1031, 801));
        lbbackground->setPixmap(QPixmap(QString::fromUtf8("gamedata/buttons/water.png")));
        lbbackground->setScaledContents(true);
        pbLevel1 = new QPushButton(centralwidget);
        pbLevel1->setObjectName(QString::fromUtf8("pbLevel1"));
        pbLevel1->setEnabled(true);
        pbLevel1->setGeometry(QRect(30, 80, 300, 300));
        pbLevel1->setCursor(QCursor(Qt::PointingHandCursor));
        pbLevel1->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 26, 84);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("gamedata/buttons/c1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLevel1->setIcon(icon);
        pbLevel1->setIconSize(QSize(300, 300));
        pbLevel2 = new QPushButton(centralwidget);
        pbLevel2->setObjectName(QString::fromUtf8("pbLevel2"));
        pbLevel2->setEnabled(true);
        pbLevel2->setGeometry(QRect(360, 80, 300, 300));
        pbLevel2->setCursor(QCursor(Qt::PointingHandCursor));
        pbLevel2->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 26, 84);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("gamedata/buttons/c2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLevel2->setIcon(icon1);
        pbLevel2->setIconSize(QSize(300, 300));
        pbLevel3 = new QPushButton(centralwidget);
        pbLevel3->setObjectName(QString::fromUtf8("pbLevel3"));
        pbLevel3->setEnabled(true);
        pbLevel3->setGeometry(QRect(690, 80, 300, 300));
        pbLevel3->setCursor(QCursor(Qt::PointingHandCursor));
        pbLevel3->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 26, 84);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("gamedata/buttons/c3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLevel3->setIcon(icon2);
        pbLevel3->setIconSize(QSize(300, 300));
        pbLevel4 = new QPushButton(centralwidget);
        pbLevel4->setObjectName(QString::fromUtf8("pbLevel4"));
        pbLevel4->setEnabled(true);
        pbLevel4->setGeometry(QRect(30, 420, 300, 300));
        pbLevel4->setCursor(QCursor(Qt::PointingHandCursor));
        pbLevel4->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 26, 84);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("gamedata/buttons/c4.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLevel4->setIcon(icon3);
        pbLevel4->setIconSize(QSize(300, 300));
        pbLevel5 = new QPushButton(centralwidget);
        pbLevel5->setObjectName(QString::fromUtf8("pbLevel5"));
        pbLevel5->setEnabled(true);
        pbLevel5->setGeometry(QRect(360, 420, 300, 300));
        pbLevel5->setCursor(QCursor(Qt::PointingHandCursor));
        pbLevel5->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 26, 84);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("gamedata/buttons/c5.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLevel5->setIcon(icon4);
        pbLevel5->setIconSize(QSize(300, 300));
        pbLevel6 = new QPushButton(centralwidget);
        pbLevel6->setObjectName(QString::fromUtf8("pbLevel6"));
        pbLevel6->setEnabled(true);
        pbLevel6->setGeometry(QRect(690, 420, 300, 300));
        pbLevel6->setCursor(QCursor(Qt::PointingHandCursor));
        pbLevel6->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 26, 84);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("gamedata/buttons/c6.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLevel6->setIcon(icon5);
        pbLevel6->setIconSize(QSize(300, 300));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 10, 891, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(29);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(170, 255, 255);"));
        label_8->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(780, 410, 111, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe Print"));
        font1.setPointSize(16);
        font1.setBold(false);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);\n"
"background-color: rgb(0, 78, 150);"));
        label_7->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(120, 70, 111, 31));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);\n"
"background-color: rgb(0, 78, 150);"));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(450, 70, 111, 31));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);\n"
"background-color: rgb(0, 78, 150);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(780, 70, 111, 31));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);\n"
"background-color: rgb(0, 78, 150);"));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(120, 410, 111, 31));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);\n"
"background-color: rgb(0, 78, 150);"));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(450, 410, 111, 31));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);\n"
"background-color: rgb(0, 78, 150);"));
        label_13->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbbackground->setText(QString());
        pbLevel1->setText(QString());
        pbLevel2->setText(QString());
        pbLevel3->setText(QString());
        pbLevel4->setText(QString());
        pbLevel5->setText(QString());
        pbLevel6->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Snakes Commander", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Level 6", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Level 1", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Level 2", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Level 3", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Level 4", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Level 5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
