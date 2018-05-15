#include "character.h"
int Character::GRID_SIZE = 32;

Character::Character()
{

}

Character::~Character()
{

}

void Character::loadAll(QString path)
{
    all.load(path);
}

void Character::loadNow()
{
    this->now = all.copy(QRect(_steps*Character::GRID_SIZE, _direc*Character::GRID_SIZE, 1*Character::GRID_SIZE, 1*Character::GRID_SIZE));
}

void Character::show(QPainter *pa)
{
    pa->drawImage(_posX*GRID_SIZE, _posY*GRID_SIZE, now);
    //pa->drawImage(0, 0, death);
}

void Character::move(int direction, int steps)
{
    if(_direc != direction){
        _steps = 1;
        _direc = direction;
    }
    switch (direction){
        case 0:
            this->_posY += steps;
            break;
        case 3:
            this->_posY -= steps;
            break;
        case 1:
            this->_posX -= steps;
            break;
        case 2:
            this->_posX += steps;
            break;
    }
    this->now = all.copy(QRect(_steps*Character::GRID_SIZE, _direc*Character::GRID_SIZE, 1*Character::GRID_SIZE, 1*Character::GRID_SIZE));
    _steps++;
    _steps = _steps % 3;
}

void Character::LVup()
{
    if(_EXPnow < _EXP)
           return;
    this->_LV++;
    this->_HP += 5;
    this->_HPnow = _HP;
    this->_MP += 2;
    this->_MPnow = _MP;
    this->_EXPnow = 0;
    this->_EXP += 5;
}

void Character::injured(int n_attack)
{
    int inj = n_attack - this->_defend;
    if(inj<0) inj = 0;
    this->_HPnow -= inj;
}

void Character::healing(int HP)
{
    this->_HPnow += HP;
    if(_HP<_HPnow)
        _HPnow = _HP;
}
