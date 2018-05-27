#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"

#include <map>
#include <iostream>
#include<QTimer>
#include <QMessageBox>
#include<QImage>


using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    //init game world
    _game.initWorld("E:\\My project\\RPG\\code\\images\\background2.png");//TODO 应该是输入有效的地图文件
    timerMonster = new QTimer(this);
    connect(timerMonster,SIGNAL(timeout()),this,SLOT(monsterMove()));
    timerMonster->start(500);
    timerFruit = new QTimer(this);
    connect(timerFruit,SIGNAL(timeout()),this,SLOT(recoverFruit()));
    timerFruit->start(5000);
    this->resize(QSize(894, 864));
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();

    pa->begin(this);
    pa->setPen(QPen(Qt::black,1));
    this->_game.show(pa);

    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(2,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(0,1);
    }
    else if(e->key() == Qt::Key_O)
    {

    }
    else if(e->key() == Qt::Key_P)
    {

    }
    if(!_game.isPlayerAlive()){
        _game.gameover();
    }
    this->repaint();
}
void MW1::recoverFruit()
{
    _game.recoverFruit();
    this->repaint();
}

void MW1::monsterMove()
{
    _game.monsterMove();
    this->repaint();
}
