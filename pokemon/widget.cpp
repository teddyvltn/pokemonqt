#include "widget.h"

//----------------------
//   Useful functions
//----------------------
#include "utils.h"
#include "window.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    auto pokemons = extract_fileData("pokemon.txt");
    auto type = extract_fileData("type.txt");
    print_data(pokemons);

    ui->setupUi(this);


    _mainMenu = new MainMenu;
    _battle = new Battle;
    ui->stackedWidget->addWidget(_mainMenu);
    ui->stackedWidget->addWidget(_battle);

    ui->stackedWidget->setCurrentIndex(MAIN_MENU);

    connect(_mainMenu, SIGNAL(moveToBattle()), this, SLOT(moveToBattle()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::moveToBattle()
{
    ui->stackedWidget->setCurrentIndex(BATTLE);
}
