#include "widget.h"

//----------------------
//   Useful functions
//----------------------
#include "utils.h"
#include "player.h"

#include "game.h"
#include "globals.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    setFixedSize(WIDTH, HEIGHT);

    ui->setupUi(this);

    _mainMenu = new MainMenu;
    _battle = new Battle;

    game = new Game();
    widget = this;

    ui->stackedWidget->insertWidget(MAIN_MENU, _mainMenu);
    ui->stackedWidget->insertWidget(BATTLE, _battle);

    ui->stackedWidget->setCurrentIndex(MAIN_MENU);

    //mainMenu -> battle
    connect(_mainMenu, SIGNAL(moveToBattle()), this, SLOT(moveToBattle()));
    connect(_battle, SIGNAL(battleEnded()), this, SLOT(battleEnded()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::backToHome()
{
    delay(560);
    //ui->stackedWidget->removeWidget(_battle);
}

void Widget::moveToBattle()
{
    ui->stackedWidget->setCurrentIndex(BATTLE);
    game->startBattle(_battle);
}

void Widget::battleEnded()
{
    std::cout << "a" << std::endl;
    ui->stackedWidget->setCurrentIndex(MAIN_MENU);
}
