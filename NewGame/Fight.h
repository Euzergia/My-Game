//
// Created by Lenovo on 14.12.2019.
//

#ifndef GAME_FIGHT_H
#define GAME_FIGHT_H
#include <iostream>
#include "Character.h"
#include "Monster.h"


class Fight {
    std::string input = "";
public:
    void line();
    int getFight(Monster* monster, Character* character);
    void attackName(Monster* monster);
};


#endif //GAME_FIGHT_H
