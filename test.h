//
// Created by Hank on 2021/2/8.
//

#ifndef WOW_TEST_H
#define WOW_TEST_H

#include <cstdio>
#include <string>
#include <vector>
#include "include/Soldier.h"

class testClass{
public:
    testClass(){}
    ~testClass(){}

    std::string name;
    int _health;
    std::vector<Soldier*> _soldiers;


    void testSoldier(Soldier* _soldier, int _idx);
    void call(int,int);

};
#endif //WOW_TEST_H
