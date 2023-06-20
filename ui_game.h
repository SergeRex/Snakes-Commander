/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStatusBar>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QStatusBar *statusbar;
    QLabel *label;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;

    void setupUi(QDialog *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(1150, 1000);
        Game->setStyleSheet(QString::fromUtf8(""));
        statusbar = new QStatusBar(Game);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));
        label = new QLabel(Game);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1030, 230, 90, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignCenter);
        frame = new QFrame(Game);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(1030, 250, 91, 61));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(Game);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(1030, 345, 91, 61));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(Game);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(1030, 440, 91, 61));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(Game);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(1030, 535, 91, 61));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(Game);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1030, 325, 90, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        label_2->setTextFormat(Qt::MarkdownText);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Game);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1030, 420, 90, 20));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        label_3->setTextFormat(Qt::MarkdownText);
        label_3->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(Game);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1030, 510, 90, 20));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        label_6->setTextFormat(Qt::MarkdownText);
        label_6->setAlignment(Qt::AlignCenter);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QDialog *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Game", nullptr));
        label->setText(QCoreApplication::translate("Game", "Time", nullptr));
        label_2->setText(QCoreApplication::translate("Game", "Level", nullptr));
        label_3->setText(QCoreApplication::translate("Game", "Speed", nullptr));
        label_6->setText(QCoreApplication::translate("Game", "Population", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
