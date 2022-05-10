#include "widget.h"

//----------------------
//   Useful functions
//----------------------
#include "utils.h"
#include "player.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    setFixedSize(WIDTH, HEIGHT);

    ui->setupUi(this);

    _mainMenu = new MainMenu;
    _battle = new Battle;

    ui->stackedWidget->addWidget(_mainMenu);
    ui->stackedWidget->addWidget(_battle);

    ui->stackedWidget->setCurrentIndex(MAIN_MENU);

    aPlayer = new Player("Teddy");
    anotherPlayer = new Player(1);

    cout << aPlayer->getItsName() << " | " << anotherPlayer->getItsName() << endl;

    aPlayer->generatePokemons();
    anotherPlayer->generatePokemons();

    //mainMenu -> battle
    connect(_mainMenu, SIGNAL(moveToBattle()), this, SLOT(moveToBattle()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::moveToBattle()
{
    ui->stackedWidget->setCurrentIndex(BATTLE);
    _battle->setupBattle(aPlayer, anotherPlayer);
}
