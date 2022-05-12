#include "switch.h"
#include "ui_switch.h"

#include "game.h"
#include "globals.h"

#include "widget.h"

#include <iostream>

using namespace std;

std::vector<QPushButton*> pokemonLabel = {};
std::vector<QLabel*> pokemonBox = {};

bool forcedSwitch;

Switch::Switch(QWidget* parent) : QWidget(parent), ui(new Ui::Switch)
{
    std::cout << "Setting up Ui: Switch" << std::endl;
    ui->setupUi(this);

    pokemonLabel = {ui->button2, ui->button3, ui->button4, ui->button5, ui->button6};
    pokemonBox = {ui->pokemon1, ui->pokemon2, ui->pokemon3, ui->pokemon4, ui->pokemon5};
}

Switch::~Switch()
{
    delete ui;
}

void Switch::activateMenu(bool activateCancel)
{
    std::cout << "Moving to Ui: Switch" << std::endl;

    forcedSwitch = !activateCancel;

    if (not activateCancel) {
        ui->button1->hide();
        ui->cancel->hide();
    }
    else {
        ui->button1->show();
        ui->cancel->show();
    }

    auto pokemons = game->getFirstPlayer()->getItsPokemons();

    for (unsigned int i = 0; i < pokemons.size(); i++) {
        if (pokemons[i] == game->getFirstPlayer()->getItsActivePokemon())
            pokemonBox[i]->move(pokemonBox[i]->pos() + QPoint(10, 0));

        pokemonLabel[i]->setText(QString::fromStdString(pokemons[i]->getItsName()));

    }

}

void Switch::doSwitch(int index)
{
    std::cout << "Switching" << std::endl;

    Player* you = game->getFirstPlayer();

    if ( not you->getItsPokemons()[index]->isAlive() ) return;

    you->switchPokemonIndex(index);
    emit switchIndex(1);
    emit refresh(forcedSwitch);
}

void Switch::on_button1_clicked()
{
    std::cout << "Moving to Ui: Battle" << std::endl;
    emit switchIndex(1);
}

void Switch::on_button3_clicked()
{
    doSwitch(0);
}

void Switch::on_button2_clicked()
{
    doSwitch(1);
}


void Switch::on_button4_clicked()
{
    doSwitch(2);
}


void Switch::on_button5_clicked()
{
    doSwitch(3);
}


void Switch::on_button6_clicked()
{
    doSwitch(4);
}

