//
// Created by Hank on 2021/2/5.
//
#ifndef WOW_HEADQUARTER_H
#define WOW_HEADQUARTER_H
#include <cstdio>
#include <vector>
#include <string>
#include "Weapon.h"
#include "Soldier.h"

class HeadQuarter{
public:
    HeadQuarter(std::string&& _name, int hp, int id): name(_name),_health(hp),_city_id(id){
        printf("%s headquarter initialized!\n",name.c_str());
    }
    ~HeadQuarter(){
        //printf("Base destruction called!\n");
        for(auto p:_soldiers){
            delete(p);
        }
    }

    int _soldier_id;
    int _health;
    bool _is_occupied = false;
    std::string name;
    std::vector<Soldier*> _soldiers;
    int _city_id;

    void create(int _idx, int _hp, int _dam);
    //void alloc_weapon(Soldier* _soldier, int _id);

    static std::string nameOrder[5];
    int blueOrder[5] = {0,1,2,3,4};
    int redOrder[5] = {1,4,3,0,2};

private:

};


#endif //WOW_HEADQUARTER_H
