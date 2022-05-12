#ifndef SWITCH_H
#define SWITCH_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Switch; }
QT_END_NAMESPACE

class Switch : public QWidget
{
    Q_OBJECT

public:
    explicit Switch(QWidget* parent=0);
    ~Switch();

    void activateMenu(bool activateCancel=true);
    void doSwitch(int index);

private slots:

    void on_button1_clicked();

    void on_button3_clicked();

    void on_button2_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

signals:
    void switchIndex(int index);

    void refresh(bool forcedSwitch=false);

private:
    Ui::Switch* ui;
};
#endif // SWITCH_H
