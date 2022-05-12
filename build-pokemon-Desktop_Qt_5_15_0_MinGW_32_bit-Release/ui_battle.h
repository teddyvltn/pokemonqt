/********************************************************************************
** Form generated from reading UI file 'battle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLE_H
#define UI_BATTLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Battle
{
public:
    QLabel *myBox;
    QLabel *otherBox;
    QLabel *box;
    QLabel *myPokemon;
    QLabel *otherPokemon;
    QLabel *otherName;
    QLabel *myName;
    QLabel *myHealthBar;
    QLabel *otherHealthBar;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QLabel *boxMessage;
    QLabel *boxText;
    QLabel *myBall1;
    QLabel *myBall2;
    QLabel *myBall3;
    QLabel *myBall4;
    QLabel *myBall5;
    QLabel *myBall6;
    QLabel *otherBall1;
    QLabel *otherBall3;
    QLabel *otherBall4;
    QLabel *otherBall2;
    QLabel *otherBall6;
    QLabel *otherBall5;
    QLabel *box_2;

    void setupUi(QWidget *Battle)
    {
        if (Battle->objectName().isEmpty())
            Battle->setObjectName(QString::fromUtf8("Battle"));
        Battle->resize(512, 368);
        myBox = new QLabel(Battle);
        myBox->setObjectName(QString::fromUtf8("myBox"));
        myBox->setGeometry(QRect(280, 180, 211, 71));
        myBox->setPixmap(QPixmap(QString::fromUtf8(":/ui/img/battlePlayerBoxS.png")));
        myBox->setScaledContents(true);
        otherBox = new QLabel(Battle);
        otherBox->setObjectName(QString::fromUtf8("otherBox"));
        otherBox->setGeometry(QRect(30, 40, 211, 51));
        otherBox->setPixmap(QPixmap(QString::fromUtf8(":/ui/img/battleFoeBoxD.png")));
        otherBox->setScaledContents(true);
        box = new QLabel(Battle);
        box->setObjectName(QString::fromUtf8("box"));
        box->setGeometry(QRect(20, 270, 471, 91));
        box->setPixmap(QPixmap(QString::fromUtf8(":/ui/img/battleCommand.png")));
        box->setScaledContents(true);
        myPokemon = new QLabel(Battle);
        myPokemon->setObjectName(QString::fromUtf8("myPokemon"));
        myPokemon->setGeometry(QRect(50, 110, 181, 181));
        myPokemon->setPixmap(QPixmap(QString::fromUtf8(":/sprites/pokemon/back/2.png")));
        myPokemon->setScaledContents(true);
        otherPokemon = new QLabel(Battle);
        otherPokemon->setObjectName(QString::fromUtf8("otherPokemon"));
        otherPokemon->setGeometry(QRect(300, 10, 161, 161));
        otherPokemon->setPixmap(QPixmap(QString::fromUtf8(":/sprites/pokemon/back/2.png")));
        otherPokemon->setScaledContents(true);
        otherName = new QLabel(Battle);
        otherName->setObjectName(QString::fromUtf8("otherName"));
        otherName->setGeometry(QRect(80, 47, 131, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Pok\303\251mon DP Pro"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::NoAntialias);
        otherName->setFont(font);
        otherName->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        myName = new QLabel(Battle);
        myName->setObjectName(QString::fromUtf8("myName"));
        myName->setGeometry(QRect(332, 188, 141, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Pok\303\251mon DP Pro"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::NoAntialias);
        myName->setFont(font1);
        myName->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        myHealthBar = new QLabel(Battle);
        myHealthBar->setObjectName(QString::fromUtf8("myHealthBar"));
        myHealthBar->setGeometry(QRect(380, 212, 94, 7));
        myHealthBar->setPixmap(QPixmap(QString::fromUtf8(":/ui/img/overlay.png")));
        myHealthBar->setScaledContents(true);
        otherHealthBar = new QLabel(Battle);
        otherHealthBar->setObjectName(QString::fromUtf8("otherHealthBar"));
        otherHealthBar->setGeometry(QRect(115, 72, 94, 7));
        otherHealthBar->setPixmap(QPixmap(QString::fromUtf8(":/ui/img/overlay.png")));
        otherHealthBar->setScaledContents(true);
        button1 = new QPushButton(Battle);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(265, 280, 111, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Pok\303\251mon DP Pro"));
        font2.setPointSize(14);
        button1->setFont(font2);
        button1->setFlat(true);
        button2 = new QPushButton(Battle);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(376, 280, 111, 31));
        button2->setFont(font2);
        button2->setFlat(true);
        button3 = new QPushButton(Battle);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(265, 318, 111, 31));
        button3->setFont(font2);
        button3->setFlat(true);
        button4 = new QPushButton(Battle);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setGeometry(QRect(376, 318, 111, 31));
        button4->setFont(font2);
        button4->setFlat(true);
        boxMessage = new QLabel(Battle);
        boxMessage->setObjectName(QString::fromUtf8("boxMessage"));
        boxMessage->setGeometry(QRect(20, 270, 471, 91));
        boxMessage->setPixmap(QPixmap(QString::fromUtf8(":/ui/img/battleMessage.png")));
        boxMessage->setScaledContents(true);
        boxText = new QLabel(Battle);
        boxText->setObjectName(QString::fromUtf8("boxText"));
        boxText->setGeometry(QRect(40, 286, 441, 61));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush1(QColor(255, 255, 255, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        boxText->setPalette(palette);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Pok\303\251mon DP Pro"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        font3.setKerning(false);
        font3.setStyleStrategy(QFont::PreferDefault);
        boxText->setFont(font3);
        boxText->setContextMenuPolicy(Qt::DefaultContextMenu);
        boxText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        myBall1 = new QLabel(Battle);
        myBall1->setObjectName(QString::fromUtf8("myBall1"));
        myBall1->setGeometry(QRect(360, 160, 16, 16));
        myBall1->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        myBall1->setScaledContents(true);
        myBall2 = new QLabel(Battle);
        myBall2->setObjectName(QString::fromUtf8("myBall2"));
        myBall2->setGeometry(QRect(380, 160, 16, 16));
        myBall2->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        myBall2->setScaledContents(true);
        myBall3 = new QLabel(Battle);
        myBall3->setObjectName(QString::fromUtf8("myBall3"));
        myBall3->setGeometry(QRect(400, 160, 16, 16));
        myBall3->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        myBall3->setScaledContents(true);
        myBall4 = new QLabel(Battle);
        myBall4->setObjectName(QString::fromUtf8("myBall4"));
        myBall4->setGeometry(QRect(420, 160, 16, 16));
        myBall4->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        myBall4->setScaledContents(true);
        myBall5 = new QLabel(Battle);
        myBall5->setObjectName(QString::fromUtf8("myBall5"));
        myBall5->setGeometry(QRect(440, 160, 16, 16));
        myBall5->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        myBall5->setScaledContents(true);
        myBall6 = new QLabel(Battle);
        myBall6->setObjectName(QString::fromUtf8("myBall6"));
        myBall6->setGeometry(QRect(460, 160, 16, 16));
        myBall6->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        myBall6->setScaledContents(true);
        otherBall1 = new QLabel(Battle);
        otherBall1->setObjectName(QString::fromUtf8("otherBall1"));
        otherBall1->setGeometry(QRect(40, 20, 16, 16));
        otherBall1->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        otherBall1->setScaledContents(true);
        otherBall3 = new QLabel(Battle);
        otherBall3->setObjectName(QString::fromUtf8("otherBall3"));
        otherBall3->setGeometry(QRect(80, 20, 16, 16));
        otherBall3->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        otherBall3->setScaledContents(true);
        otherBall4 = new QLabel(Battle);
        otherBall4->setObjectName(QString::fromUtf8("otherBall4"));
        otherBall4->setGeometry(QRect(100, 20, 16, 16));
        otherBall4->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        otherBall4->setScaledContents(true);
        otherBall2 = new QLabel(Battle);
        otherBall2->setObjectName(QString::fromUtf8("otherBall2"));
        otherBall2->setGeometry(QRect(60, 20, 16, 16));
        otherBall2->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        otherBall2->setScaledContents(true);
        otherBall6 = new QLabel(Battle);
        otherBall6->setObjectName(QString::fromUtf8("otherBall6"));
        otherBall6->setGeometry(QRect(140, 20, 16, 16));
        otherBall6->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        otherBall6->setScaledContents(true);
        otherBall5 = new QLabel(Battle);
        otherBall5->setObjectName(QString::fromUtf8("otherBall5"));
        otherBall5->setGeometry(QRect(120, 20, 16, 16));
        otherBall5->setPixmap(QPixmap(QString::fromUtf8(":/img/ballempty.png")));
        otherBall5->setScaledContents(true);
        box_2 = new QLabel(Battle);
        box_2->setObjectName(QString::fromUtf8("box_2"));
        box_2->setGeometry(QRect(-20, -90, 561, 461));
        box_2->setPixmap(QPixmap(QString::fromUtf8(":/img/bg/Sky.png")));
        box_2->setScaledContents(true);
        box_2->raise();
        myBox->raise();
        otherBox->raise();
        myPokemon->raise();
        otherPokemon->raise();
        otherName->raise();
        myName->raise();
        myHealthBar->raise();
        otherHealthBar->raise();
        myBall1->raise();
        myBall2->raise();
        myBall3->raise();
        myBall4->raise();
        myBall5->raise();
        myBall6->raise();
        otherBall1->raise();
        otherBall3->raise();
        otherBall4->raise();
        otherBall2->raise();
        otherBall6->raise();
        otherBall5->raise();
        box->raise();
        button4->raise();
        button2->raise();
        button1->raise();
        button3->raise();
        boxMessage->raise();
        boxText->raise();

        retranslateUi(Battle);

        QMetaObject::connectSlotsByName(Battle);
    } // setupUi

    void retranslateUi(QWidget *Battle)
    {
        Battle->setWindowTitle(QCoreApplication::translate("Battle", "Form", nullptr));
        myBox->setText(QString());
        otherBox->setText(QString());
        box->setText(QString());
        myPokemon->setText(QString());
        otherPokemon->setText(QString());
        otherName->setText(QCoreApplication::translate("Battle", "TextLabel", nullptr));
        myName->setText(QCoreApplication::translate("Battle", "TextLabel", nullptr));
        myHealthBar->setText(QString());
        otherHealthBar->setText(QString());
        button1->setText(QCoreApplication::translate("Battle", "PushButton", nullptr));
        button2->setText(QCoreApplication::translate("Battle", "PushButton", nullptr));
        button3->setText(QCoreApplication::translate("Battle", "PushButton", nullptr));
        button4->setText(QCoreApplication::translate("Battle", "PushButton", nullptr));
        boxMessage->setText(QString());
        boxText->setText(QCoreApplication::translate("Battle", "TextLabel", nullptr));
        myBall1->setText(QString());
        myBall2->setText(QString());
        myBall3->setText(QString());
        myBall4->setText(QString());
        myBall5->setText(QString());
        myBall6->setText(QString());
        otherBall1->setText(QString());
        otherBall3->setText(QString());
        otherBall4->setText(QString());
        otherBall2->setText(QString());
        otherBall6->setText(QString());
        otherBall5->setText(QString());
        box_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Battle: public Ui_Battle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLE_H
