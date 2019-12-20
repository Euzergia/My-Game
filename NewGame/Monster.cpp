//
// Created by Lenovo on 14.12.2019.
//

#include "Monster.h"

    Monster::Monster(){
        std::srand((unsigned)time(0));
        m_strength = 0;
        m_agility = 0;
        m_vitality = 0;
        m_intelligence = 0;
        m_hp = 0;
        m_mp = 0;
        m_randIndex = 0;
        /*m_monsterName = "Dragon";*/
    }
    int Monster::setHp(int hp){
        m_hp = hp;
    }
    int Monster::getHp(){
        return m_hp;
    }
    std::string Monster::getName(){
        return m_monsterName;
    }
