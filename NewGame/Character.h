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
#include "Monster.h"

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
    Items m_currGloves;
    Items m_currBoots;
    Items m_currHelmet;
    Items m_currHolder;
    int m_dmg;
    int m_def;
    std::string m_name;
    std::string m_weaponName;
    std::string m_armorName;
    std::string m_helmetName;
    std::string m_glovesName;
    std::string m_bootsName;
    int m_lvl;
    int m_potions;
    int m_potionsLimit;
    int m_exp;
    int m_expLimit;
    int m_gold;
    std::vector<Items> m_inventory;
    std::vector<Items> m_character;

public:
    Character();
    void setName();
    void setPotion(int potion);
    int getPotion();
    std::string getName() const;
    int getBaseDmg();
    int setHp(int hp);
    int getHp();
    int getMp();
    void showStats();
    void showChar();
    void showInventory();
    void showHelp();
    static void chooseWeapon(Character* character);
    void weaponChar(int choice);
    void armorChar(int choice);
    void helmetChar(int choice);
    void glovesChar(int choice);
    void bootsChar(int choice);
    void itemsChar();
    void setWeapon(const Items& weapon);
    void setWeaponName(std::string wName);
    std::string getWeaponName();
    Items getWeapon();
    int getDamage() const;
    void setArmor(const Items& armor);
    void setArmorName(std::string wName);
    std::string getArmorName();
    Items getArmor();
    int getDef();
    void setHelmet(const Items& helmet);
    void setHelmetName(std::string wName);
    std::string getHelmetName();
    Items getHelmet();
    void setGloves(const Items& gloves);
    void setGold(int newGold);
    int getGold();
    void setGlovesName(std::string wName);
    std::string getGlovesName();
    Items getGloves();
    void setBoots(const Items& boots);
    void setBootsName(std::string wName);
    std::string getBootsName();
    int getPrice(Items* item) const;
    Items getBoots();
    void reward(Monster* monster);
    void setHolder(const Items& holder);
    Items getHolder();
    int critDamage() const;
};




#endif //GAME_CHARACTER_H
