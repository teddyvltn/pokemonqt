#include "battle.h"
#include "ui_battle.h"

#include <iostream>
#include <QFile>

#define HEALTHBAR_WIDTH 81

#define ACTION_MAIN 0
#define ACTION_ATTACK 1

int CURRENT_ACTION;

Battle::Battle(QWidget* parent) : QWidget(parent), ui(new Ui::Battle)
{
    std::cout << "Setting up Ui: Battle" << std::endl;
    ui->setupUi(this);
}

Battle::~Battle()
{
    delete ui;
}

void buttonSetText(std::string aString, QPushButton* aButton) {
    aButton->setText(QString::fromStdString(aString));
    if (not aButton->isVisible())
        aButton->show();
}

void Battle::setButtonAction(int identifier)
{
    if (identifier == ACTION_MAIN) {
        CURRENT_ACTION = identifier;

        buttonSetText("Attack", ui->button1);
        buttonSetText("Bag", ui->button2);
        buttonSetText("Switch", ui->button3);
        ui->button4->hide();
    }
    else {
        CURRENT_ACTION = ACTION_ATTACK;

        // getmoves etc
        buttonSetText("Coup de boule", ui->button1);
        ui->button2->hide();
        ui->button3->hide();
    }
}

void Battle::setupBattle(Player *aPlayer, Player *anotherPlayer)
{
    std::cout << "Setting up battle between players..." << std::endl;

    const Pokemon* myPokemon = aPlayer->getItsActivePokemon();
    const Pokemon* otherPokemon = anotherPlayer->getItsActivePokemon();

    CURRENT_ACTION = 0;

    QString pathMyModel = QString::fromStdString(":/" + myPokemon->getItsModel());
    ui->myPokemon->setPixmap(pathMyModel);

    QString pathOtherModel = QString::fromStdString(":/" + otherPokemon->getItsModel());
    ui->otherPokemon->setPixmap(pathOtherModel);

    ui->myName->setText(QString::fromStdString(myPokemon->getItsName()));
    ui->otherName->setText(QString::fromStdString(otherPokemon->getItsName()));

    ui->myHealthBar->setFixedWidth(HEALTHBAR_WIDTH);
    ui->otherHealthBar->setFixedWidth(HEALTHBAR_WIDTH);

    setButtonAction(ACTION_MAIN);
}



void Battle::on_button1_clicked()
{
    if (CURRENT_ACTION == ACTION_MAIN)
        setButtonAction(ACTION_ATTACK);
    else {
        // attack
    }
}

