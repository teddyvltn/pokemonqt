#ifndef MOVE_H
#define MOVE_H

#include "utils.h"
#include "type.h"

class Move
{
    string itsName;

    int itsIdentifier;

    int itsDamage;
    int itsPPMax;
    int itsPP;

    string itsType;
    //sound

public:
    Move(int itsIdentifier);
    int getItsDamage() const;
    const string &getItsName() const;

    const string &getItsType() const;
};

#endif // MOVE_H
