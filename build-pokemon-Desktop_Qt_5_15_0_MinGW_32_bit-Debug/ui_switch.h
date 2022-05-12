/********************************************************************************
** Form generated from reading UI file 'switch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCH_H
#define UI_SWITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Switch
{
public:
    QLabel *bg;
    QLabel *pokemon1;
    QLabel *pokemon2;
    QLabel *pokemon3;
    QLabel *pokemon4;
    QLabel *pokemon5;
    QLabel *cancel;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;

    void setupUi(QWidget *Switch)
    {
        if (Switch->objectName().isEmpty())
            Switch->setObjectName(QString::fromUtf8("Switch"));
        Switch->resize(512, 368);
        bg = new QLabel(Switch);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(0, -10, 521, 381));
        bg->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partybg.png")));
        bg->setScaledContents(true);
        pokemon1 = new QLabel(Switch);
        pokemon1->setObjectName(QString::fromUtf8("pokemon1"));
        pokemon1->setGeometry(QRect(50, 20, 201, 41));
        pokemon1->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon1->setScaledContents(true);
        pokemon2 = new QLabel(Switch);
        pokemon2->setObjectName(QString::fromUtf8("pokemon2"));
        pokemon2->setGeometry(QRect(50, 70, 201, 41));
        pokemon2->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon2->setScaledContents(true);
        pokemon3 = new QLabel(Switch);
        pokemon3->setObjectName(QString::fromUtf8("pokemon3"));
        pokemon3->setGeometry(QRect(50, 120, 201, 41));
        pokemon3->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon3->setScaledContents(true);
        pokemon4 = new QLabel(Switch);
        pokemon4->setObjectName(QString::fromUtf8("pokemon4"));
        pokemon4->setGeometry(QRect(50, 170, 201, 41));
        pokemon4->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon4->setScaledContents(true);
        pokemon5 = new QLabel(Switch);
        pokemon5->setObjectName(QString::fromUtf8("pokemon5"));
        pokemon5->setGeometry(QRect(50, 220, 201, 41));
        pokemon5->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon5->setScaledContents(true);
        cancel = new QLabel(Switch);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(390, 310, 101, 41));
        cancel->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyCancel.png")));
        cancel->setScaledContents(true);
        button1 = new QPushButton(Switch);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(400, 320, 80, 21));
        button1->setFlat(true);
        button2 = new QPushButton(Switch);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(50, 20, 201, 41));
        button2->setFlat(true);
        button3 = new QPushButton(Switch);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(50, 70, 201, 41));
        button3->setFlat(true);
        button4 = new QPushButton(Switch);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setGeometry(QRect(50, 120, 201, 41));
        button4->setFlat(true);
        button5 = new QPushButton(Switch);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setGeometry(QRect(50, 170, 201, 41));
        button5->setFlat(true);
        button6 = new QPushButton(Switch);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setGeometry(QRect(50, 220, 201, 41));
        button6->setFlat(true);

        retranslateUi(Switch);

        QMetaObject::connectSlotsByName(Switch);
    } // setupUi

    void retranslateUi(QWidget *Switch)
    {
        Switch->setWindowTitle(QCoreApplication::translate("Switch", "Form", nullptr));
        bg->setText(QString());
        pokemon1->setText(QString());
        pokemon2->setText(QString());
        pokemon3->setText(QString());
        pokemon4->setText(QString());
        pokemon5->setText(QString());
        cancel->setText(QString());
        button1->setText(QCoreApplication::translate("Switch", "PushButton", nullptr));
        button2->setText(QCoreApplication::translate("Switch", "PushButton", nullptr));
        button3->setText(QCoreApplication::translate("Switch", "PushButton", nullptr));
        button4->setText(QCoreApplication::translate("Switch", "PushButton", nullptr));
        button5->setText(QCoreApplication::translate("Switch", "PushButton", nullptr));
        button6->setText(QCoreApplication::translate("Switch", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Switch: public Ui_Switch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCH_H
