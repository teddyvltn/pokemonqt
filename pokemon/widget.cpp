#include "widget.h"
#include "ui_widget.h"

#include "utils.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto pokemons = extract_fileData("pokemon.txt");
    auto type = extract_fileData("type.txt");
    print_data(pokemons);
}

Widget::~Widget()
{
    delete ui;
}

