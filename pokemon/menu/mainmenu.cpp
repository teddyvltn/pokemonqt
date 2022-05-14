#include "mainmenu.h"
#include "ui_mainmenu.h"

#include "game.h"
#include "globals.h"

#include <iostream>

using namespace std;

MainMenu::MainMenu(QWidget* parent) : QWidget(parent), ui(new Ui::MainMenu)
{
    std::cout << "Setting up Ui: MainMenu" << std::endl;
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::refreshMain()
{
    auto pokemons = game->getFirstPlayer()->getItsPokemons();

    vector<QLabel*> pokemonSprite {ui->pk1, ui->pk2, ui->pk3, ui->pk4, ui->pk5, ui->pk6};

    for (unsigned int i = 0; i < 6; i++) {
        QLabel* sprite = pokemonSprite[i];

        Pokemon* p = pokemons[i];

        if (i < pokemons.size()) {
            sprite->show();
            sprite->setPixmap(QString::fromStdString(":/" + p->getItsModel()));
        }
        else {
            sprite->hide();
        }
    }
}

void MainMenu::on_pushButton_2_clicked()
{
    std::cout << "Moving to Ui: Battle" << std::endl;
    emit moveToBattle();
}

