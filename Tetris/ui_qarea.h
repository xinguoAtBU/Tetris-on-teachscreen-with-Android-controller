/********************************************************************************
** Form generated from reading ui file 'qarea.ui'
**
** Created: Thu Dec 11 22:23:09 2014
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QAREA_H
#define UI_QAREA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_QareA
{
public:

    void setupUi(QFrame *QareA)
    {
        if (QareA->objectName().isEmpty())
            QareA->setObjectName(QString::fromUtf8("QareA"));
        QareA->setFrameShadow(QFrame::Raised);
        QareA->resize(400, 300);
        QareA->setFrameShape(QFrame::StyledPanel);

        retranslateUi(QareA);

        QMetaObject::connectSlotsByName(QareA);
    } // setupUi

    void retranslateUi(QFrame *QareA)
    {
        QareA->setWindowTitle(QApplication::translate("QareA", "Frame", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(QareA);
    } // retranslateUi

};

namespace Ui {
    class QareA: public Ui_QareA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QAREA_H
