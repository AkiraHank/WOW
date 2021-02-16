//
// Created by Hank on 2021/2/5.
//

#include "../include/HeadQuarter.h"

std::string  HeadQuarter::nameOrder[] =  {"iceman","lion","wolf","ninja","dragon"};

void HeadQuarter::create(int _idx, int _hp, int _dam) {
    int* order;
    if(this->name == "red") order = blueOrder;
    else order = redOrder;
    if(this->_health >= _hp)
        printf("%s ",this->name.c_str());
    else return;
    switch(order[_idx%5]){
        case 0: {//iceman

            auto _iceman = new iceman(_hp, _dam, _idx);
            _iceman->base = this;
            this->_health -= _hp;
            this->_soldiers.emplace_back(_iceman);

            break;
        }
        case 1: {//lion

            this->_health -= _hp;
            auto _iceman = new lion(_hp, _dam, _idx, this->_health);
            _iceman->base = this;
            this->_soldiers.emplace_back(_iceman);

            break;
        }
        case 2: {//wolf

            auto _iceman = new wolf(_hp, _dam, _idx);
            _iceman->base = this;
            this->_health -= _hp;
            this->_soldiers.emplace_back(_iceman);

            break;
        }
        case 3: {//ninja

            auto _iceman = new ninja(_hp, _dam, _idx);
            _iceman->base = this;
            this->_health -= _hp;
            this->_soldiers.emplace_back(_iceman);

            break;
        }
        case 4: {//dragon

            auto _iceman = new dragon(_hp, _dam, _idx);
            _iceman->base = this;
            this->_health -= _hp;
            this->_soldiers.emplace_back(_iceman);

            break;
        }
    }
    printf(" (%d->%d)\n",this->_health+_hp,this->_health);
}



