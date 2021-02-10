//
// Created by Hank on 2021/2/7.
//

#ifndef WOW_CITY_H
#define WOW_CITY_H
class Soldier;

class City {
public:
    City(int id):_city_id(id){}

    int _city_id;

    Soldier* red_soldier = nullptr;
    Soldier* blue_soldier = nullptr;
    bool _is_red_alive = false;
    bool _is_blue_alive = false;

    void battle();
};


#endif //WOW_CITY_H
