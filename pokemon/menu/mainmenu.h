#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget* parent=0);
    ~MainMenu();

private slots:
    void on_pushButton_2_clicked();

    void battleReward();
    void battleNoReward();

signals:
    void moveToBattle();

private:
    Ui::MainMenu* ui;
};

#endif // MAINMENU_H
