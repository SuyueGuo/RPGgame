#include"warrior.h"
void Warrior::initialize(QString temp, int x, int y, char camp)
{
    QString path = temp;
    loadAll(path);
    this->setDirec(0);
    this->setSteps(1);
    loadNow();
    this->setState(1);
    this->setX(x);
    this->setY(y);
    this->setLV(1);
    this->setHP(10);
    this->setMP(5);
    this->setEXP(10);
    this->setAtt(5);
    this->setMAtt(3);
    this->setDef(1);
    this->setMDef(1);
    this->setCamp(camp);
}

void Warrior::phy_attack(Character *people)
{
    people->injured(0);

}
