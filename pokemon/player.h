#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "pokemon.h"

class Player
{
protected:
    int itsIdentifier;
    bool isAi;

    std::string itsName;

    QString itsModel;

    std::vector<Pokemon*>::iterator itsActivePokemon;

    std::vector<Pokemon*> itsPokemons;

public:
    Player(int identifier);
    Player(std::string itsName);

    void generatePokemons();
    void switchPokemon();

    int computePokemonAlive();

    const std::string &getItsName() const;

    Pokemon* getItsActivePokemon() const;
};

#endif // PLAYER_H
