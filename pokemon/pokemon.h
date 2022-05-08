#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <QString>

class Pokemon
{
    std::string itsName;
    int itsIdentifier;

    int itsLevel;

    int itsMaxHP;
    int itsCurrentHP;

    QString itsModel;

    //vector<Moves*> itsMoves;

public:
    Pokemon();
};

#endif // POKEMON_H
