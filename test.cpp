//
// Created by Hank on 2021/2/7.
//
#include <cstdio>
#include <string>
#include <vector>
#include "include/Soldier.h"
#include "test.h"

void testClass::call(int _idx, int _hp) {
    int order[5] = {0,1,2,3,4};
    switch(order[_idx%5]){
        case 0: {//iceman
            if(this->_health >= _hp){
                auto _iceman = new iceman(_hp,100, _idx);
                this->_health -= _hp;
                testSoldier(_iceman, _idx%3);
                this->_soldiers.emplace_back(_iceman);
            }
            break;
        }
        case 1: {//lion

            break;
        }
        case 2: {//wolf

            break;
        }
        case 3: {//ninja

            break;
        }
        case 4: {//dragon

            break;
        }
    }
}

void testClass::testSoldier(Soldier* _soldier, int _idx){
    printf("aaa\n");
}