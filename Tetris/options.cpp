#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);

    this->ui->lineEdit->setText(tr("1"));
}

Options::~Options()
{
    delete ui;
}

void Options::on_pushButton_clicked()
{
    this->hide();
}



void Options::on_horizontalSlider_valueChanged(int value)
{
      int pos = this->ui->horizontalSlider->value();
      QString str = QString("%1").arg(pos);
      this->ui->lineEdit->setText(str);
}

void Options::on_pushButton_2_clicked()
{/*
    if(this->ui->pushButton_2->isChecked())
    {
    this->gameArea->setDrawGrid(false);
    }
    else
    {
    this->gameArea->setDrawGrid(true);
    }
    this->gameArea->draw_gameArea();
    this->gameArea->setFocus();
    */
}


