#include "widget.h"

//----------------------
//   Useful functions
//----------------------
#include "utils.h"

//----------------------
//      ui menu
//----------------------
#include "menu/battle.h"

Widget::Widget(QWidget *parent)
    : QStackedWidget(parent)
{
    auto pokemons = extract_fileData("pokemon.txt");
    auto type = extract_fileData("type.txt");
    print_data(pokemons);

    ui = new Ui::StackedWidget;
    ui->setupUi(this);

    Battle* battle = new Battle;
    this->addWidget(battle);
}

Widget::~Widget()
{
    delete ui;
}

