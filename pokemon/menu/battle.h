#ifndef BATTLE_H
#define BATTLE_H

#include <QWidget>
#include <QLabel>
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Battle; }
QT_END_NAMESPACE

class Battle : public QWidget
{
    Q_OBJECT

public:
    explicit Battle(QWidget* parent=0);
    ~Battle();
    void setupBattle(Player* aPlayer, Player* anotherPlayer);
    void setButtonAction(int identifier);
    void refreshBallDisplay();

    void resizeHealthBar(QLabel* healthBar, Pokemon* aPokemon);
    void setMessage(QString aText);

    void hideMessage();

    void switchPokemon(Player* aPlayer);
    void attackTurn();

    void doAttack(Player* firstToAttack, Player* secondToAttack, bool firstTurn=true);

    void endBattle(Player* winner, Player* looser);

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void refresh(bool forcedSwitch=false);

signals:
    void battleEnded(Player* winner, Player* losser);
    void switchMenu(bool activateCancel=true);

private:
    Ui::Battle* ui;

    Player* you;
    Player* opponent;
};


#endif // BATTLE_H
