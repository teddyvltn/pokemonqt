#include "player.h"
#include "utils.h"

#include "game.h"
#include "globals.h"

auto trainer = extract_fileData("trainer.txt");

const std::string &Player::getItsName() const
{
    return itsName;
}

Pokemon* Player::getItsActivePokemon() const
{
    return *itsActivePokemon;
}

const std::vector<Pokemon *> &Player::getItsPokemons() const
{
    return itsPokemons;
}

Player::Player(int identifier)
{
    auto t = trainer[identifier-1];

    itsIdentifier = identifier;
    isAi = true;

    itsName = t["name"];
}

Player::Player(std::string name)
{
    itsIdentifier = 0;
    isAi = false;

    itsName = name;
}

void Player::generatePokemons()
{
    for (int i = 1; i < 6; i++) {
        if (isAi) {
            int identifier = itsIdentifier;
            auto t = trainer[identifier-1];
            int pokemonIdentifier = stoi(t[to_string(i)]);

            if (pokemonIdentifier != 0)
                itsPokemons.push_back(new Pokemon(pokemonIdentifier, this));
        }
        else
            itsPokemons.push_back(new Pokemon(2, this));
    }

    itsActivePokemon = itsPokemons.begin();
}

void Player::switchPokemon()
{
    if (not (computePokemonAlive() == 0))
        itsActivePokemon++;
    else
        game->loss(this);
}

void Player::switchPokemonIndex(int index)
{
    itsActivePokemon = itsPokemons.begin() + index;
}

int Player::computePokemonAlive()
{
    int nbrAlive = 0;

    for (Pokemon* pokemon : itsPokemons) {
        if (pokemon->isAlive())
            nbrAlive++;
    }

    return nbrAlive;
}


