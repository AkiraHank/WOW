//
// Created by Hank on 2021/2/5.
//

#include "../include/Base.h"


void Base::create(int _idx, int _hp) {
    int* order;
    if(this->name == "red") order = blueOrder;
    else order = redOrder;

    switch(order[_idx%5]){
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
        case 3: {//ninja

            break;
        }
        case 4: {//dragon

            break;
        }
    }
}

void Base::alloc_weapon(Soldier* _soldier, int _id) {
    switch(_id%3){
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

