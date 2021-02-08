//
// Created by Hank on 2021/2/8.
//

#ifndef WOW_TEST_H
#define WOW_TEST_H

#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include "include/Soldier.h"
#include "include/Weapon.h"
class testClass{
public:
    testClass(std::string _name):name(std::move(_name)){}
    ~testClass(){}

    std::string name;
    int _health;
    std::vector<Soldier*> _soldiers;


    void alloc_weapon(Soldier* _soldier, int _idx);
    void create(int,int);

};
#endif //WOW_TEST_H
