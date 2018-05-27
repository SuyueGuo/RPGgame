#ifndef WARRIOR_H
#define WARRIOR_H
#include"character.h"

class Warrior:public Character
{
public:
    void initialize(QString temp, int x, int y, char camp);
    void phy_attack(Character* people);

};

#endif // WARRIOR_H
