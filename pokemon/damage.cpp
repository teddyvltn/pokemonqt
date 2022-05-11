#include "damage.h"

#include <QRandomGenerator>

Damage::Damage(Pokemon* attacker, Move* move, Pokemon* victim)
{
    itsVictim = victim;
    itsAttacker = attacker;

    int generatedNumber = QRandomGenerator::global()->generate();

    isCritical = (generatedNumber < ODD_CRITICAL);

    itsMove = move;
    itsDamage = move->getItsDamage();
    itsMultiplier = 1; // type truc

}

void Damage::computeDamage()
{
    itsDamage = itsDamage/20;
}

void Damage::attack()
{
    computeDamage();

    if (itsVictim->getItsCurrentHP() - itsDamage < 0)
        itsDamage = itsVictim->getItsCurrentHP();

    itsVictim->setItsCurrentHP(itsVictim->getItsCurrentHP() - itsDamage);

    std::cout << itsAttacker->getItsName() << " attack " << itsVictim->getItsName()
              << " with " << itsMove->getItsName() << " for " << itsDamage << std::endl;

    std::cout << "HP of " << itsVictim->getItsName() << " are " << itsVictim->getItsCurrentHP() << std::endl;
}



