#include "player.h"
#include "utils.h"

auto trainer = extract_fileData("trainer.txt");

const std::string &Player::getItsName() const
{
    return itsName;
}

const Pokemon* Player::getItsActivePokemon() const
{
    return *itsActivePokemon;
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
                itsPokemons.push_back(new Pokemon(pokemonIdentifier));
        }
        else
            itsPokemons.push_back(new Pokemon(2));
    }

    itsActivePokemon = itsPokemons.begin();
}


