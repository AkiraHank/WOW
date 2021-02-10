#include <iostream>
#include "include/Soldier.h"
#include "include/HeadQuarter.h"
#include "include/Weapon.h"
#include "include/City.h"

#include <vector>
#include <string>
using std::vector;
int main() {
    int k = 5;
    auto Red_base = new HeadQuarter("red",10000,0);
    auto Blue_base = new HeadQuarter("blue",10000,k+1);

    vector<City*> cities;
    for(int i=1;i<=k;i++){
        auto tmp = new City(i);
        cities.emplace_back(tmp);
    }



    delete(Red_base);
    delete(Blue_base);
    for(auto c:cities) delete(c);
    return 0;
}
