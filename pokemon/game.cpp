#include "game.h"

#include "globals.h"
#include "type.h"
#include "widget.h"

Player *Game::getFirstPlayer() const
{
    return firstPlayer;
}

Game::Game()
{

}

void Game::initialize()
{
    firstPlayer = new Player("Francis");
    firstPlayer->generatePokemons();

    populateStringType();
    populateTypeEfficiency();
}

void Game::loss(Player *playerWhoLost)
{
    std::cout << playerWhoLost->getItsName() << " lost the battle!" << std::endl;

}

void Game::startBattle(Battle* _battle)
{

    Player* secondPlayer = new Player(1);
    secondPlayer->generatePokemons();

    _battle->setupBattle(firstPlayer, secondPlayer);
}
