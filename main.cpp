#include <iostream>
#include "include/Soldier.h"
#include "include/Base.h"
#include "include/Weapon.h"

void test(Soldier* soldier){
    printf("ok!!\n");
}

int main() {
    Base* Red_base = new Base("red");
    Base* Blue_base = new Base("blue");

    auto _iceman = new iceman(10,10,10);
    test(_iceman);


    free(Red_base);
    free(Blue_base);
    getchar();
    return 0;
}
