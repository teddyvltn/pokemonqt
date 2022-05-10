#ifndef BATTLE_H
#define BATTLE_H

#include <QWidget>
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Battle; }
QT_END_NAMESPACE

class Battle : public QWidget
{
    Q_OBJECT

public:
    explicit Battle(QWidget* parent=0);
    ~Battle();
    void setupBattle(Player* aPlayer, Player* anotherPlayer);
    void setButtonAction(int identifier);

private slots:
    void on_button1_clicked();

private:
    Ui::Battle* ui;
};


#endif // BATTLE_H
