#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <QString>

#include "move.h"

class Pokemon
{
    std::string itsName;
    int itsIdentifier;

    int itsLevel;

    int itsMaxHP;
    int itsCurrentHP;

    int itsAttack;
    int itsDefense;
    int itsSpeed;

    std::string itsDescription;

    std::string itsModel;

    vector<Move*> itsMoves;

public:
    Pokemon(int id);



    int getItsIdentifier() const;
    void setItsIdentifier(int newItsIdentifier);
    const std::string &getItsName() const;
    int getItsLevel() const;
    void setItsLevel(int newItsLevel);
    int getItsMaxHP() const;
    void setItsMaxHP(int newItsMaxHP);
    int getItsCurrentHP() const;
    void setItsCurrentHP(int newItsCurrentHP);
    int getItsAttack() const;
    int getItsDefense() const;
    int getItsSpeed() const;
    const std::string &getItsModel() const;
    const vector<Move *> &getItsMoves() const;
};

#endif // POKEMON_H
