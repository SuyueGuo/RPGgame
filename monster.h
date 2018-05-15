#ifndef MONSTER_H
#define MONSTER_H
#include "character.h"
class Monster: public Character
{
public:
    Monster();
    ~Monster(){}
    void addA(){accumulation++;}
    int getA(){return accumulation;}
    void replaceA(){accumulation = 0;}
private:
    int accumulation;
};

#endif // MONSTER_H
