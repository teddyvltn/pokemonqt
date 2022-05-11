#ifndef MOVE_H
#define MOVE_H

#include "utils.h"

class Move
{
    string itsName;

    int itsIdentifier;

    int itsDamage;
    int itsPPMax;
    int itsPP;

    //sound

public:
    Move(int itsIdentifier);
    int getItsDamage() const;
    const string &getItsName() const;
};

#endif // MOVE_H
