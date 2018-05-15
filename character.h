#ifndef KNIGHT1_H
#define KNIGHT1_H
#include<QString>
#include <QImage>
#include <QPainter>
#include<QString>
#include<iostream>
using namespace std;

class Character{
public:
    static int GRID_SIZE;
    Character();
    ~Character();
    int getX(){return _posX;}
    int getY(){return _posY;}
    int getDirec(){return _direc;}
    int getSteps(){return _steps;}
    void show(QPainter *pa);
    void setX(int x){_posX = x;}
    void setY(int y){_posY = y;}
    void setDirec(int d){_direc = d;}
    void setSteps(int s){_steps = s;}
    void setHP(int h){_HP = h; _HPnow = h;}
    int getHP(){return _HPnow;}
    void setMP(int m){_MP = m; _MPnow = m;}
    void setEXP(int e){_EXP = e; _EXPnow = 0;}
    void setLV(int l){_LV = l;}
    void setAtt(int a){_attack = a;}
    void setDef(int d){_defend = d;}
    void move(int direction, int steps);
    void loadAll(QString path);
    void loadNow();
    void LVup();
    void injured(int n_attack);
    void healing(int HP);

 private:
    QImage all;
    QImage now;
    int _direc;
    //0123下上左右
    int _steps;
    int _posX;
    int _posY;
    int _LV;      //等级
    int _HP;      //生命值
    int _HPnow;     //当前生命
    int _MP;      //魔法值
    int _MPnow;     //当前魔法
    int _EXP;     //经验值
    int _EXPnow;   //当前经验
    int _attack;        //攻击力
    int _defend;        //防御力
};

#endif // KNIGHT1_H
