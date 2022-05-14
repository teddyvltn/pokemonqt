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

    void switchPokemonIndex(int index);

    int computePokemonAlive();

    void addRandomPokemon();
    void removeDeadPokemon();

    const std::string &getItsName() const;

    Pokemon* getItsActivePokemon() const;
    const std::vector<Pokemon *> &getItsPokemons() const;
};

#endif // PLAYER_H
