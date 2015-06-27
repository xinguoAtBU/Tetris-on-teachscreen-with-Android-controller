#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->resize(320,230);
}


Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    w.show();
    this->hide();
}

void Menu::on_pushButton_2_clicked()
{
    opt.show();
    //this->hide();
}
