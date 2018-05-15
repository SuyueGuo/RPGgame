#include "player.h"

Player::Player()
{
    QString path = "E:\\My project\\RPG\\code\\images\\knight1b.png";
    loadAll(path);
    this->setDirec(0);
    this->setSteps(1);
    loadNow();
    this->setX(5);
    this->setY(8);
    this->setLV(1);
    this->setHP(10);
    this->setMP(5);
    this->setEXP(10);
    this->setAtt(5);
    this->setDef(1);
}

Player::~Player()
{

}
