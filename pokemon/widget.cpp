#include "widget.h"

//----------------------
//   Useful functions
//----------------------
#include "utils.h"
#include "player.h"

#include "game.h"
#include "globals.h"

Game* game = new Game();

int nbrCombat = 1;

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    setFixedSize(WIDTH, HEIGHT);

    ui->setupUi(this);

    _mainMenu = new MainMenu;
    _battle = new Battle;
    _switch = new Switch;

    game->initialize();

    ui->stackedWidget->insertWidget(MAIN_MENU, _mainMenu);
    ui->stackedWidget->insertWidget(BATTLE, _battle);
    ui->stackedWidget->insertWidget(SWITCH, _switch);

    //mainMenu -> battle

    //save_data(game->getFirstPlayer());

    ui->stackedWidget->setCurrentIndex(MAIN_MENU);

    connect(_mainMenu, SIGNAL(moveToBattle()), this, SLOT(moveToBattle()));
    connect(_battle, SIGNAL(battleEnded(Player*,Player*)), this, SLOT(battleEnded(Player*, Player*)));
    connect(_battle, SIGNAL(switchMenu(bool)), this, SLOT(switchMenu(bool)));
    connect(_switch, SIGNAL(switchIndex(int)), this, SLOT(switchIndex(int)));

    connect(_switch, SIGNAL(refresh(bool)), _battle, SLOT(refresh(bool)));

    _mainMenu->refreshMain();
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

void Widget::switchIndex(int index) {
    ui->stackedWidget->setCurrentIndex(index);
}

void Widget::switchMenu(bool activateCancel)
{
    ui->stackedWidget->setCurrentIndex(SWITCH);
    _switch->activateMenu(activateCancel);
}

void Widget::moveToBattle()
{
    //_battle = new Battle();
    ui->stackedWidget->setCurrentIndex(BATTLE);
    game->startBattle(_battle, nbrCombat);
}

void Widget::battleEnded(Player* winner, Player* losser)
{
    std::cout << winner->getItsName() << std::endl;
    if (winner == game->getFirstPlayer()) {
        winner->addRandomPokemon();
        winner->removeDeadPokemon();

        nbrCombat++;
    }
    else {
        losser->removeDeadPokemon();

        losser->addRandomPokemon();
        losser->addRandomPokemon();

        losser->removeDeadPokemon();
    }
    delay(500);


    _mainMenu->refreshMain();
    ui->stackedWidget->setCurrentIndex(MAIN_MENU);
}
