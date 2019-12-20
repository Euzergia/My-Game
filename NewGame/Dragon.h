//
// Created by Lenovo on 14.12.2019.
//

#ifndef GAME_DRAGON_H
#define GAME_DRAGON_H

#include "Monster.h"

class Dragon:public Monster {
    int m_skill;
public:
    Dragon();
    int skillAttack();
    std::string getName();
};


#endif //GAME_DRAGON_H
