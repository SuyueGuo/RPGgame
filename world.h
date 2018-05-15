#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include <QImage>
#include "monster.h"
#include "player.h"

class World
{
public:
    World(){}
    ~World(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void handlePlayerMove(int direction, int steps);
        //假定只有一个玩家
    void handleKnightMove(int direction, int steps);
    void recoverFruit();
    void monsterMove();
    void gameover();
    bool isPlayerAlive(){return show_player;}
    void savegame();
    void loadgame();

private:
    vector<RPGObj> _objs;
    vector<RPGObj> _deletes;
    Player* _player;
    bool show_player;
    Monster _monster;
    QImage _background;
    QImage _death;
    short Map[100][100];

};

#endif // WORLD_H
