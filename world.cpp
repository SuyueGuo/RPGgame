#include "world.h"
#include "icon.h"
#include<iostream>
#include<QPainter>
#define XMAX 27
#define YMAX 26
using namespace std;
//short Map[100][100];
//1石头2水果3人物4固定伤害物
void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    memset(Map, 0, 10000);
    const char* path = mapFile.c_str();
    _background.load(path);
    _death.load("E:\\My project\\RPG\\code\\death.jpg");

    _player = new Player;
    show_player = 1;

    //stone 4 5
    RPGObj obj1, obj2, obj3, obj4;
    obj1.initObj("stone");
    obj1.setPosX(4);
    obj1.setPosY(7);
    Map[4][7] = 1;

    obj2.initObj("stone");
    obj2.setPosX(18);
    obj2.setPosY(8);
    Map[18][8] = 1;

    obj3.initObj("cacti");
    obj3.setPosX(4);
    obj3.setPosY(10);
    Map[4][10] = 4;

    obj4.initObj("fruit");
    obj4.setPosX(5);
    obj4.setPosY(13);
    Map[5][13] = 2;

    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
}


void World::show(QPainter* painter){
    painter->drawImage(0, 0, _background);
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    if(show_player){
        this->_player->show(painter);
        this->_monster.show(painter);
    }
    else{

        painter->drawImage(0, 0, _death);
    }

}

void World::handlePlayerMove(int direction, int steps){
    int x = _player->getX();
    int y = _player->getY();
    Map[_player->getX()][_player->getY()] = 0;
    this->_player->move(direction, steps);
    if(Map[_player->getX()][_player->getY()] == 1){//石头
        _player->setX(x);
        _player->setY(y);
    }
    else if(Map[_player->getX()][_player->getY()] == 2){//水果
        RPGObj fruit;
        fruit.initObj("fruit");
        fruit.setPosX(_player->getX());
        fruit.setPosY(_player->getY());
        _deletes.push_back(fruit);
        vector<RPGObj>::iterator it;
        for(it=this->_objs.begin();it!=this->_objs.end();it++){
            if((*it).getPosX() == _player->getX() && (*it).getPosY() == _player->getY()){
                 _objs.erase(it);
                 break;
            }
        }
        Map[_player->getX()][_player->getY()] = 0;
        _player->healed(2);
    }
    else if(Map[_player->getX()][_player->getY()] == 3){//敌人
        _player->setX(x);
        _player->setY(y);
    }
    else if(Map[_player->getX()][_player->getY()] == 4){//固定伤害物
        _player->setX(x);
        _player->setY(y);
        _player->injured(3);
        if(_player->getHP() <= 0){
            gameover();
        }
    }
    if(_player->getX() < 0 || _player->getX() > XMAX)
        _player->setX(x);
    if(_player->getY() < 0 || _player->getY() > YMAX)
        _player->setY(y);
    Map[_player->getX()][_player->getY()] = 3;
}

void World::recoverFruit()
{
    vector<RPGObj>::iterator it;
    for(it = _deletes.begin(); it != _deletes.end(); it++){
        cout<<(*it).getObjType()<<endl;
        RPGObj fruit;
        fruit.initObj("fruit");
        fruit.setPosX((*it).getPosX());
        fruit.setPosY((*it).getPosY());
        _objs.push_back(fruit);
        Map[(*it).getPosX()][(*it).getPosY()] = 2;
    }
    _deletes.clear();

}

void World::monsterMove()
{
    Map[_monster.getX()][_monster.getY()] = 0;
    int x = _monster.getX();
    int y = _monster.getY();
    _monster.move(_monster.getDirec(), 1);
    if(Map[_monster.getX()][_monster.getY()] == 1){//石头
        _monster.setX(x);
        _monster.setY(y);
        Map[_monster.getX()][_monster.getY()] = 3;
        return;
    }
    else if(Map[_monster.getX()][_monster.getY()] == 2){//水果
        RPGObj fruit;
        fruit.initObj("fruit");
        fruit.setPosX(_monster.getX());
        fruit.setPosY(_monster.getY());
        _deletes.push_back(fruit);
        vector<RPGObj>::iterator it;
        for(it=this->_objs.begin();it!=this->_objs.end();it++){
            if((*it).getPosX() == _monster.getX() && (*it).getPosY() ==_monster.getY()){
                 _objs.erase(it);
                 break;
            }
        }
        Map[_monster.getX()][_monster.getY()] = 3;
        return;
    }
    else if(Map[_monster.getX()][_monster.getY()] == 3){//敌人
        _monster.setX(x);
        _monster.setY(y);
        Map[_monster.getX()][_monster.getY()] = 3;
        return;
    }
    _monster.addA();
    if(_monster.getA() == 4){
        _monster.setDirec((_monster.getDirec()+1) % 4);
        _monster.replaceA();
    }
    Map[_monster.getX()][_monster.getY()] = 3;
}

void World::gameover()
{
    show_player = 0;

}

void World::savegame()
{

}

void World::loadgame()
{

}
