#include "damage.h"

#include <QRandomGenerator>

Damage::Damage(Pokemon* attacker, Move* move, Pokemon* victim)
{
    itsVictim = victim;
    itsAttacker = attacker;

    itsVictimType = victim->getItsType();
    itsAttackerType = attacker->getItsType();

    int generatedNumber = QRandomGenerator::global()->bounded(100);

    isCritical = (generatedNumber < ODD_CRITICAL);

    itsMove = move;
    itsDamage = move->getItsDamage();
    itsMultiplier = 1; // type truc

}

void Damage::computeDamage()
{
    float ratioAttackDefense = (float)itsAttacker->getItsAttack() / (float)itsVictim->getItsDefense();
    float typeMultiplicator = getTypeEfficiency(itsAttackerType, itsVictimType);

    std::cout << "Base damage of " << itsMove->getItsName() << " : " << itsDamage;

    itsDamage = ratioAttackDefense * itsDamage * typeMultiplicator / 10;
    if (isCritical) {
        itsDamage *= 2; std::cout << "CRITICAL!! ";
    }


    std::cout << ", Attacker Attack / Defender Defense = " << ratioAttackDefense
              << ", Type multiplicator = " << typeMultiplicator
              << ", New damage = " << itsDamage*10 << "/10" << std::endl;

}

void Damage::attack()
{
    computeDamage();

    if (itsVictim->getItsCurrentHP() - itsDamage < 0)
        itsDamage = itsVictim->getItsCurrentHP();

    itsVictim->setItsCurrentHP(itsVictim->getItsCurrentHP() - itsDamage);

    std::cout << itsAttacker->getItsName() << " attack " << itsVictim->getItsName()
              << " with " << itsMove->getItsName() << " for " << itsDamage << std::endl;

    std::cout << "HP of " << itsVictim->getItsName() << " are " << itsVictim->getItsCurrentHP()
              << "/" << itsVictim->getItsMaxHP() << std::endl;
}



