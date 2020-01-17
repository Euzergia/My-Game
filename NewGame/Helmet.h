//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#ifndef GAME_HELMET_H
#define GAME_HELMET_H

#include "Items.h"

class Helmet:public Items {
public:
    Helmet(int dmg, int def, int agi, int dur, int mpRecovery, int hpRecovery, const std::string& name, int price, int index);
    int getDamage() const;
    std::string getName() const;
};



#endif //GAME_HELMET_H
