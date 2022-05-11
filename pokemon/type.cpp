#include "type.h"

map<string, Type> stringType;
map<Type, map<Type, float>> typeEfficiency;

void populateStringType()
{
    std::cout << "Populate: stringType!" << std::endl;

    stringType["fire"] = FIRE;
    stringType["water"] = WATER;
    stringType["grass"] = GRASS;
    stringType["eletric"] = ELECTRIC;
}

Type stringToType(string aType)
{
    return stringType[aType];
}


void populateTypeEfficiency()
{
    std::cout << "Populate: stringType!" << std::endl;
    auto type = extract_fileData("type.txt");

    print_data(type);

    for (unsigned int i = 0; i != type.size(); i++) {
        auto data = type[i];

        string curtype = data["curtype"];

        map<Type, float> tmpSecondMap;

        for (auto it = data.begin(); it != data.end(); it++) {

            //std::cout << it->first << " " << it->second << std::endl;

            if (it->first != "curtype") {

                tmpSecondMap.insert({stringToType(it->first), stof(it->second)});
            }


        }

        typeEfficiency.insert({stringToType(curtype), tmpSecondMap});
    }

}

float getTypeEfficiency(Type aType, Type otherType)
{
    return typeEfficiency[aType][otherType];
}
