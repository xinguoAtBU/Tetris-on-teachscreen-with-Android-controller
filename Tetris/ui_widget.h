/********************************************************************************
** Form generated from reading ui file 'widget.ui'
**
** Created: Thu Dec 11 22:23:09 2014
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSlider *horizontalSlider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(472, 321);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(330, 20, 31, 31));
        pushButton->setMouseTracking(false);
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/5.png);"));
        pushButton->setCheckable(true);
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(350, 130, 31, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/3.png);"));
        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(330, 90, 31, 31));
        pushButton_10->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/1.png);"));
        pushButton_11 = new QPushButton(Widget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(330, 170, 31, 31));
        pushButton_11->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/2.png);"));
        pushButton_12 = new QPushButton(Widget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(310, 130, 31, 31));
        pushButton_12->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/4.png);"));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 20, 31, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/9.png);"));
        pushButton_2->setCheckable(true);
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(390, 170, 31, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/10.png);"));
        pushButton_6->setCheckable(true);
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 70, 31, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/4.png);"));
        pushButton_3->setCheckable(true);
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(390, 110, 41, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/7.png);"));
        pushButton_4->setCheckable(true);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(320, 210, 91, 19));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(5);
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_8->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_2->setText(QString());
        pushButton_6->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        Q_UNUSED(Widget);
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
