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
    firstPlayer = new Player("Teddy");
    firstPlayer->generatePokemons();

    populateStringType();
    populateTypeEfficiency();
}

void Game::loss(Player *playerWhoLost)
{
    std::cout << playerWhoLost->getItsName() << " lost the battle!" << std::endl;

}

void Game::startBattle(Battle* _battle, int trainer)
{
    Player* secondPlayer = new Player(trainer);
    secondPlayer->generatePokemons();

    _battle->setupBattle(firstPlayer, secondPlayer);
}
