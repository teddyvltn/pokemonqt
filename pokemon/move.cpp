#include "move.h"

auto movesList = extract_fileData("move.txt");

int Move::getItsDamage() const
{
    return itsDamage;
}

const string &Move::getItsName() const
{
    return itsName;
}


const string &Move::getItsType() const
{
    return itsType;
}

Move::Move(int identifier)
{
    auto m = movesList[identifier - 1];

    itsName = m["name"];
    itsIdentifier = identifier - 1;

    itsDamage = stoi(m["power"]);

    itsType = m["type"];

    itsPPMax = stoi(m["pp"]);
    itsPP = itsPPMax;
}
