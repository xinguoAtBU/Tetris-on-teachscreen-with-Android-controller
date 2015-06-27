#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QtGui>
#include <QFrame>
#include "myitem.h"
#include <QPainter>
#include <QColor>
#include <QTimer>

namespace gameArea {
    class GameArea;
}

class GameArea : public QFrame {
    Q_OBJECT

public:
    GameArea(QWidget *parent = 0);
    GameArea(int speed,QWidget *parent = 0);

    ~GameArea();

public:
void currentItem_to_currentMap();
    bool isKey_Down_Move_OneStep;
    int startY;
    int step;
    int moveID;
    bool isMoveLeft();
    bool isMoveRight();
    int startX;
    void do_itemChange();


    void init_gameArea(int X,int Y,int frame_width,int frame_height,int width,int height,int boxStep,int start_x,int start_y,int Angle);
    void moveOneStep();
    bool isMoveEnd();
    bool isGame_Over();
    void init_Game();
    void gameStart();
    void nextItem();
    int getFullRowNum();
    void do_MoveNext();
    void draw_gameArea();

    //
    void setGameAreaColor(QColor color=Qt::white);
    void setBoxBrushColor(QColor color=Qt::green);
    void setBoxPenColor(QColor color=Qt::black);
    void set_draw_box_picture(bool Bool=false);
    void setBoxPicture(QString fileName);

    //
    void setPlaySound_moveLeft(QString fileName,bool Bool=false);
    void setPlaySound_moveRight(QString fileName,bool Bool=false);
    void setPlaySound_moveDown(QString fileName,bool Bool=false);
    void setPlaySound_itemChange(QString fileName,bool Bool=false);
    void setPlaySound(bool Bool=false);

    //
    void setRotate(bool Bool=false);
    void setGameAreaPixOrigin(int x,int y);
    void setGameAreaPix(int x,int y);
    void setRotateAngle(int angle);


    void setKey_Down_Move_oneStep(bool Bool = false);
    void setDrawGrid(bool Bool = true);
    void setDrawNextItem(bool Bool =true);
    void setbox(int row,int col);

private:
    void playSound(QString fileName);
    void init_Map(unsigned char *initMap,int row,int col);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void draw_Grid();

    void copy_Map(unsigned char *theMap,unsigned char *toMap,int row,int col);
    void draw_currentMap();

    void draw_nextItem();

    void clearRow();

private:

    int gameArea_width;
    int gameArea_height;
    int map_row;
    int map_col;


    int init_startX;
    int init_startY;
    unsigned char *currentMap;
    unsigned char *copyMap;

    QPixmap *pix_gameArea;
    MyItem *myItem;
    unsigned char *currentItem;
    unsigned char *theNextItem;
    bool isFirstItem;
    bool isGameOver;
    int fullRowNum;
    QColor gameAreaColor;
    QColor boxPenColor;
    QColor boxBrushColor;



    bool isDrawGrid;
    bool isDrawNextItem;
    bool isPlaySound_moveLeft;
    bool isPlaySound_moveRight;
    bool isPlaySound_moveDown;
    bool isPlaySound_itemChange;
    QString sound_moveLeft;
    QString sound_moveRight;
    QString sound_moveDown;
    QString sound_itemChange;

    bool isRotate;
    int theAngle;
    int gameArea_X;
    int gameArea_Y;
    int pix_X;
    int pix_Y;

    bool is_draw_box_picture;
    QString boxPicture;

    QTimer *moveTimer;
    int moveSpeed;

private slots:
    void moveTimer_upDate();

};

#endif // GAMEAREA_H
