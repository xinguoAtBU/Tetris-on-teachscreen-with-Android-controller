#ifndef OPTIONS_H
#define OPTIONS_H
#include "gamearea.h"
#include <QDialog>

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

private slots:
    void on_pushButton_clicked();


    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_2_clicked();

private:
    Ui::Options *ui;
    //GameArea *gameArea;
};

#endif // OPTIONS_H
