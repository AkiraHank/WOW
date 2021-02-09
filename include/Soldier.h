//
// Created by Hank on 2021/2/5.
//

#ifndef WOW_SOLDIER_H
#define WOW_SOLDIER_H
#include <vector>
#include <iostream>
class Weapon;
class HeadQuarter;

class Soldier{
public:
    Soldier(int hp, int dam, int id);
    virtual ~Soldier();
    int _strength;
    int _id;
    int _damage;
    int _typeId;

    std::vector<Weapon*> _weapons;
    int _weaponIdx;

    virtual void attack(int , Soldier*)=0;
    virtual void get_weapon()=0;
    void report();

    HeadQuarter* base;
    virtual void march()=0;
    void hurted(int);

private:
    void die();
};


class dragon : public Soldier{
public:
    dragon(int hp, int dam, int id):Soldier(hp,dam,id){
        printf("dragon %d born\n",_id);
        this->_typeId = 4;
        get_weapon();
    }
    ~dragon();

    void yell();
    void attack(int, Soldier*) override;
    void get_weapon() override;
    void march() override;
};

class ninja : public Soldier{
public:
    ninja(int hp, int dam, int id):Soldier(hp,dam,id){
        printf("ninja %d born\n",_id);
        this->_typeId = 3;
        get_weapon();
    }
    ~ninja();

    void attack(int, Soldier*) override;
    void get_weapon() override;
    void march() override;
};

class iceman : public Soldier{
public:
    iceman(int hp, int dam, int id):Soldier(hp,dam,id){
        printf("iceman %d born\n",_id);
        this->_typeId = 0;
        get_weapon();
    }
    ~iceman();

    void attack(int, Soldier*) override;
    void get_weapon() override;
    void march() override;
};

class lion : public Soldier{
public:
    lion(int hp, int dam, int id, int loy):Soldier(hp,dam,id),loyalty(loy){
        printf("lion %d born\n",_id);
        this->_typeId = 1;
        get_weapon();
    }
    ~lion();

    void attack(int, Soldier*) override;
    void get_weapon() override;
    void march() override;
    int loyalty;
};

class wolf : public Soldier{
public:
    wolf(int hp, int dam, int id):Soldier(hp,dam,id){
        printf("wolf %d born\n",_id);
        this->_typeId = 2;
    }
    ~wolf();
    void rob(Soldier* _soldier){

    }

    void attack(int, Soldier*) override;
    void get_weapon() override{}
    void march() override;
};

#endif //WOW_SOLDIER_H
