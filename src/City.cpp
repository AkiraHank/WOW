//
// Created by Hank on 2021/2/7.
//

#include "../include/City.h"
#include "../include/Weapon.h"
#include "../include/Soldier.h"
#include <algorithm>

bool wCmp(Weapon* a, Weapon* b){
    return a->_wNum < b->_wNum;
}

void City::battle(){
    Soldier* first,*second;
    if(this->_city_id & 1){ //odd id
        first = this->red_soldier;
        second = this->blue_soldier;
    }else{
        second = this->red_soldier;
        first = this->blue_soldier;
    }
    std::sort(first->_weapons.begin(),first->_weapons.end(),wCmp);
    std::sort(second->_weapons.begin(),second->_weapons.end(),wCmp);

    if(first->_typeId==2) first->rob(second);
    if(second->_typeId==2) second->rob(first);

    int len1 = std::max(static_cast<int>(first->_weapons.size()),1),
        len2 = std::max(static_cast<int>(second->_weapons.size()),1);
    int id1=0,id2=0;


    while(this->_is_red_alive && this->_is_blue_alive){
        first->attack((id1++)%len1,second);
        second->attack((id2++)%len2,first);
    }

}
