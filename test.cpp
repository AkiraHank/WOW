//
// Created by Hank on 2021/2/7.
//

#include "test.h"

void testClass::create(int _idx, int _hp) {
    int order[5] = {0,1,2,3,4};
    switch(order[_idx%3]){
        case 0: {//iceman
            if(this->_health >= _hp){
                auto _iceman = new iceman(_hp,100, _idx);
                this->_health -= _hp;
                alloc_weapon(_iceman, _idx%3);
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
    }
}

void testClass::alloc_weapon(Soldier* _soldier, int _idx){
    switch(_idx%3){
        case 0: {

            break;
        }
        case 1:{

            break;
        }
        case 2:{

            break;
        }
    }
}