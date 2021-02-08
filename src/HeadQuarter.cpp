//
// Created by Hank on 2021/2/5.
//

#include "../include/HeadQuarter.h"

std::string  HeadQuarter::nameOrder[] =  {"iceman","lion","wolf","ninja","dragon"};

void HeadQuarter::create(int _idx, int _hp, int _dam) {
    int* order;
    if(this->name == "red") order = blueOrder;
    else order = redOrder;

    switch(order[_idx%5]){
        case 0: {//iceman
            if(this->_health >= _hp){
                auto _iceman = new iceman(_hp, _dam, _idx);
                _iceman->base = this;
                this->_health -= _hp;
                this->_soldiers.emplace_back(_iceman);

            }
            break;
        }
        case 1: {//lion
            if(this->_health >= _hp){
                this->_health -= _hp;
                auto _iceman = new lion(_hp, _dam, _idx, this->_health);
                _iceman->base = this;
                this->_soldiers.emplace_back(_iceman);
            }
            break;
        }
        case 2: {//wolf
            if(this->_health >= _hp){
                auto _iceman = new wolf(_hp, _dam, _idx);
                _iceman->base = this;
                this->_health -= _hp;
                this->_soldiers.emplace_back(_iceman);
            }
            break;
        }
        case 3: {//ninja
            if(this->_health >= _hp){
                auto _iceman = new ninja(_hp, _dam, _idx);
                _iceman->base = this;
                this->_health -= _hp;
                this->_soldiers.emplace_back(_iceman);
            }
            break;
        }
        case 4: {//dragon
            if(this->_health >= _hp){
                auto _iceman = new dragon(_hp, _dam, _idx);
                _iceman->base = this;
                this->_health -= _hp;
                this->_soldiers.emplace_back(_iceman);
            }
            break;
        }
    }
}



