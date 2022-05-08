#ifndef BATTLE_H
#define BATTLE_H

#include "window.h"
#include "ui_battle.h"

class Battle : public Window
{
    Ui::Battle *ui;

public:
    Battle(Window* parent=nullptr);
};

#endif // BATTLE_H
