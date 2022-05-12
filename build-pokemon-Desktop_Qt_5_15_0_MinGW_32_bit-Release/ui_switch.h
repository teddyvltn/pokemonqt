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
    QLabel *pokemon3;
    QLabel *pokemon2;
    QLabel *pokemon1;
    QLabel *pokemon4;
    QLabel *pokemon5;
    QLabel *cancel;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QLabel *pokemon6;
    QPushButton *button7;
    QLabel *decor;
    QLabel *name1;
    QLabel *model1;
    QLabel *hp1;
    QLabel *decor_2;
    QLabel *hp2;
    QLabel *name2;
    QLabel *model2;
    QLabel *decor_3;
    QLabel *hp3;
    QLabel *name3;
    QLabel *model3;
    QLabel *decor_4;
    QLabel *hp4;
    QLabel *model4;
    QLabel *name4;
    QLabel *decor_5;
    QLabel *model5;
    QLabel *hp5;
    QLabel *name5;
    QLabel *name6;
    QLabel *decor_6;
    QLabel *hp6;
    QLabel *model6;

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
        pokemon3 = new QLabel(Switch);
        pokemon3->setObjectName(QString::fromUtf8("pokemon3"));
        pokemon3->setGeometry(QRect(20, 100, 231, 81));
        pokemon3->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon3->setScaledContents(true);
        pokemon2 = new QLabel(Switch);
        pokemon2->setObjectName(QString::fromUtf8("pokemon2"));
        pokemon2->setGeometry(QRect(260, 20, 231, 91));
        pokemon2->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon2->setScaledContents(true);
        pokemon1 = new QLabel(Switch);
        pokemon1->setObjectName(QString::fromUtf8("pokemon1"));
        pokemon1->setGeometry(QRect(20, 10, 231, 81));
        pokemon1->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon1->setScaledContents(true);
        pokemon4 = new QLabel(Switch);
        pokemon4->setObjectName(QString::fromUtf8("pokemon4"));
        pokemon4->setGeometry(QRect(260, 120, 231, 81));
        pokemon4->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon4->setScaledContents(true);
        pokemon5 = new QLabel(Switch);
        pokemon5->setObjectName(QString::fromUtf8("pokemon5"));
        pokemon5->setGeometry(QRect(20, 190, 231, 81));
        pokemon5->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon5->setScaledContents(true);
        cancel = new QLabel(Switch);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(380, 290, 151, 81));
        cancel->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyCancel.png")));
        cancel->setScaledContents(true);
        button1 = new QPushButton(Switch);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(400, 310, 111, 41));
        button1->setFlat(true);
        button2 = new QPushButton(Switch);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(20, 10, 221, 71));
        button2->setFlat(true);
        button3 = new QPushButton(Switch);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(260, 20, 221, 81));
        button3->setFlat(true);
        button4 = new QPushButton(Switch);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setGeometry(QRect(20, 100, 221, 81));
        button4->setFlat(true);
        button5 = new QPushButton(Switch);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setGeometry(QRect(260, 120, 221, 71));
        button5->setFlat(true);
        button6 = new QPushButton(Switch);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setGeometry(QRect(20, 190, 221, 71));
        button6->setFlat(true);
        pokemon6 = new QLabel(Switch);
        pokemon6->setObjectName(QString::fromUtf8("pokemon6"));
        pokemon6->setGeometry(QRect(260, 210, 231, 81));
        pokemon6->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyPanelRound.png")));
        pokemon6->setScaledContents(true);
        button7 = new QPushButton(Switch);
        button7->setObjectName(QString::fromUtf8("button7"));
        button7->setGeometry(QRect(260, 210, 221, 71));
        button7->setFlat(true);
        decor = new QLabel(Switch);
        decor->setObjectName(QString::fromUtf8("decor"));
        decor->setGeometry(QRect(20, 0, 51, 61));
        decor->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyBall.PNG")));
        decor->setScaledContents(false);
        name1 = new QLabel(Switch);
        name1->setObjectName(QString::fromUtf8("name1"));
        name1->setGeometry(QRect(98, 18, 141, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name1->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Pok\303\251mon DP Pro"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        name1->setFont(font);
        model1 = new QLabel(Switch);
        model1->setObjectName(QString::fromUtf8("model1"));
        model1->setGeometry(QRect(40, 10, 51, 61));
        model1->setPixmap(QPixmap(QString::fromUtf8(":/sprites/pokemon/back/2.png")));
        model1->setScaledContents(true);
        hp1 = new QLabel(Switch);
        hp1->setObjectName(QString::fromUtf8("hp1"));
        hp1->setGeometry(QRect(100, 50, 131, 18));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        hp1->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Pok\303\251mon DP Pro"));
        font1.setPointSize(14);
        hp1->setFont(font1);
        hp1->setScaledContents(true);
        decor_2 = new QLabel(Switch);
        decor_2->setObjectName(QString::fromUtf8("decor_2"));
        decor_2->setGeometry(QRect(260, 10, 51, 61));
        decor_2->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyBall.PNG")));
        decor_2->setScaledContents(false);
        hp2 = new QLabel(Switch);
        hp2->setObjectName(QString::fromUtf8("hp2"));
        hp2->setGeometry(QRect(340, 60, 131, 18));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        hp2->setPalette(palette2);
        hp2->setFont(font1);
        hp2->setScaledContents(true);
        name2 = new QLabel(Switch);
        name2->setObjectName(QString::fromUtf8("name2"));
        name2->setGeometry(QRect(338, 28, 141, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name2->setPalette(palette3);
        name2->setFont(font);
        model2 = new QLabel(Switch);
        model2->setObjectName(QString::fromUtf8("model2"));
        model2->setGeometry(QRect(280, 20, 51, 61));
        model2->setPixmap(QPixmap(QString::fromUtf8(":/sprites/pokemon/back/2.png")));
        model2->setScaledContents(true);
        decor_3 = new QLabel(Switch);
        decor_3->setObjectName(QString::fromUtf8("decor_3"));
        decor_3->setGeometry(QRect(20, 90, 51, 61));
        decor_3->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyBall.PNG")));
        decor_3->setScaledContents(false);
        hp3 = new QLabel(Switch);
        hp3->setObjectName(QString::fromUtf8("hp3"));
        hp3->setGeometry(QRect(100, 140, 131, 18));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        hp3->setPalette(palette4);
        hp3->setFont(font1);
        hp3->setScaledContents(true);
        name3 = new QLabel(Switch);
        name3->setObjectName(QString::fromUtf8("name3"));
        name3->setGeometry(QRect(98, 108, 141, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name3->setPalette(palette5);
        name3->setFont(font);
        model3 = new QLabel(Switch);
        model3->setObjectName(QString::fromUtf8("model3"));
        model3->setGeometry(QRect(40, 100, 51, 61));
        model3->setPixmap(QPixmap(QString::fromUtf8(":/sprites/pokemon/back/2.png")));
        model3->setScaledContents(true);
        decor_4 = new QLabel(Switch);
        decor_4->setObjectName(QString::fromUtf8("decor_4"));
        decor_4->setGeometry(QRect(262, 112, 51, 61));
        decor_4->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyBall.PNG")));
        decor_4->setScaledContents(false);
        hp4 = new QLabel(Switch);
        hp4->setObjectName(QString::fromUtf8("hp4"));
        hp4->setGeometry(QRect(342, 162, 131, 18));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        hp4->setPalette(palette6);
        hp4->setFont(font1);
        hp4->setScaledContents(true);
        model4 = new QLabel(Switch);
        model4->setObjectName(QString::fromUtf8("model4"));
        model4->setGeometry(QRect(282, 122, 51, 61));
        model4->setPixmap(QPixmap(QString::fromUtf8(":/sprites/pokemon/back/2.png")));
        model4->setScaledContents(true);
        name4 = new QLabel(Switch);
        name4->setObjectName(QString::fromUtf8("name4"));
        name4->setGeometry(QRect(340, 130, 141, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name4->setPalette(palette7);
        name4->setFont(font);
        decor_5 = new QLabel(Switch);
        decor_5->setObjectName(QString::fromUtf8("decor_5"));
        decor_5->setGeometry(QRect(22, 182, 51, 61));
        decor_5->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyBall.PNG")));
        decor_5->setScaledContents(false);
        model5 = new QLabel(Switch);
        model5->setObjectName(QString::fromUtf8("model5"));
        model5->setGeometry(QRect(42, 192, 51, 61));
        model5->setPixmap(QPixmap(QString::fromUtf8(":/sprites/pokemon/back/2.png")));
        model5->setScaledContents(true);
        hp5 = new QLabel(Switch);
        hp5->setObjectName(QString::fromUtf8("hp5"));
        hp5->setGeometry(QRect(102, 232, 131, 18));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        hp5->setPalette(palette8);
        hp5->setFont(font1);
        hp5->setScaledContents(true);
        name5 = new QLabel(Switch);
        name5->setObjectName(QString::fromUtf8("name5"));
        name5->setGeometry(QRect(100, 200, 141, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name5->setPalette(palette9);
        name5->setFont(font);
        name6 = new QLabel(Switch);
        name6->setObjectName(QString::fromUtf8("name6"));
        name6->setGeometry(QRect(338, 218, 141, 31));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name6->setPalette(palette10);
        name6->setFont(font);
        decor_6 = new QLabel(Switch);
        decor_6->setObjectName(QString::fromUtf8("decor_6"));
        decor_6->setGeometry(QRect(260, 200, 51, 61));
        decor_6->setPixmap(QPixmap(QString::fromUtf8(":/img/switch/partyBall.PNG")));
        decor_6->setScaledContents(false);
        hp6 = new QLabel(Switch);
        hp6->setObjectName(QString::fromUtf8("hp6"));
        hp6->setGeometry(QRect(340, 250, 131, 18));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        hp6->setPalette(palette11);
        hp6->setFont(font1);
        hp6->setScaledContents(true);
        model6 = new QLabel(Switch);
        model6->setObjectName(QString::fromUtf8("model6"));
        model6->setGeometry(QRect(280, 210, 51, 61));
        model6->setPixmap(QPixmap(QString::fromUtf8(":/sprites/pokemon/back/2.png")));
        model6->setScaledContents(true);
        bg->raise();
        pokemon5->raise();
        pokemon2->raise();
        pokemon3->raise();
        pokemon6->raise();
        pokemon1->raise();
        pokemon4->raise();
        cancel->raise();
        name1->raise();
        decor->raise();
        model1->raise();
        hp1->raise();
        decor_2->raise();
        hp2->raise();
        name2->raise();
        model2->raise();
        decor_3->raise();
        hp3->raise();
        name3->raise();
        model3->raise();
        decor_4->raise();
        hp4->raise();
        model4->raise();
        name4->raise();
        decor_5->raise();
        model5->raise();
        hp5->raise();
        name5->raise();
        name6->raise();
        decor_6->raise();
        hp6->raise();
        model6->raise();
        button7->raise();
        button2->raise();
        button1->raise();
        button4->raise();
        button5->raise();
        button6->raise();
        button3->raise();

        retranslateUi(Switch);

        QMetaObject::connectSlotsByName(Switch);
    } // setupUi

    void retranslateUi(QWidget *Switch)
    {
        Switch->setWindowTitle(QCoreApplication::translate("Switch", "Form", nullptr));
        bg->setText(QString());
        pokemon3->setText(QString());
        pokemon2->setText(QString());
        pokemon1->setText(QString());
        pokemon4->setText(QString());
        pokemon5->setText(QString());
        cancel->setText(QString());
        button1->setText(QString());
        button2->setText(QString());
        button3->setText(QString());
        button4->setText(QString());
        button5->setText(QString());
        button6->setText(QString());
        pokemon6->setText(QString());
        button7->setText(QString());
        decor->setText(QString());
        name1->setText(QCoreApplication::translate("Switch", "TextLabel", nullptr));
        model1->setText(QString());
        hp1->setText(QCoreApplication::translate("Switch", "HP/10", nullptr));
        decor_2->setText(QString());
        hp2->setText(QString());
        name2->setText(QCoreApplication::translate("Switch", "TextLabel", nullptr));
        model2->setText(QString());
        decor_3->setText(QString());
        hp3->setText(QString());
        name3->setText(QCoreApplication::translate("Switch", "TextLabel", nullptr));
        model3->setText(QString());
        decor_4->setText(QString());
        hp4->setText(QString());
        model4->setText(QString());
        name4->setText(QCoreApplication::translate("Switch", "TextLabel", nullptr));
        decor_5->setText(QString());
        model5->setText(QString());
        hp5->setText(QString());
        name5->setText(QCoreApplication::translate("Switch", "TextLabel", nullptr));
        name6->setText(QCoreApplication::translate("Switch", "TextLabel", nullptr));
        decor_6->setText(QString());
        hp6->setText(QString());
        model6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Switch: public Ui_Switch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCH_H
