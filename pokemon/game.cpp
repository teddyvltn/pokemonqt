#include "game.h"

#include "globals.h"
#include "widget.h"

Game::Game()
{
    firstPlayer = new Player("Francis");
}

void Game::loss(Player *playerWhoLost)
{
    std::cout << playerWhoLost->getItsName() << " lost the battle!" << std::endl;

    widget->backToHome();
}

void Game::startBattle(Battle* _battle)
{
    firstPlayer->generatePokemons();
    Player* secondPlayer = new Player(1);
    secondPlayer->generatePokemons();

    _battle->setupBattle(firstPlayer, secondPlayer);
}
