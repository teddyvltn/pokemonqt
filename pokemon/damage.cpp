#include "damage.h"

#include <QRandomGenerator>

bool Damage::getIsCritical() const
{
    return isCritical;
}

int Damage::getItsMultiplier() const
{
    return itsMultiplier;
}

Damage::Damage(Pokemon* attacker, Move* move, Pokemon* victim)
{
    itsVictim = victim;
    itsAttacker = attacker;

    itsVictimType = stringToType(victim->getItsType());
    itsAttackerType = stringToType(attacker->getItsType());

    int generatedNumber = QRandomGenerator::global()->bounded(100);

    isCritical = (generatedNumber < ODD_CRITICAL);

    itsMove = move;
    itsDamage = move->getItsDamage();
    itsMultiplier = 1; // type truc

}


void Damage::computeDamage()
{
    float ratioAttackDefense = (float)itsAttacker->getItsAttack() / (float)itsVictim->getItsDefense();
    float typeMultiplicator = getTypeEfficiency(stringToType(itsMove->getItsType()), itsVictimType);

    std::cout << "Base damage of " << itsMove->getItsName() << " : " << itsDamage;

    itsDamage = ratioAttackDefense * itsDamage * typeMultiplicator / 3;
    if (isCritical) {
        itsDamage *= 2; std::cout << " (CRITICAL!!) ";
    }

    std::cout << ", Attacker Attack / Defender Defense = " << ratioAttackDefense
              << ", Type multiplicator = " << typeMultiplicator
              << ", New damage = " << itsDamage*10 << "/10" << std::endl;

    itsMultiplier = typeMultiplicator;

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

string Damage::descDamage()
{
    string text = "";

    if (isCritical) {
        text += "Coup critique! ";
    }

    if (itsMultiplier == 0.5)
        text += "Ce n'est pas très efficace...";
    else if (itsMultiplier == 2)
        text += "C'est super efficace!!";

    return text;
}




