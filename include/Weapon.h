//
// Created by Hank on 2021/2/5.
//

#ifndef WOW_WEAPON_H
#define WOW_WEAPON_H
#include "Soldier.h"

class Weapon{
public:
    Weapon(){};
    virtual ~Weapon(){}
    virtual void attack(Soldier*) = 0;
    int _damage;
    int _wNum;
    static bool sortWeapon(Weapon*,Weapon*);
    Soldier* _user;

    static std::string wOrder[3];
private:
};

class sword : public Weapon{
public:
    sword(int _dmg){
        _damage = _dmg*0.2;
        _wNum = 0;
    }

    ~sword(){}

    void attack(Soldier*);
};

class bomb : public Weapon{
public:
    bool status = true;
    bomb(int _dmg){
        _damage = _dmg*0.4;
        _wNum = 1;
    }

    ~bomb(){}

    void attack(Soldier*);
};

class arrow : public Weapon{
public:
    arrow(int _dmg){
        _damage = _dmg*0.3;
        _wNum = 2;
    }
    ~arrow(){}

    void attack(Soldier*);
private:
    int _times;
};

#endif //WOW_WEAPON_H
