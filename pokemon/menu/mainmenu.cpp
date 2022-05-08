#include "mainmenu.h"
#include "ui_mainmenu.h"

#include <iostream>

MainMenu::MainMenu(QWidget* parent) : QWidget(parent), ui(new Ui::MainMenu)
{
    std::cout << "Setting up Ui: MainMenu" << std::endl;
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_2_clicked()
{
    std::cout << "Moving to Ui: Battle" << std::endl;
    emit moveToBattle();
}

