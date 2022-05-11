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

Move::Move(int identifier)
{
    auto m = movesList[identifier - 1];

    itsName = m["name"];
    itsIdentifier = identifier - 1;

    itsDamage = stoi(m["power"]);

    itsPPMax = stoi(m["pp"]);
    itsPP = itsPPMax;
}
