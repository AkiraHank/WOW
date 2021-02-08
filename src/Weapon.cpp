//
// Created by Hank on 2021/2/5.
//

#include "../include/Weapon.h"
std::string Weapon::wOrder[3] = {"sword","bomb","arrow"};

void sword::attack(Soldier *_soldier) {
    _soldier->hurted(this->_damage);
}

void bomb::attack(Soldier *_soldier) {
    if(!this->status) return;
    _soldier->hurted(this->_damage);
    if(this->_user->_typeId != 3)
        this->_user->hurted(this->_damage/2);
    this->status = false;
}

void arrow::attack(Soldier *_soldier) {
    if(this->_times>0){
        _soldier->hurted(this->_damage);
        this->_times--;
    }
}


bool Weapon::sortWeapon(Weapon* a, Weapon* b){
    return a->_wNum < b->_wNum;
}