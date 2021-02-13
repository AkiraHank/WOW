//
// Created by Hank on 2021/2/5.
//

#include "../include/Weapon.h"
#include "../include/Soldier.h"

std::string Weapon::wOrder[3] = {"sword","bomb","arrow"};

void sword::attack(Soldier *_soldier) {
    _soldier->hurted(this->_damage);
}

void bomb::attack(Soldier *_soldier) {
    printf("BOMB!!!!\n");
    _soldier->hurted(this->_damage);
    if(this->_user->_typeId != 3)
        this->_user->hurted(this->_damage/2);
    for(auto it=this->_user->_weapons.begin();it!=this->_user->_weapons.end();it++){
        if((*it)->_wNum == this->_wNum){
            this->_user->_weapons.erase(it,it+1);
            delete(this);
            break;
        }
    }
}

void arrow::attack(Soldier *_soldier) {
    if(this->_times>0){
        _soldier->hurted(this->_damage);
        this->_times--;
    }
    if(this->_times==0){
        for(auto it=this->_user->_weapons.begin();it!=this->_user->_weapons.end();it++){
            if((*it)->_wNum == this->_wNum && (*it)->_times == 0){
                printf("arrow used up!\n");
                this->_user->_weapons.erase(it,it+1);
                delete(this);
                break;
            }
        }
    }
}


bool Weapon::sortWeapon(Weapon* a, Weapon* b){
    return a->_wNum < b->_wNum;
}