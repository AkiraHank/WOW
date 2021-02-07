//
// Created by Hank on 2021/2/5.
//

#ifndef WOW_SOLDIER_H
#define WOW_SOLDIER_H
#include <vector>
#include "Weapon.h"
#include "Base.h"

class Soldier{
public:
    int _strength;
    int _id;
    int _damage;

    std::vector<Weapon*> _weapons;
    int _weaponIdx;

    virtual void attack(int , Soldier*)=0;
    virtual void get_weapon(int _idx)=0;
    virtual void yell()=0;
    void die();
    void hurted(int);

    Base* base;
    void march();
};


class dragon : public Soldier{
public:
    dragon(int hp, int dam, int id):strength(hp),_damage(dam),_id(id){
        pritnf("dragon %d born\n",_id);
        get_weapon(id);
    }
    ~dragon();

    void yell();
    void attack(int, Soldier*);
    void get_weapon(int _idx);
};

class ninja : public Soldier{
public:
    ninja(int hp, int dam, int id):strength(hp),_damage(dam),_id(id),Soldier(){
        pritnf("ninja %d born\n",_id);
        get_weapon(id);
    }
    ~ninja();

    void yell();
    void attack(int, Soldier*);
    void get_weapon(int _idx);
};

class iceman : public Soldier{
public:
    iceman(int hp, int dam, int id):strength(hp),_damage(dam),_id(id),Soldier(){
        pritnf("iceman %d born\n",_id);
        get_weapon(id);
    }
    ~iceman();

    void yell();
    void attack(int, Soldier*);
    void get_weapon(int _idx);
};

class lion : public Soldier{
public:
    lion(int hp, int dam, int id, int loy):strength(hp),_damage(dam),_id(id),loyalty(loy),Soldier(){
        pritnf("lion %d born\n",_id);
        get_weapon(id);
    }
    ~lion();

    void yell();
    void attack(int, Soldier*);
    void get_weapon(int _idx);
    int loyalty;
};

class wolf : public Soldier{
public:
    wolf(int hp, int dam, int id):strength(hp),_damage(dam),_id(id),Soldier(){
        pritnf("wolf %d born\n",_id);
        get_weapon(id);
    }
    ~wolf();
    void rob(Soldier* _soldier){

    }

    void yell();
    void attack(int, Soldier*);
    void get_weapon(int _idx);
};

#endif //WOW_SOLDIER_H
