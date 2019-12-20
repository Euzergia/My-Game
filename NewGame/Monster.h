//
// Created by Lenovo on 14.12.2019.
//

#ifndef GAME_MONSTER_H
#define GAME_MONSTER_H

#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

class Monster {
protected:
    int m_hp;
    int m_mp;
    int m_strength;
    int m_agility;
    int m_vitality;
    int m_intelligence;
    /*std::array<std::string, 10> m_monsterName;*/
    int m_randIndex;
    std::string m_monsterName;
public:
    Monster();
    int setHp(int hp);
    int getHp();
    virtual std::string getName();
};



#endif //GAME_MONSTER_H
