#include "battle.h"
#include "ui_battle.h"

#include "damage.h"

#include "game.h"
#include "globals.h"
#include "widget.h"

#include <iostream>
#include <QFile>
#include <QPropertyAnimation>
#include <QRandomGenerator>

#define HEALTHBAR_WIDTH 94

#define ACTION_MAIN 0
#define ACTION_ATTACK 1

int CURRENT_ACTION;
int CURRENT_ATTACK;

map<Player*, QLabel*> Sprites = {};
map<Player*, QLabel*> HealthBar = {};
map<Player*, QLabel*> Name = {};

vector<QLabel*> myBall = {};
vector<QLabel*> otherBall = {};

vector<QPushButton*> attackButton = {};

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

void makeBlink(QLabel * aSprite) {
    for (int i = 0; i < 3; i++) {
        aSprite->setVisible(false);
        delay(100);
        aSprite->setVisible(true);
        delay(100);
    }

}

void Battle::setMessage(QString aText) {
    ui->boxMessage->setVisible(true);
    ui->boxText->setVisible(true);

    ui->boxText->setText(aText);

}

void Battle::hideMessage()
{
    ui->boxMessage->setVisible(false);
    ui->boxText->setVisible(false);
}

void Battle::setButtonAction(int identifier)
{
    if (identifier == ACTION_MAIN) {
        CURRENT_ACTION = identifier;

        buttonSetText("Attack", ui->button1);
        buttonSetText("Pokemon", ui->button2);
        ui->button3->hide();
        ui->button4->hide();
    }
    else {
        CURRENT_ACTION = ACTION_ATTACK;

        auto youPokemonMoves = you->getItsActivePokemon()->getItsMoves();

        for (unsigned int i = 0; i != attackButton.size(); i++) {
            if (i < youPokemonMoves.size())
                buttonSetText(youPokemonMoves[i]->getItsName(), attackButton[i]);
            else
                attackButton[i]->hide();
        }
    }
}

void Battle::refreshBallDisplay()
{
    auto youPokemons = you->getItsPokemons();

    for (unsigned int i = 0; i != youPokemons.size(); i++) {
        if (youPokemons[i]->isAlive())
            myBall[i]->setPixmap(QString::fromStdString(":/ui/img/ballnormal.png"));
        else
            myBall[i]->setPixmap(QString::fromStdString(":/ui/img/ballstatus.PNG"));
    }

    auto opponentPokemons = opponent->getItsPokemons();

    for (unsigned int i = 0; i != opponentPokemons.size(); i++) {
        if (opponentPokemons[i]->isAlive())
            otherBall[i]->setPixmap(QString::fromStdString(":/ui/img/ballnormal.png"));
        else
            otherBall[i]->setPixmap(QString::fromStdString(":/ui/img/ballstatus.PNG"));
    }
}

void Battle::resizeHealthBar(QLabel *healthBar, Pokemon* aPokemon)
{
    healthBar->setFixedWidth(((float)aPokemon->getItsCurrentHP() / (float)aPokemon->getItsMaxHP()) * HEALTHBAR_WIDTH);
}

void Battle::setupBattle(Player *aPlayer, Player *anotherPlayer)
{
    std::cout << "Setting up battle between players..." << std::endl;

    you = aPlayer;
    opponent = anotherPlayer;

    Pokemon* myPokemon = you->getItsActivePokemon();
    Pokemon* otherPokemon = opponent->getItsActivePokemon();

    CURRENT_ACTION = 0;

    ui->otherPokemon->setVisible(true);
    ui->myPokemon->setVisible(true);

    QString pathMyModel = QString::fromStdString(":/" + myPokemon->getItsBackModel());
    ui->myPokemon->setPixmap(pathMyModel);

    QString pathOtherModel = QString::fromStdString(":/" + otherPokemon->getItsModel());
    ui->otherPokemon->setPixmap(pathOtherModel);

    ui->myName->setText(QString::fromStdString(myPokemon->getItsName()));
    ui->otherName->setText(QString::fromStdString(otherPokemon->getItsName()));

    resizeHealthBar(ui->myHealthBar, myPokemon);
    ui->otherHealthBar->setFixedWidth(HEALTHBAR_WIDTH);

    setButtonAction(ACTION_MAIN);

    ui->boxMessage->setVisible(false);
    ui->boxText->setVisible(false);

    Sprites.insert({you, ui->myPokemon});
    Sprites.insert({opponent, ui->otherPokemon});

    HealthBar.insert({you, ui->myHealthBar});
    HealthBar.insert({opponent, ui->otherHealthBar});

    Name.insert({you, ui->myName});
    Name.insert({opponent, ui->otherName});

    myBall = {ui->myBall1, ui->myBall2, ui->myBall3, ui->myBall4, ui->myBall5, ui->myBall6};
    otherBall = {ui->otherBall1, ui->otherBall2, ui->otherBall3, ui->otherBall4, ui->otherBall5, ui->otherBall6};

    refreshBallDisplay();

    attackButton = {ui->button1, ui->button2, ui->button3, ui->button4};
}

void Battle::attackTurn()
{
    ui->boxMessage->setVisible(true);
    ui->boxText->setVisible(true);

    Pokemon* myPokemon = you->getItsActivePokemon();
    Pokemon* otherPokemon = opponent->getItsActivePokemon();

    if (myPokemon->getItsSpeed() >= otherPokemon->getItsSpeed()) {
        doAttack(you, opponent);
    }
    else {
        doAttack(opponent, you);
    }

    setButtonAction(ACTION_MAIN);

}

void Battle::endBattle(Player *winner, Player *looser)
{
    QLabel* victimSprite = Sprites[looser];

    victimSprite->setVisible(false);

    QString winnerMessage = QString::fromStdString(winner->getItsName() + " has won the battle!");

    setMessage(winnerMessage);

    delay(2000);

    emit battleEnded(winner, looser);
}


void Battle::doAttack(Player *firstToAttack, Player *secondToAttack, bool firstTurn)
{
    QLabel* victimSprite = Sprites[secondToAttack];
    QLabel* victimHealthBar = HealthBar[secondToAttack];

    Pokemon* attacker = firstToAttack->getItsActivePokemon();
    Pokemon* victim = secondToAttack->getItsActivePokemon();

    if ( not (game->getFirstPlayer() == firstToAttack))
        CURRENT_ATTACK = QRandomGenerator::global()->bounded(attacker->getItsMoves().size());

    Move* move = attacker->getItsMoves()[CURRENT_ATTACK];

    Damage* dmg = new Damage(attacker,
                             move,
                             victim);

    QString attackMessage = QString::fromStdString(attacker->getItsName() + " attack " +
                                                   victim->getItsName() + " with " + move->getItsName() + "!");
    setMessage(attackMessage);
    dmg->attack();

    makeBlink(victimSprite);
    resizeHealthBar(victimHealthBar, victim);

    delay(500);

    QString descMessage = QString::fromStdString(dmg->descDamage());

    if (descMessage != "") {
        setMessage(descMessage);
        delay(1000);
    }

    if (victim->isAlive() and firstTurn) {
        doAttack(secondToAttack, firstToAttack, false);
    }
    else if ( not victim->isAlive() ) {

        QString deathMessage = QString::fromStdString(victim->getItsName() + " his KO!");

        setMessage(deathMessage);
        victimSprite->setVisible(false);

        refreshBallDisplay();

        delay(1000);

        if (secondToAttack->computePokemonAlive() > 0) {

            if (secondToAttack == game->getFirstPlayer()) {
                emit switchMenu(false);
                victimSprite->setPixmap(QString::fromStdString(":/" + secondToAttack->getItsActivePokemon()->getItsBackModel()));
            }
            else {
                secondToAttack->switchPokemon();
                victimSprite->setPixmap(QString::fromStdString(":/" + secondToAttack->getItsActivePokemon()->getItsModel()));
                Name[secondToAttack]->setText(QString::fromStdString(secondToAttack->getItsActivePokemon()->getItsName()));
            }

            resizeHealthBar(victimHealthBar, secondToAttack->getItsActivePokemon());

            QString switchMessage = QString::fromStdString(secondToAttack->getItsName() + "has sent "
                                                           + secondToAttack->getItsActivePokemon()->getItsName());

            setMessage(switchMessage);

            delay(1000);

            victimSprite->setVisible(true);

        }
        else {
            endBattle(firstToAttack, secondToAttack);
        }

    }

    hideMessage();

}



void Battle::on_button1_clicked()
{
    if (CURRENT_ACTION == ACTION_MAIN)
        setButtonAction(ACTION_ATTACK);
    else {
        CURRENT_ATTACK = 0;
        attackTurn();
    }

}

void Battle::on_button2_clicked()
{
    if (CURRENT_ACTION == ACTION_MAIN) {
        emit switchMenu();
    }
    else {
        CURRENT_ATTACK = 1;
        attackTurn();
    }

}

void Battle::on_button3_clicked()
{
    CURRENT_ATTACK = 2;
    attackTurn();
}

void Battle::on_button4_clicked()
{
    CURRENT_ATTACK = 3;
    attackTurn();
}

void Battle::refresh(bool forcedSwitch)
{
    std::cout << "Refreshing after switch" << std::endl;

    Pokemon* myPokemon = you->getItsActivePokemon();

    ui->myPokemon->setVisible(false);

    ui->myPokemon->setPixmap(QString::fromStdString(":/" + myPokemon->getItsBackModel()));

    string pokemonName = myPokemon->getItsName();
    for (auto & c: pokemonName) c = toupper(c);

    Name[you]->setText(QString::fromStdString(pokemonName));

    resizeHealthBar(ui->myHealthBar, myPokemon);

    QString switchMessage = QString::fromStdString(you->getItsName() + "has sent "
                                                 + myPokemon->getItsName());

    setMessage(switchMessage);

    delay(1000);

    ui->myPokemon->setVisible(true);

    delay(500);

    hideMessage();

    if (not forcedSwitch)
        doAttack(opponent, you, false);

}





