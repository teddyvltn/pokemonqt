#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "ui_widget.h"

//----------------------
//      ui menu
//----------------------
#include "menu/mainmenu.h"
#include "menu/battle.h"

#define MAIN_MENU 0
#define BATTLE 1

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void moveToBattle();

private:
    Ui::Widget *ui;

    MainMenu* _mainMenu;
    Battle* _battle;

};
#endif // WIDGET_H
