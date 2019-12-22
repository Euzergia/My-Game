//
// Created by Lenovo on 14.12.2019.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "Items.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

class Character {
private:
    int m_hp;
    int m_mp;
    int m_strength;
    int m_agility;
    int m_vitality;
    int m_intelligence;
    Items m_currWeapon;
    Items m_currArmor;
    int m_dmg;
    int m_def;
    std::string m_name;
    std::string m_weaponName;
    std::string m_armorName;
    int m_lvl;
    int m_exp;
    int m_expLimit;
    int m_gold;
    std::vector<Items> m_inventory;
    std::vector<Items> m_character;

public:
    Character();
    void setName();
    std::string getName();
    void setWeapon(const Items& weapon);
    void setArmor(const Items& armor);
    int getDamage() const;
    int getBaseDmg();
    void setWeaponName(std::string wName);
    void setArmorName(std::string wName);
    std::string getWeaponName();
    std::string getArmorName();
    int getHp();
    int getMp();
    void showStats();
    void showChar();
    void showInventory();
    void showHelp();
    static void chooseWeapon(Character* character);
    void weapChar();
    void armoChar();
    Items getWeapon();
    Items getArmor();
    int getDef();
};




#endif //GAME_CHARACTER_H
