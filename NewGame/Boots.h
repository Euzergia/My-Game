//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#ifndef GAME_BOOTS_H
#define GAME_BOOTS_H


#include "Items.h"


class Boots:public Items {
public:
    Boots(int dmg, int def, int agi, int dur, const std::string& name, int price);
    int getDefense() const;
    std::string getName() const;
};


#endif //GAME_BOOTS_H
