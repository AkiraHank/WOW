//
// Created by Hank on 2021/2/5.
//

#ifndef WOW_SOLDIER_H
#define WOW_SOLDIER_H
#include <vector>
#include <iostream>
class Weapon;
class HeadQuarter;
class City;
bool wCmp(Weapon* a, Weapon* b);

class Soldier{
public:
    Soldier(int hp, int dam, int id);
    virtual ~Soldier();
    int _strength;
    int _id;
    int _damage;
    int _typeId;

    City* _city = nullptr;

    std::vector<Weapon*> _weapons;
    int _weaponIdx;

    virtual void attack(int , Soldier*)=0;
    virtual void get_weapon()=0;
    void report();

    HeadQuarter* base = nullptr;
    void march(std::vector<City*>& cities);
    void hurted(int);
    virtual void rob(Soldier* ){};
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
    //void march(std::vector<City*>& cities) override;
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
    //void march(std::vector<City*>& cities) override;
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
    //void march(std::vector<City*>& cities) override;
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
    //void march(std::vector<City*>& cities) override;
    int loyalty;
};

class wolf : public Soldier{
public:
    wolf(int hp, int dam, int id):Soldier(hp,dam,id){
        printf("wolf %d born\n",_id);
        this->_typeId = 2;
    }
    ~wolf();
    void rob(Soldier* _soldier) override;

    void attack(int, Soldier*) override;
    void get_weapon() override{}
    //void march(std::vector<City*>& cities) override;
};

#endif //WOW_SOLDIER_H
