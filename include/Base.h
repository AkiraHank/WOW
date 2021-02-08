//
// Created by Hank on 2021/2/5.
//

#ifndef WOW_BASE_H
#define WOW_BASE_H
#include <vector>
#include <string>
#include "Soldier.h"
#include "Weapon.h"
class Base {
public:
    Base(string _name):name(_name){}
    ~Base(){
        for(auto p:_soldiers){
            free(p);
        }
    }

    int _soldier_id;
    int _health;
    bool _state;
    std::string name;
    std::vector<Soldier*> _soldiers;

    void create(int _idx, int _hp);
    void alloc_weapon(Soldier* _soldier, int _id);
    void test(Soldier*);
    int blueOrder[5] = {0,1,2,3,4};
    int redOrder[5] = {1,4,3,0,2};

private:

};


#endif //WOW_BASE_H
