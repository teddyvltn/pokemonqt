#ifndef TYPE_H
#define TYPE_H

#include "utils.h"

enum Type {
    FIRE,
    WATER,
    GRASS,
    ELECTRIC
};

extern map<string, Type> stringType;
extern map<Type, map<Type, float>> typeEfficiency;

void populateStringType();
Type stringToType(string aType);

void populateTypeEfficiency();
float getTypeEfficiency(Type aType, Type otherType);

#endif // TYPE_H
