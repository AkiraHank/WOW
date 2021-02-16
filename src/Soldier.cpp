//
// Created by Hank on 2021/2/5.
//

#include "../include/Soldier.h"
#include "../include/Weapon.h"
#include "../include/HeadQuarter.h"
#include "../include/City.h"
#include <algorithm>

void Soldier::die(){
    printf("%s %s %d has been slain!\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id);
    if(this->_city != nullptr){
        if(this->base->name == "red"){
            this->_city->_is_red_alive = false;
            this->_city->red_soldier = nullptr;
        }
        else{
            this->_city->_is_blue_alive = false;
            this->_city->blue_soldier = nullptr;
        }
    }
    for(auto it=this->base->_soldiers.begin();it!=this->base->_soldiers.end();it++){
        if((*it)->_id == this->_id) {
            this->base->_soldiers.erase(it,it+1);
            delete(this);
            fflush(stdout);
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
    printf("%s %s %d took %d damage. (%d->%d)\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id,dam,this->_strength+dam,this->_strength);
    if(this->_strength <= 0){ //die
        this->die();
    }
}

void Soldier::march(std::vector<City*>& cities, HeadQuarter* head) {
    int dc = this->base->name=="red"? 1:-1;
    if(this->_typeId == 0){
        this->_strength -= this->_strength/10;
        printf("%s %s %d is melting!\n",this->base->name.c_str(),HeadQuarter::nameOrder[_typeId].c_str(),this->_id);
    }
    if(this->_city == nullptr){ //first step
        int nextId = this->base->_city_id+dc-1;
        if(dc==1){ //red
            this->_city = cities[nextId];
            this->_city->_is_red_alive = true;
            this->_city->red_soldier = this;
            //("%s %s %d has marched to city %d!\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id,this->_city->_city_id);
        }
        else{//blue
            this->_city = cities[nextId];
            this->_city->_is_blue_alive = true;
            this->_city->blue_soldier = this;
            //printf("%s %s %d has marched to city %d!\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id,this->_city->_city_id);
        }
    }else{
        int nextId = this->_city->_city_id+dc;
        if(nextId == 0 || nextId == cities.size()+1){ //taking the headquarter
            if(this->base->name == "red"){
                this->_city->_is_red_alive = false;
                this->_city->red_soldier = nullptr;
            }
            else{
                this->_city->_is_blue_alive = false;
                this->_city->blue_soldier = nullptr;
            }
            this->_city = nullptr;
            head->_is_occupied = true;
            printf("%s %s %d has taken enemy's headquarter!\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id);
            return;
        }
        else if(dc==1){ //red
            this->_city->_is_red_alive = false;
            if(nextId>=cities.size()) return;
            this->_city = cities[nextId-1];
            this->_city->_is_red_alive = true;
            this->_city->red_soldier = this;
            //printf("%s %s %d has marched to city %d!\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id,this->_city->_city_id);
        }
        else { //blue
            this->_city->_is_blue_alive = false;
            if(nextId<=0) return;
            this->_city = cities[nextId-1];
            this->_city->_is_blue_alive = true;
            this->_city->blue_soldier = this;
            //printf("%s %s %d has marched to city %d!\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id,this->_city->_city_id);
        }
        printf("%s %s %d has marched to city %d!\n",this->base->name.c_str(),HeadQuarter::nameOrder[this->_typeId].c_str(),this->_id,this->_city->_city_id);
    }
}

Soldier::Soldier(int hp, int dam, int id):_strength(hp),_damage(dam),_id(id){}

Soldier::~Soldier() noexcept {

}
//dragon

dragon::~dragon() noexcept {
    for(auto w:this->_weapons){
        delete(w);
    }
}

void dragon::attack(int _weaponId, Soldier* _soldier) {
    if(this->_weapons.empty()) return;
    printf("%s dragon %d attacked %s %s %d with %s\n",this->base->name.c_str(),this->_id,
           _soldier->base->name.c_str(),HeadQuarter::nameOrder[_soldier->_typeId].c_str(),_soldier->_id, Weapon::wOrder[this->_weapons[_weaponId]->_wNum].c_str());
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



void dragon::yell() {
    printf("%s dragon %d yelled: \"I survived!\"\n",this->base->name.c_str(),this->_id);
}


ninja::~ninja() noexcept {
    for(auto w:this->_weapons){
        delete(w);
    }
}

void ninja::attack(int _weaponId, Soldier* _soldier) {
    if(this->_weapons.empty()) return;
    printf("%s ninja %d attacked %s %s %d with %s\n",this->base->name.c_str(),this->_id,
           _soldier->base->name.c_str(),HeadQuarter::nameOrder[_soldier->_typeId].c_str(),_soldier->_id, Weapon::wOrder[this->_weapons[_weaponId]->_wNum].c_str());
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

//void ninja::march(std::vector<City*>& cities) {
//
//}


iceman::~iceman() noexcept {
    for(auto w:this->_weapons){
        delete(w);
    }
}

void iceman::attack(int _weaponId, Soldier* _soldier) {
    if(this->_weapons.empty()) return;
    printf("%s iceman %d attacked %s %s %d with %s\n",this->base->name.c_str(),this->_id,
           _soldier->base->name.c_str(),HeadQuarter::nameOrder[_soldier->_typeId].c_str(),_soldier->_id, Weapon::wOrder[this->_weapons[_weaponId]->_wNum].c_str());
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

//void iceman::march(std::vector<City*>& cities) {
//
//}
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
    if(this->_weapons.empty()) return;
    printf("%s lion %d attacked %s %s %d with %s\n",this->base->name.c_str(),this->_id,
           _soldier->base->name.c_str(),HeadQuarter::nameOrder[_soldier->_typeId].c_str(),_soldier->_id, Weapon::wOrder[this->_weapons[_weaponId]->_wNum].c_str());
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

//void lion::march(std::vector<City*>& cities) {
//
//}
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
    if(this->_weapons.empty()) return;
    printf("%s wolf %d attacked %s %s %d with %s\n",this->base->name.c_str(),this->_id,
           _soldier->base->name.c_str(),HeadQuarter::nameOrder[_soldier->_typeId].c_str(),_soldier->_id, Weapon::wOrder[this->_weapons[_weaponId]->_wNum].c_str());
    this->_weapons[_weaponId]->attack(_soldier);
}

//void wolf::march(std::vector<City*>& cities) {
//
//}

void wolf::rob(Soldier *_soldier) {
    if(!_soldier->_weapons.empty() && _soldier->_typeId != 2){
        this->_weapons.emplace_back(_soldier->_weapons[0]);
        _soldier->_weapons[0]->_user = this;
        _soldier->_weapons.erase(_soldier->_weapons.begin());
        std::sort(this->_weapons.begin(),this->_weapons.end(),wCmp);
    }
}
