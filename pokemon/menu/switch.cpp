#include "switch.h"
#include "ui_switch.h"

#include "game.h"
#include "globals.h"

#include "widget.h"

#include <iostream>

using namespace std;

std::vector<QPushButton*> pokemonLabel = {};
std::vector<QLabel*> pokemonBox = {};
std::vector<QLabel*> pokemonName = {};
std::vector<QLabel*> pokemonSprite = {};
std::vector<QLabel*> pokemonHP = {};

bool forcedSwitch;

Switch::Switch(QWidget* parent) : QWidget(parent), ui(new Ui::Switch)
{
    std::cout << "Setting up Ui: Switch" << std::endl;
    ui->setupUi(this);

    pokemonLabel = {ui->button2, ui->button3, ui->button4, ui->button5, ui->button6, ui->button7};
    pokemonBox = {ui->pokemon1, ui->pokemon2, ui->pokemon3, ui->pokemon4, ui->pokemon5, ui->pokemon6};

    pokemonName = {ui->name1, ui->name2, ui->name3, ui->name4, ui->name5, ui->name6};
    pokemonSprite = {ui->model1, ui->model2, ui->model3, ui->model4, ui->model5, ui->model6};

    pokemonHP = {ui->hp1, ui->hp2, ui->hp3, ui->hp4, ui->hp5, ui->hp6};
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

    for (unsigned int i = 0; i < 6; i++) {

        QLabel* pBox = pokemonBox[i];
        QLabel* pName = pokemonName[i];
        QLabel* pSprite = pokemonSprite[i];
        QPushButton* button = pokemonLabel[i];
        QLabel* pHP = pokemonHP[i];

        Pokemon* p = pokemons[i];

        if (i < pokemons.size()) {
            pBox->setVisible(true);
            pName->setVisible(true);
            pSprite->setVisible(true);
            button->setVisible(true);
            pHP->setVisible(true);

            pBox->setPixmap(QString::fromStdString(":/img/switch/partyPanelRound.png"));
            pName->setText(QString::fromStdString(p->getItsName()));

            pSprite->setPixmap(QString::fromStdString(":/" + p->getItsModel()));

            string hpText = "HP: " + to_string(p->getItsCurrentHP()) + "/" + to_string(p->getItsMaxHP());

            pHP->setText(QString::fromStdString(hpText));

            if (p == game->getFirstPlayer()->getItsActivePokemon())
                pBox->setPixmap(QString::fromStdString(":/img/switch/partyPanelRoundSwap.png"));

            if (not p->isAlive())
                pBox->setPixmap(QString::fromStdString(":/img/switch/partyPanelRoundSelFnt.png"));
        }
        else {

            pName->setVisible(false);
            pSprite->setVisible(false);
            button->setVisible(false);
            pHP->setVisible(false);
        }

    }

}

void Switch::doSwitch(int index)
{
    std::cout << "Switching" << std::endl;

    Player* you = game->getFirstPlayer();

    if ( not you->getItsPokemons()[index]->isAlive() ) return;
    if ( you->getItsActivePokemon() == you->getItsPokemons()[index]) return;

    you->switchPokemonIndex(index);
    emit switchIndex(1);
    emit refresh(forcedSwitch);
}

void Switch::on_button1_clicked()
{
    std::cout << "Moving to Ui: Battle" << std::endl;
    emit switchIndex(1);
}

void Switch::on_button2_clicked()
{
    doSwitch(0);
}

void Switch::on_button3_clicked()
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


void Switch::on_button7_clicked()
{
    doSwitch(5);
}

