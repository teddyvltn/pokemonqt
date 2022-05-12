#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <QString>

#include "type.h"
#include "move.h"
class Player;

class Pokemon
{
    std::string itsName;
    int itsIdentifier;

    Player* itsTrainer;

    int itsLevel;

    int itsMaxHP;
    int itsCurrentHP;

    int itsAttack;
    int itsDefense;
    int itsSpeed;

    string itsType;

    std::string itsDescription;

    std::string itsModel;
    std::string itsBackModel;

    vector<Move*> itsMoves;

public:
    Pokemon(int id, Player* trainer);

    bool isAlive();

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
    Player *getItsTrainer() const;
    const std::string &getItsBackModel() const;
    const string &getItsType() const;
};

#endif // POKEMON_H
