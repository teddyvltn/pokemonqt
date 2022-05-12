#include "battle.h"
#include "ui_battle.h"

#include "damage.h"

#include <iostream>
#include <QFile>
#include <QPropertyAnimation>

#define HEALTHBAR_WIDTH 81

#define ACTION_MAIN 0
#define ACTION_ATTACK 1

int CURRENT_ACTION;
int CURRENT_ATTACK;

map<Player*, QLabel*> Sprites;
map<Player*, QLabel*> HealthBar;

vector<QLabel*> myBall;
vector<QLabel*> otherBall;

vector<QPushButton*> attackButton;

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
        buttonSetText("Bag", ui->button2);
        buttonSetText("Switch", ui->button3);
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

    QString pathMyModel = QString::fromStdString(":/" + myPokemon->getItsModel());
    ui->myPokemon->setPixmap(pathMyModel);

    QString pathOtherModel = QString::fromStdString(":/" + otherPokemon->getItsModel());
    ui->otherPokemon->setPixmap(pathOtherModel);

    ui->myName->setText(QString::fromStdString(myPokemon->getItsName()));
    ui->otherName->setText(QString::fromStdString(otherPokemon->getItsName()));

    ui->myHealthBar->setFixedWidth(HEALTHBAR_WIDTH);
    ui->otherHealthBar->setFixedWidth(HEALTHBAR_WIDTH);

    setButtonAction(ACTION_MAIN);

    ui->boxMessage->setVisible(false);
    ui->boxText->setVisible(false);

    Sprites.insert({you, ui->myPokemon});
    Sprites.insert({opponent, ui->otherPokemon});

    HealthBar.insert({you, ui->myHealthBar});
    HealthBar.insert({opponent, ui->otherHealthBar});

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
    QLabel* victimHealthBar = HealthBar[looser];

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

    QString attackMessage = QString::fromStdString(attacker->getItsName() + " attack " +
                                                   victim->getItsName() + " ! ");

    Move* move = attacker->getItsMoves()[CURRENT_ATTACK];
    Damage* dmg = new Damage(attacker,
                             move,
                             victim);

    setMessage(attackMessage);
    dmg->attack();

    makeBlink(victimSprite);
    resizeHealthBar(victimHealthBar, victim);

    delay(500);

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
            secondToAttack->switchPokemon();

            victimSprite->setPixmap(QString::fromStdString(":/" + victim->getItsModel()));
            victimHealthBar->setFixedWidth(HEALTHBAR_WIDTH);

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
        attackTurn();
        CURRENT_ATTACK = 0;
    }

}

void Battle::on_button2_clicked()
{
    if (CURRENT_ACTION == ACTION_MAIN) {}
        //BAG
        //setButtonAction(ACTION_ATTACK);
    else {
        attackTurn();
        CURRENT_ATTACK = 1;
    }

}


