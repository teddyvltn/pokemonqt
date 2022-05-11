#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "menu/battle.h"

class Game
{

private:
    Player* firstPlayer;
    //Player* secondPlayer;

public:
    Game();

    void loss(Player* playerWhoLost);
    void startBattle(Battle* _battle);

    Player *getFirstPlayer() const;
};

#endif // GAME_H
