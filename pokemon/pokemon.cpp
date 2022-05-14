#include "pokemon.h"

#include "globals.h"

#include "player.h"
#include "utils.h"

auto pokemons = extract_fileData("pokemon.txt");
int NBR_POKEMON = pokemons.size();

const std::string &Pokemon::getItsBackModel() const
{
    return itsBackModel;
}

const string &Pokemon::getItsType() const
{
    return itsType;
}

Pokemon::Pokemon(int id, Player* trainer)
{
    auto p = pokemons[id-1];

    this->itsIdentifier = stoi(p["id"]);
    this->itsName = p["name"];

    this->itsTrainer = trainer;

    this->itsType = p["type"];

    this->itsModel = "sprites/pokemon/" + p["id"] + ".png";
    this->itsBackModel = "sprites/pokemon/back/" + p["id"] + ".png";

    this->itsMaxHP = stoi(p["hp"]);
    this->itsCurrentHP = this->itsMaxHP;

    this->itsAttack = stoi(p["attack"]);
    this->itsDefense = stoi(p["defense"]);
    this->itsSpeed = stoi(p["speed"]);

    this->itsDescription = "";

    for (unsigned int i = 1; i < 5; i++) {

        int move = stoi(p["move" + to_string(i)]);
        if (move != 0)
            this->itsMoves.push_back(new Move(move));
    }

}

bool Pokemon::isAlive()
{
    return (itsCurrentHP != 0);
}

Player *Pokemon::getItsTrainer() const
{
    return itsTrainer;
}

const vector<Move *> &Pokemon::getItsMoves() const
{
    return itsMoves;
}


const std::string &Pokemon::getItsName() const
{
    return itsName;
}

int Pokemon::getItsLevel() const
{
    return itsLevel;
}

void Pokemon::setItsLevel(int newItsLevel)
{
    itsLevel = newItsLevel;
}

int Pokemon::getItsMaxHP() const
{
    return itsMaxHP;
}

void Pokemon::setItsMaxHP(int newItsMaxHP)
{
    itsMaxHP = newItsMaxHP;
}

int Pokemon::getItsCurrentHP() const
{
    return itsCurrentHP;
}

void Pokemon::setItsCurrentHP(int newItsCurrentHP)
{
    itsCurrentHP = newItsCurrentHP;
}

int Pokemon::getItsAttack() const
{
    return itsAttack;
}

int Pokemon::getItsDefense() const
{
    return itsDefense;
}

int Pokemon::getItsSpeed() const
{
    return itsSpeed;
}

const std::string &Pokemon::getItsModel() const
{
    return itsModel;
}

int Pokemon::getItsIdentifier() const
{
    return itsIdentifier;
}
