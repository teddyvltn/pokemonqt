#ifndef DAMAGE_H
#define DAMAGE_H

#include "pokemon.h"

#define ODD_CRITICAL 5

class Damage
{
    Pokemon* itsVictim;
    Pokemon* itsAttacker;

    Type itsVictimType;
    Type itsAttackerType;

    Move* itsMove;

    int itsDamage;
    int itsMultiplier;

    bool isCritical;

public:
    Damage(Pokemon* itsAttacler, Move* itsMove, Pokemon* itsVictim);

    void attack();

    void computeDamage();
    bool getIsCritical() const;
    int getItsMultiplier() const;

    string descDamage();
};

#endif // DAMAGE_H
