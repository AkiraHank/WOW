//
// Created by Hank on 2021/2/5.
//

#include "../include/Soldier.h"
#include "../include/Weapon.h"
#include "../include/HeadQuarter.h"
#include <algorithm>

void Soldier::die(){

}

void Soldier::report() {
    if(this->_weapons.empty())
        printf("%s %s %d has no weapon!\n",base->name.c_str(),HeadQuarter::nameOrder[_typeId].c_str(),_id);
    else{
        printf("%s %d has %d weapons:",HeadQuarter::nameOrder[_typeId].c_str(),_id,this->_weapons.size());
        for(auto w:this->_weapons){
            printf(" %s",Weapon::wOrder[w->_wNum%3].c_str());
        }
        printf(".\n");
    }
}

void Soldier::hurted(int dam) {
    this->_strength -= dam;
    if(this->_strength <= 0){ //die

    }
    printf("%s %d took %d damage\n",HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id,dam);
}


//dragon

dragon::~dragon() noexcept {
    for(auto w:this->_weapons){
        free(w);
    }
}

void dragon::attack(int _weaponId, Soldier* _soldier) {
    if(this->_weapons.empty()) return;
    std::sort(this->_weapons.begin(),this->_weapons.end(),Weapon::sortWeapon);
    this->_weapons[_weaponId]->attack(_soldier);
    if(this->_strength>0) yell();
}

void dragon::get_weapon() {
    switch(this->_id%3){
        case 0: {
            auto _sword = new sword(this->_damage);
            _sword->_user = this;
            this->_weapons.emplace_back(_sword);
            break;
        }
        case 1:{
            auto _bomb = new bomb(this->_damage);
            _bomb->_user = this;
            this->_weapons.emplace_back(_bomb);
            break;
        }
        case 2:{
            auto _arrow = new arrow(this->_damage);
            _arrow->_user = this;
            this->_weapons.emplace_back(_arrow);
            break;
        }
    }
}

void dragon::march() {

}

void dragon::yell() {
    printf("I survived again!\n");
}
//ninja
//ninja::ninja(int) {
//
//}

ninja::~ninja() noexcept {
    for(auto w:this->_weapons){
        free(w);
    }
}

void ninja::attack(int _weaponId, Soldier* _soldier) {
    this->_weapons[_weaponId]->attack(_soldier);
}

void ninja::get_weapon() {
    switch(this->_id%3){
        case 0: {
            auto _sword = new sword(this->_damage);
            _sword->_user = this;
            auto _bomb = new bomb(this->_damage);
            _bomb->_user = this;
            this->_weapons.emplace_back(_sword);
            this->_weapons.emplace_back(_bomb);
            break;
        }
        case 1:{
            auto _bomb = new bomb(this->_damage);
            _bomb->_user = this;
            auto _arrow = new arrow(this->_damage);
            _arrow->_user = this;
            this->_weapons.emplace_back(_bomb);
            this->_weapons.emplace_back(_arrow);
            break;
        }
        case 2:{
            auto _arrow = new arrow(this->_damage);
            _arrow->_user = this;
            auto _sword = new sword(this->_damage);
            _sword->_user = this;
            this->_weapons.emplace_back(_arrow);
            this->_weapons.emplace_back(_sword);
            break;
        }
    }
}

void ninja::march() {

}
//iceman
//iceman::iceman(int) {
//
//}

iceman::~iceman() noexcept {
    for(auto w:this->_weapons){
        free(w);
    }
}

void iceman::attack(int _weaponId, Soldier* _soldier) {
    this->_weapons[_weaponId]->attack(_soldier);
}

void iceman::get_weapon() {
    switch(this->_id%3){
        case 0: {
            auto _sword = new sword(this->_damage);
            _sword->_user = this;
            this->_weapons.emplace_back(_sword);
            break;
        }
        case 1:{
            auto _bomb = new bomb(this->_damage);
            _bomb->_user = this;
            this->_weapons.emplace_back(_bomb);
            break;
        }
        case 2:{
            auto _arrow = new arrow(this->_damage);
            _arrow->_user = this;
            this->_weapons.emplace_back(_arrow);
            break;
        }
    }
}

void iceman::march() {

}
//lion
//lion::lion(int k) {
//    lion::loyalty = k;
//}

lion::~lion() noexcept {
    for(auto w:this->_weapons){
        free(w);
    }
}

void lion::attack(int _weaponId, Soldier* _soldier) {
    this->_weapons[_weaponId]->attack(_soldier);
}

void lion::get_weapon() {
    switch(this->_id%3){
        case 0: {
            auto _sword = new sword(this->_damage);
            _sword->_user = this;
            this->_weapons.emplace_back(_sword);
            break;
        }
        case 1:{
            auto _bomb = new bomb(this->_damage);
            _bomb->_user = this;
            this->_weapons.emplace_back(_bomb);
            break;
        }
        case 2:{
            auto _arrow = new arrow(this->_damage);
            _arrow->_user = this;
            this->_weapons.emplace_back(_arrow);
            break;
        }
    }
}

void lion::march() {

}
//wolf
//wolf::wolf(int) {
//
//}

wolf::~wolf() noexcept {
    for(auto w:this->_weapons){
        free(w);
    }
}

void wolf::attack(int _weaponId, Soldier* _soldier) {
    int minIdx = 0x7fffffff, id2Rob = -1;
    for(int i =0;i<_soldier->_weapons.size();i++){
        if(_soldier->_weapons[i]->_wNum < minIdx){
            minIdx = _soldier->_weapons[i]->_wNum;
            id2Rob = i;
        }
    }
    if(id2Rob != -1 && _soldier->_typeId != 2){ // weapon robbed
        this->_weapons.emplace_back(_soldier->_weapons[id2Rob]);
        _soldier->_weapons[id2Rob]->_user = this;
        _soldier->_weapons.erase(_soldier->_weapons.begin()+id2Rob);
        this->_weapons[_weaponId]->attack(_soldier);
    }
}

void wolf::march() {

}
