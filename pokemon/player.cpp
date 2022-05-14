#include "player.h"
#include "utils.h"

#include "game.h"
#include "globals.h"

#include <QRandomGenerator>

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
    if (isAi) {
        for (int i = 1; i < 7; i++) {
            int identifier = itsIdentifier;
            auto t = trainer[identifier-1];
            int pokemonIdentifier = stoi(t[to_string(i)]);

            if (pokemonIdentifier != 0)
                itsPokemons.push_back(new Pokemon(pokemonIdentifier, this));
        }
    }
    else {
        addRandomPokemon();
        addRandomPokemon();
        addRandomPokemon();
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

template <typename T>
void remove_at(std::vector<T>& v, typename std::vector<T>::size_type n)
{
    std::swap(v[n], v.back());
    v.pop_back();
}

void Player::addRandomPokemon()
{
    if (itsPokemons.size() == 6) {
        int randomDel = QRandomGenerator::global()->bounded(4);

        remove_at(itsPokemons, randomDel);
    }

    int randomPokemon = QRandomGenerator::global()->bounded(NBR_POKEMON-1)+1;
    itsPokemons.push_back(new Pokemon(randomPokemon, this));

    itsActivePokemon = itsPokemons.begin();
}

void Player::removeDeadPokemon()
{
    for (unsigned int i = 0; i < itsPokemons.size(); i++) {
        if ( not itsPokemons[i]->isAlive() )
            remove_at(itsPokemons, i);
    }
}


