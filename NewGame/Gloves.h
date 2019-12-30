//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#ifndef GAME_GLOVES_H
#define GAME_GLOVES_H


#include "Items.h"


class Gloves:public Items {
public:
    Gloves(int dmg, int def, int agi, int dur, const std::string& name, int price, int index);
    int getDefense() const;
    std::string getName() const;
};


#endif //GAME_GLOVES_H
