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
    int m_dmg;
    std::string m_monster;
    std::string m_attackName;
    /*std::array<std::string, 10> m_monsterName;*/
    std::string m_monsterName;
public:
    Monster();
    ~Monster();
    void setMonsterType(std::string type);
    std::string getMonsterType();
    int setHp(int hp);
    int getHp();
    int critDamage() const;
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
    void setDmg(int dmg);
    int getDmg();
    std::string getName() const;
    std::string getAttackName();
    void setAttackName(std::string attackName);
    void dragonNames(int tier, int attType);
    void wolfNames(int tier, int attType);
    void goblinNames(int tier, int attType);
    void orcNames(int tier, int attType);
    void ogreNames(int tier, int attType);
    void randMonster();
    void setMonsterStats();
    void setValue(int value);
};



#endif //GAME_MONSTER_H
