//
// Created by Lenovo on 14.12.2019.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "Weapon.h"
#include <vector>
#include <ctime>
#include <cstdlib>

class Character {
private:
    int m_hp;
    int m_mp;
    int m_strength;
    int m_agility;
    int m_vitality;
    int m_intelligence;
    Weapon m_currWeapon;
    int m_dmg;
    std::string m_name;
    std::string m_weaponName;

public:
    Character();
    void setName();
    std::string getName();
    void setWeapon(const Weapon& weapon);
    int getDamage() const;
    int getBaseDmg();
    void setWeaponName(std::string wName);
    std::string getWeaponName();
    int getHp();
    int getMp();
    static void chooseWeapon(Character* character);
};




#endif //GAME_CHARACTER_H
