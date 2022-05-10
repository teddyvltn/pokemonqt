#ifndef DAMAGE_H
#define DAMAGE_H

#include "pokemon.h"

class Damage
{
    Pokemon* itsVictim;
    Pokemon* itsAttacker;

    //moves

    int itsDamage;
    int itsMultiplier;

    bool isCritical;

public:
    Damage();
};

#endif // DAMAGE_H
