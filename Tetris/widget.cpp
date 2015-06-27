#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <malloc.h>
#include <QByteArray>
#include <QFile>
#include <QTextStream>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{   textshow="Your Score";
	data="aa";
	id=0;
    startornot=0;
    difficult=1;
    score2="0";
    level=10;
    ui->setupUi(this);
    this->resize(480,270);
    this->gameArea=new GameArea(this);
    this->timer = new QTimer(this);
    connect(this->timer,SIGNAL(timeout()),this,SLOT(timer_upDate()));
    this->timer2 = new QTimer(this);
    connect(this->timer2,SIGNAL(timeout()),this,SLOT(timer2_upDate()));
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    score =0;
}

void Widget::timer_upDate()
{
    this->gameArea->moveOneStep();
    if(this->gameArea->isMoveEnd())
    {
         if(this->gameArea->isGame_Over())
            {
            this->timer->stop();
             startornot=0;
            QMessageBox::warning(this,tr("warning"),tr("Game Over!"),QMessageBox::Yes);
            this->score=0;
            this->gameArea->init_Game();
            this->gameArea->gameStart();
            this->timer->start(500*level/10);
            }
        else
            {
            this->gameArea->nextItem();
            int num = this->gameArea->getFullRowNum();
            this->doScore(num);
            this->gameArea->gameStart();
            }
        }
    else
        {
        this->gameArea->do_MoveNext();
        }
    }
void Widget::timer2_upDate(){
    int move=0;
    char buf[128];
char subbuf[3];
	/*QFile file("/home/root/proejct/dahu");
	if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
	//do nothing
	}
	QTextStream in(&file);
	QString line = in.readLine();
	while(!line.isNull()){
	process_line(line);
	line=in.readLine();
	}
	data=line;
	file.close();
		*/
	FILE * pFile;
	pFile = fopen("/home/root/proejct/dahu", "r");
	while(fread(buf,4,1,pFile)!=0);
	fclose(pFile);
	//data =buf;
int tempid;
strncpy(subbuf,buf,3);
tempid=(atoi(subbuf)%100)%10;
//data=subbuf;
if(tempid!=id){
if(buf[1]=='1'){
move=1;
}
else if(buf[1]=='2'){
move =2;
}
else if(buf[1]=='3'){
move=3;
}
else if(buf[1]=='4'){
move=4;
}else {
move =0;
}
}else{
move =0;

}
id =tempid;


    //if(moveID==moveid){
        //do nothing;
//    }
    //lse{
        //moveID=moveid;
//int temp = data.toInt();



    /*if(strcmp(buf[0],"1")==1){
           move=1;
    }
   else if(strcmp(buf[0],"2")==1){
           move=2;
    }
    else if(strcmp(buf[0],"3")==1){
           move=3;
    }
   else if(strcmp(buf[0],"4")==1){
           move=4;
    }else {move =0;
    }*/


        switch(move)
        {   case 0:
            //wait;
            break;
            case 1:
            this->gameArea->do_itemChange();
            this->gameArea->currentItem_to_currentMap();
            this->gameArea->draw_gameArea();
                //up

                break;
            case 2:
                //down
            if(this->gameArea->isKey_Down_Move_OneStep)
            {
                this->gameArea->startY+=this->gameArea->step;
                if(this->gameArea->isMoveEnd()) this->gameArea->startY-=this->gameArea->step;
                else
                {
                    this->gameArea->currentItem_to_currentMap();
                    this->gameArea->draw_gameArea();
                }
            }
            else
            {
                int i=0;
                while(!this->gameArea->isMoveEnd())
                {
                    this->gameArea->startY +=this->gameArea->step;
                    i++;
                }
                this->gameArea->startY -=this->gameArea->step;
                if(i>0)
                {
                    this->gameArea->currentItem_to_currentMap();
                    this->gameArea->draw_gameArea();

                }
            }
                break;
            case 3:
            this->gameArea->startX=this->gameArea->startX - this->gameArea->step;
            if(this->gameArea->isMoveLeft()) this->gameArea->startX = this->gameArea->startX+this->gameArea->step;
            else
            {
                this->gameArea->currentItem_to_currentMap();
                this->gameArea->draw_gameArea();

            }
                //left
                break;
            case 4:
            this->gameArea->startX=this->gameArea->startX + this->gameArea->step;
            if(this->gameArea->isMoveRight()) this->gameArea->startX = this->gameArea->startX-this->gameArea->step;
            else
            {
                this->gameArea->currentItem_to_currentMap();
                this->gameArea->draw_gameArea();

            }
                //right
                break;
       // }

    }
/*printf("timer 2 ends/n");*/
}

void Widget::doScore(int num) //显示分数
{
score += num*100;
//this->ui->label_3->setText(tr("%1").arg(score));
score2=QString("%1").arg(score);

}



void Widget::on_pushButton_clicked()
{
    score=0;
    this->gameArea->init_Game();
    this->gameArea->gameStart();
    this->timer->start(500*level/10);
    startornot=1;
    this->timer2->start(10);
    this->gameArea->setFocus();
    this->doScore(0);

}
Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    if(this->ui->pushButton_2->isChecked())
    {
    this->timer->stop();
        startornot=0;
    //this->ui->pushButton_2->setText(tr(" continue "));
    }
    else
    {
    this->timer->start(500*level/10);
    //this->ui->pushButton_2->setText(tr("pause"));
    this->gameArea->setFocus();
    }
}

void Widget::on_pushButton_3_clicked()
{
    this->timer->stop();
    startornot=0;
    this->timer2->stop();
    this->on_pushButton_clicked();
}

void Widget::on_pushButton_4_clicked()
{
    this->gameArea->setGameAreaColor(QColor(255,255,0,qrand()%255)); //更改游戏区域背景颜色
    this->gameArea->setBoxBrushColor(QColor(0,255,0,qrand()%255));//更改小方块背景颜色
    this->gameArea->setBoxPenColor(QColor(0,0,0,qrand()%255));//更改小方块边框颜色
    this->gameArea->draw_gameArea();
    this->gameArea->setFocus();
}



void Widget::on_pushButton_6_clicked()
{
    if(this->ui->pushButton_6->isChecked())
    {
    this->gameArea->setDrawGrid(false);
    }
    else
    {
    this->gameArea->setDrawGrid(true);
    }
    this->gameArea->draw_gameArea();
    this->gameArea->setFocus();
}

void Widget::on_pushButton_8_clicked()//down
{
    if(this->gameArea->isKey_Down_Move_OneStep)
    {
        this->gameArea->startY+=this->gameArea->step;
        if(this->gameArea->isMoveEnd()) this->gameArea->startY-=this->gameArea->step;
        else
        {
            this->gameArea->currentItem_to_currentMap();
            this->gameArea->draw_gameArea();
        }
    }
    else
    {
        int i=0;
        while(!this->gameArea->isMoveEnd())
        {
            this->gameArea->startY +=this->gameArea->step;
            i++;
        }
        this->gameArea->startY -=this->gameArea->step;
        if(i>0)
        {
            this->gameArea->currentItem_to_currentMap();
            this->gameArea->draw_gameArea();

        }
    }
}

void Widget::on_pushButton_11_clicked()//left
{
    this->gameArea->startX=this->gameArea->startX - this->gameArea->step;
    if(this->gameArea->isMoveLeft()) this->gameArea->startX = this->gameArea->startX+this->gameArea->step;
    else
    {
        this->gameArea->currentItem_to_currentMap();
        this->gameArea->draw_gameArea();

    }

}

void Widget::on_pushButton_10_clicked()//right
{
    this->gameArea->startX=this->gameArea->startX + this->gameArea->step;
    if(this->gameArea->isMoveRight()) this->gameArea->startX = this->gameArea->startX-this->gameArea->step;
    else
    {
        this->gameArea->currentItem_to_currentMap();
        this->gameArea->draw_gameArea();

    }
}

void Widget::on_pushButton_12_clicked()//up
{
    this->gameArea->do_itemChange();
    this->gameArea->currentItem_to_currentMap();
    this->gameArea->draw_gameArea();

}
void Widget:: drawRotatedText(QPainter *painter, int x, int y, const QString &text)
{
    painter->save();
    painter->translate(x, y);
    painter->rotate(270); // or 270
    painter->drawText(0, 0, text);
    painter->restore();
}

void Widget::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    this->drawRotatedText(&painter,150,70,textshow);
    this->drawRotatedText(&painter,170,70,score2);
    QString lvlabel="Lv";
    this->drawRotatedText(&painter,220,260,lvlabel);
    QString lv = QString("%1").arg(difficult);
    this->drawRotatedText(&painter,240,260,lv);
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    int speedlevel = this->ui->horizontalSlider->value();
    switch(speedlevel){
    case 1:
        level=10;
        difficult=1;
        break;
    case 2:
        level=8;
        difficult=2;
        break;
    case 3:
        level=6;
        difficult=3;
        break;
    case 4:
        level=4;
        difficult=4;
        break;
    case 5:
        level=2;
        difficult=5;
        break;
	this->timer->stop();
   	this->timer->start(500*level/10);

    }

    if(startornot==0){

    }else{
    this->timer->stop();
    this->timer->start(500*level/10);
    }
    this->gameArea->setFocus();
}
