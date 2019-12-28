//
// Created by Lenovo on 14.12.2019.
//

#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include <iostream>
#include "Items.h"


class Weapon:public Items {
public:
    Weapon(int dmg, int def, int agi, int dur, const std::string& name, int price);
    int getDamage() const;
    std::string getName() const;
};


#endif //GAME_WEAPON_H
