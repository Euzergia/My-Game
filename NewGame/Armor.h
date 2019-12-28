//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include <iostream>
#include "Items.h"

class Armor:public Items {
public:
    Armor(int dmg, int def, int agi, int dur, const std::string& name, int price);
    int getDefense() const;
    std::string getName() const;
};


#endif //GAME_ARMOR_H
