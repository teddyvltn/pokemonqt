#include "battle.h"


Battle::Battle(Window* parent) : Window(parent), ui(new Ui::Battle)
{
    ui->setupUi(this);
}
