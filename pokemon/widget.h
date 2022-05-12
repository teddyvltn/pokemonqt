#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"

//----------------------
//      ui menu
//----------------------
#include "menu/mainmenu.h"
#include "menu/battle.h"
#include "menu/switch.h"

#define MAIN_MENU 0
#define BATTLE 1
#define SWITCH 2

#define WIDTH 512
#define HEIGHT 368

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void backToHome();

private slots:
    void moveToBattle();
    void battleEnded(Player* winner, Player* losser);
    void switchIndex(int i);
    void switchMenu(bool activateCancel=true);

private:
    Ui::Widget *ui;

    MainMenu* _mainMenu;
    Battle* _battle;
    Switch* _switch;

    Player* aPlayer;
    Player* anotherPlayer;

};
#endif // WIDGET_H
