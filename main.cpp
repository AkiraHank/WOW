#include <iostream>
#include <vector>
#include "include/Soldier.h"
#include "include/HeadQuarter.h"
#include "include/City.h"
#include <random>

using std::vector;
int main() {
    int k = 6;
    auto Red_base = new HeadQuarter("red",4000,0);
    auto Blue_base = new HeadQuarter("blue",4000,k+1);

    vector<City*> cities;
    for(int i=1;i<=k;i++){
        auto tmp = new City(i);
        cities.emplace_back(tmp);
    }

    int Time = 0;
    int rIdx=0,bIdx=2;
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(200, 1000);
    while(!Red_base->_is_occupied && !Blue_base->_is_occupied){
        Red_base->create(rIdx+Time,u(e),u(e)/2);
        Blue_base->create(rIdx+Time,u(e),u(e)/2);
        for(auto s:Red_base->_soldiers) s->march(cities,Blue_base);
        for(auto s:Blue_base->_soldiers) s->march(cities,Red_base);
        if(Red_base->_is_occupied || Blue_base->_is_occupied) break;
        for(auto c:cities) c->battle();
        fflush(stdout);
        Time += 1;
        if(Time & 1) {
            for(auto s:Red_base->_soldiers) s->report();
            for(auto s:Blue_base->_soldiers) s->report();
        }

    }

    for(auto s:Red_base->_soldiers) s->report();
    for(auto s:Blue_base->_soldiers) s->report();

    if(Red_base->_is_occupied) printf("Blue won!!\n");
    else printf("Red won!!\n");

    for(auto c:cities) delete(c);
    delete(Red_base);
    delete(Blue_base);
    return 0;
}
