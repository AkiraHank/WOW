//
// Created by Hank on 2021/2/5.
//

#include "../include/Weapon.h"
void sword::attack(Soldier *_soldier) {
    _soldier->hurted(this->_damage);
}

void bomb::attack(Soldier *_soldier) {
    _soldier->hurted(this->_damage);
    this->_user->hurted(this->_damage/2);
}

void arrow::attack(Soldier *_soldier) {
    if(this->_times>0){
        _soldier->hurted(this->_damage);
        this->_times--;
    }

}