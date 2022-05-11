#include "pokemon.h"
#include "utils.h"

auto pokemons = extract_fileData("pokemon.txt");

Pokemon::Pokemon(int id)
{
    auto p = pokemons[id-1];

    this->itsIdentifier = stoi(p["id"]);
    this->itsName = p["name"];

    //this->itsType = getTypeFromString(p["type"]);

    this->itsModel = "sprites/pokemon/back/" + p["id"] + ".png";

    this->itsMaxHP = stoi(p["hp"]);
    this->itsCurrentHP = this->itsMaxHP;

    this->itsAttack = stoi(p["attack"]);
    this->itsDefense = stoi(p["defense"]);
    this->itsSpeed = stoi(p["speed"]);

    this->itsDescription = "";

    this->itsMoves.push_back(new Move(1));
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
