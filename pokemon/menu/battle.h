#ifndef BATTLE_H
#define BATTLE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Battle; }
QT_END_NAMESPACE

class Battle : public QWidget
{
    Q_OBJECT

public:
    explicit Battle(QWidget* parent=0);
    ~Battle();

private:
    Ui::Battle* ui;
};


#endif // BATTLE_H
