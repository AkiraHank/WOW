//
// Created by Hank on 2021/2/5.
//

#include "../include/Soldier.h"
void Soldier::hurted(int dam) {
    this->_strength -= dam;
    if(this->_strength <= 0){ //die

    }
}


//dragon

dragon::~dragon() noexcept {

}

void dragon::attack(int _weaponId, Soldier* _soldier) {
    this->_weapons[_weaponId]->attack(_soldier);
}

void dragon::get_weapon(int _idx) {
    switch(_idx%3){
        case 0: {
            auto _sword = new sword(this->_damage);
            this->_weapons.emplace_back(dynamic_cast<Weapon*>(_sword));
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
//ninja
//ninja::ninja(int) {
//
//}

ninja::~ninja() noexcept {

}

void ninja::attack(int _weaponId, Soldier* _soldier) {
    this->_weapons[_weaponId]->attack(_soldier);
}

//iceman
//iceman::iceman(int) {
//
//}

iceman::~iceman() noexcept {

}

void iceman::attack(int _weaponId, Soldier* _soldier) {
    this->_weapons[_weaponId]->attack(_soldier);
}

//lion
//lion::lion(int k) {
//    lion::loyalty = k;
//}

lion::~lion() noexcept {

}

void lion::attack(int _weaponId, Soldier* _soldier) {
    this->_weapons[_weaponId]->attack(_soldier);
}

//wolf
//wolf::wolf(int) {
//
//}

wolf::~wolf() noexcept {

}

void wolf::attack(int _weaponId, Soldier* _soldier) {
    this->_weapons[_weaponId]->attack(_soldier);
}
