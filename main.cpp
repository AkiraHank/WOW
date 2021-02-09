#include <iostream>
#include "include/Soldier.h"
#include "include/HeadQuarter.h"
#include "include/Weapon.h"


int main() {
    auto Red_base = new HeadQuarter("red",10000);
    auto Blue_base = new HeadQuarter("blue",10000);

    Red_base->create(2,400,100);
    Blue_base->create(1,15,50);

    Red_base->_soldiers[0]->report();
    Red_base->_soldiers[0]->attack(0,Blue_base->_soldiers[0]);
    Red_base->_soldiers[0]->report();

    delete(Red_base);
    delete(Blue_base);
    return 0;
}
