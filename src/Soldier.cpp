//
// Created by Hank on 2021/2/5.
//

#include "../include/Soldier.h"
#include "../include/Weapon.h"
#include "../include/HeadQuarter.h"
#include "../include/City.h"
#include <algorithm>

void Soldier::die(){
    for(auto it=this->base->_soldiers.begin();it!=this->base->_soldiers.end();it++){
        if((*it)->_id == this->_id) {
            this->base->_soldiers.erase(it,it+1);
            delete(this);
            break;
        }
    }
}

void Soldier::report() {
    if(this->_weapons.empty())
        printf("%s %s %d has no weapon!\n",this->base->name.c_str(),HeadQuarter::nameOrder[_typeId].c_str(),_id);
    else{
        printf("%s %s %d has %d weapons:",this->base->name.c_str(),HeadQuarter::nameOrder[_typeId].c_str(),_id,this->_weapons.size());
        for(auto w:this->_weapons){
            printf(" %s",Weapon::wOrder[w->_wNum%3].c_str());
        }
        printf(".\n");
    }
}

void Soldier::hurted(int dam) {
    this->_strength -= dam;
    printf("%s %s %d took %d damage.\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id,dam);
    if(this->_strength <= 0){ //die
        this->die();
    }
}

Soldier::Soldier(int hp, int dam, int id):_strength(hp),_damage(dam),_id(id){}

Soldier::~Soldier() noexcept {
    printf("%s %s has been slain!\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str());
}
//dragon

dragon::~dragon() noexcept {
    for(auto w:this->_weapons){
        delete(w);
    }
}

void dragon::attack(int _weaponId, Soldier* _soldier) {
    if(!this->_weapons.empty())
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
        delete(w);
    }
}

void ninja::attack(int _weaponId, Soldier* _soldier) {
    if(!this->_weapons.empty())
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
        delete(w);
    }
}

void iceman::attack(int _weaponId, Soldier* _soldier) {
    if(!this->_weapons.empty())
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
        delete(w);
    }
}

void lion::attack(int _weaponId, Soldier* _soldier) {
    if(!this->_weapons.empty())
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
    //printf("wolf destructed!\n");
    for(auto w:this->_weapons){
        delete(w);
    }
}

void wolf::attack(int _weaponId, Soldier* _soldier) {
    if(!this->_weapons.empty())
        this->_weapons[_weaponId]->attack(_soldier);
}

void wolf::march() {

}

void wolf::rob(Soldier *_soldier) {
    if(!_soldier->_weapons.empty() && _soldier->_typeId != 2){
        this->_weapons.emplace_back(_soldier->_weapons[0]);
        _soldier->_weapons[0]->_user = this;
        _soldier->_weapons.erase(_soldier->_weapons.begin());
        std::sort(this->_weapons.begin(),this->_weapons.end(),wCmp);
    }
}
