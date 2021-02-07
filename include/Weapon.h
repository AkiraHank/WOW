//
// Created by Hank on 2021/2/5.
//

#ifndef WOW_WEAPON_H
#define WOW_WEAPON_H
#include "Soldier.h"

class Weapon{
public:
    Weapon(){};
    virtual ~Weapon() = 0;
    virtual void attack(Soldier*) = 0;
    int _damage;
    int _wNum;

    Soldier* _user;

private:
};

class sword : public Weapon{
public:
    sword(int _dmg){
        _damage = _dmg*0.2;
    }

    ~sword();

    void attack(Soldier*);
};

class bomb : public Weapon{
public:
    bomb(int _dmg){
        _damage = _dmg*0.4;
    }

    ~bomb();

    void attack(Soldier*);
};

class arrow : public Weapon{
public:
    arrow(int _dmg){
        _damage = _dmg*0.3;
    }
    ~arrow();

    void attack(Soldier*);
private:
    int _times;
};

#endif //WOW_WEAPON_H
