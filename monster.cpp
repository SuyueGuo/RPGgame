#include "monster.h"

Monster::Monster()
{
    QString path = "E:\\My project\\RPG\\code\\images\\boss1a.png";
    loadAll(path);
    this->setDirec(0);
    this->setSteps(1);
    loadNow();
    this->setX(20);
    this->setY(10);
    this->accumulation = 0;
}
