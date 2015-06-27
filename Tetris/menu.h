#ifndef MENU_H
#define MENU_H
#include "widget.h"
#include "options.h"
#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Menu *ui;
    Widget w;
    Options opt;
};

#endif // MENU_H
