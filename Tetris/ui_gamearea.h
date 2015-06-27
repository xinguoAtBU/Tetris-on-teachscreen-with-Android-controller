/********************************************************************************
** Form generated from reading ui file 'gamearea.ui'
**
** Created: Thu Dec 11 22:23:09 2014
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GAMEAREA_H
#define UI_GAMEAREA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:

    void setupUi(QFrame *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->setFrameShadow(QFrame::Raised);
        game->resize(400, 300);
        game->setFrameShape(QFrame::StyledPanel);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QFrame *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Frame", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(game);
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEAREA_H
