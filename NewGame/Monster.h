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
    int m_value;
    /*std::array<std::string, 10> m_monsterName;*/
    std::string m_monsterName;
public:
    Monster();
    ~Monster();
    int setHp(int hp);
    int getHp();
    void setName(std::string name);
    int setMp(int mp);
    int setStrength(int strength);
    int setAgility(int agility);
    int setVitality(int vitality);
    int setIntelligence(int intelligence);
    int getMp();
    int getValue();
    int getVitality();
    int getIntelligence();
    int getStrength();
    int getAgility();
    std::string getName();
    void dragonNames();
    void dragonNames2();
    void dragonNames3();
    void wolfNames();
    void wolfNames2();
    void wolfNames3();
    void goblinNames();
    void goblinNames2();
    void goblinNames3();
    void orcNames();
    void orcNames2();
    void orcNames3();
    void ogreNames();
    void ogreNames2();
    void ogreNames3();
    void randMonster();
    void setMonsterStats();
    void setValue(int value);
};



#endif //GAME_MONSTER_H
