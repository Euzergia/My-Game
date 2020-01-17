//
// Created by Lenovo on 14.12.2019.
//

#include <algorithm>
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"
#include "Boots.h"
#include "Gloves.h"

Character::Character() : m_currWeapon(5,0,0,0,0,0, "",0,0), m_currArmor(0,0,0,0,0,0,"",0,0), m_currHelmet(0,0,0,0,0,0,"",0,0), m_currGloves(0,0,0,0,0,0,"",0,0), m_currBoots(0,0,0,0,0,0,"",0,0), m_currHolder(0,0,0,0,0,0,"",0,0){
        srand(time(nullptr));
        m_strength = (rand () % 11) + 1;
        m_agility = (rand () % 11) + 1;
        m_vitality = (rand () % 11) + 1;
        m_intelligence = (rand () % 11) + 1;
        m_name = "";
        m_lvl = 1;
        m_exp = 0;
        m_expLimit = 200;
        m_dmg = m_strength * m_strength;
        m_def = 0;
        m_hp = m_vitality * m_vitality;
        m_mp = m_intelligence * m_intelligence;
        m_gold = 10;
        m_potions = 3;
        m_potionsLimit = 3;
        m_inventory.reserve(10);
        m_mpRecovery = 2;
        m_hpRecovery = 2;
    }
    void Character::line(){
        std::cout << "-----------------------------" << std::endl;
    }
    void Character::showStats() {
    bool again = true;
    int input;
        const char separator = ' ';
        const int nameWidth = 25;
        while(again) {
            line();
            std::cout << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Status window: " << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Name: ";
            std::cout << m_name << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Level: ";
            std::cout << m_lvl << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Exp: ";
            std::cout << m_exp << std::left << "/" << m_expLimit << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "HP: ";
            std::cout << m_hp << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "MP: ";
            std::cout << m_mp << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "HP Recovery (0): ";
            std::cout << m_hpRecovery << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "MP Recovery (1): ";
            std::cout << m_mpRecovery << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Vitality (2): ";
            std::cout << m_vitality << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Intelligence (3): ";
            std::cout << m_intelligence << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Strength (4): ";
            std::cout << m_strength << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Agility (5): ";
            std::cout << m_agility << std::endl;
            std::cout << std::endl;
            std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Skill points: ";
            std::cout << m_skillPoints << std::endl;
            std::cout << std::endl;
            std::cout << "Back (6)" << std::endl;

            std::cout << std::endl;
            std::cout << "Enter input: " << std::endl;
            std::cin >> input;
            if (std::cin.fail()) {
                line();
                std::cout << std::endl;
                std::cout << "You must enter a number!!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                std::cout << std::endl;
            } else {
                switch (input) {
                    case 0: {
                        if(m_skillPoints > 0) {
                            m_hpRecovery++;
                            m_skillPoints--;
                        }else {
                            std::cout << "You do not have enough skill points!" << std::endl;
                        }
                        break;
                    }
                    case 1: {
                        if(m_skillPoints > 0) {
                            m_mpRecovery++;
                            m_skillPoints--;
                        }else {
                            std::cout << "You do not have enough skill points!" << std::endl;
                        }
                        break;
                    }
                    case 2: {
                        if(m_skillPoints > 0) {
                            m_vitality++;
                            m_skillPoints--;
                            setHp(getHp() + ((m_vitality * m_vitality) - getHp()));
                        }else {
                            std::cout << "You do not have enough skill points!" << std::endl;
                        }
                        break;
                    }
                    case 3: {
                        if(m_skillPoints > 0) {
                            m_intelligence++;
                            m_skillPoints--;
                            setHp(getMp() + ((m_intelligence * m_intelligence) - getMp()));
                        }else {
                            std::cout << "You do not have enough skill points!" << std::endl;
                        }
                        break;
                    }
                    case 4: {
                        if(m_skillPoints > 0) {
                            m_strength++;
                            m_skillPoints--;
                        }else {
                            std::cout << "You do not have enough skill points!" << std::endl;
                        }
                        break;
                    }
                    case 5: {
                        if(m_skillPoints > 0) {
                            m_agility++;
                            m_skillPoints--;
                        }else {
                            std::cout << "You do not have enough skill points!" << std::endl;
                        }
                        break;
                    }
                    case 6: {
                        again = false;
                        break;
                    }
                }
            }
        }
    }
    void Character::showInventory() {
        int index;
        bool again = false;
        int n = 0;
        const char separator = ' ';
        const int nameWidth = 15;
        while (!again) {
            if (std::cin.fail()) {
                line();
                std::cout << std::endl;
                std::cout << "You must enter a number!!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                std::cout << std::endl;
            } else {
                line();
                std::cout << std::endl;
                std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Inventory window: "
                          << std::endl;
                for (int i = 0; i < m_inventory.size(); ++i) {
                    std::cout << i << ". " << m_inventory[i].getName() << std::endl;
                    n = m_inventory.size();
                }
                std::cout << std::endl;
                std::cout << n << ". Back" << std::endl;
                std::cout << std::endl;
                std::cout << "Gold/s: " << m_gold << std::endl;
                std::cout << "Slots used: " << m_inventory.size() << "/" << m_inventory.capacity() << std::endl;

                std::cout << std::endl;
                std::cout << "Enter your input: " << std::endl;
                std::cin >> index;
                if (index == n) {
                    again = true;
                }
                for (int j = 0; j < m_inventory.size(); j++) {
                    if (index == j) {
                        std::string input;
                        std::cout << "A: Equip" << std::endl;
                        std::cout << "B: Sell" << std::endl;
                        std::cout << "C: Discard" << std::endl;
                        std::cin >> input;
                        if (input == "a" || input == "A") {
                            std::cout << "Do you want to equip this item? Press y(yes) or n(no)." << std::endl;
                            std::cin >> input;
                            if (input == "y" || input == "Y") {
                                if (m_inventory[j].getIndex() == 1) { // WEAPON
                                    setHolder(m_inventory[j]);
                                    m_inventory.erase(m_inventory.begin() + index);
                                    if (m_character[0].getName() == "") {
                                        m_character.erase(m_character.begin());
                                    } else {
                                        m_inventory.push_back(getWeapon());
                                        m_character.erase(m_character.begin());
                                    }
                                    m_character.insert(m_character.begin(), getHolder());
                                    setWeapon(getHolder());
                                } else if (m_inventory[j].getIndex() == 2) { //ARMOR
                                    setHolder(m_inventory[j]);
                                    m_inventory.erase(m_inventory.begin() + index);
                                    if (m_character[2].getName() == "") {
                                        m_character.erase(m_character.begin() + 2);
                                    } else {
                                        m_inventory.push_back(getWeapon());
                                        m_character.erase(m_character.begin() + 2);
                                    }
                                    m_character.insert(m_character.begin() + 2, getHolder());
                                    setArmor(getHolder());
                                } else if (m_inventory[j].getIndex() == 3) { //HELMET
                                    setHolder(m_inventory[j]);
                                    m_inventory.erase(m_inventory.begin() + index);
                                    if (m_character[1].getName() == "") {
                                        m_character.erase(m_character.begin() + 1);
                                    } else {
                                        m_inventory.push_back(getWeapon());
                                        m_character.erase(m_character.begin() + 1);
                                    }
                                    m_character.insert(m_character.begin() + 1, getHolder());
                                    setHelmet(getHolder());
                                } else if (m_inventory[j].getIndex() == 4) { //GLOVES
                                    setHolder(m_inventory[j]);
                                    m_inventory.erase(m_inventory.begin() + index);
                                    if (m_character[3].getName() == "") {
                                        m_character.erase(m_character.begin() + 3);
                                    } else {
                                        m_inventory.push_back(getWeapon());
                                        m_character.erase(m_character.begin() + 3);
                                    }
                                    m_character.insert(m_character.begin() + 3, getHolder());
                                    setGloves(getHolder());
                                } else if (m_inventory[j].getIndex() == 5) { //BOOTS
                                    setHolder(m_inventory[j]);
                                    m_inventory.erase(m_inventory.begin() + index);
                                    if (m_character[4].getName() == "") {
                                        m_character.erase(m_character.begin() + 4);
                                    } else {
                                        m_inventory.push_back(getWeapon());
                                        m_character.erase(m_character.begin() + 4);
                                    }
                                    m_character.insert(m_character.begin() + 4, getHolder());
                                    setBoots(getHolder());
                                } else if (input == "n" || input == "N") {

                                }
                            }
                        } else if (input == "b" || input == "B") {
                            std::cout << "Do you want to sell " << m_inventory[index].getName() << " for "
                                      << (m_inventory[index].getPrice() / 2) << " golds? Press y(yes) or n(no).\n";
                            std::cin >> input;
                            if (input == "y" || input == "Y") {
                                m_inventory.erase(m_inventory.begin() + index);
                                std::cout << "You sold it successfully." << std::endl;
                                setGold(getGold() + (m_inventory[index].getPrice() / 2));
                            }
                        } else if (input == "c" || input == "C") {
                            std::cout << "Do you want to discard " << m_inventory[index].getName()
                                      << "? Press y(yes) or n(no).\n";
                            std::cin >> input;
                            if (input == "y" || input == "Y") {
                                m_inventory.erase(m_inventory.begin() + index);
                                std::cout << "You discarded it successfully." << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }
    void Character::showHelp() {
        const char separator = ' ';
        const int nameWidth = 15;
        line();
        std::cout << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Help window: " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Commands: ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Action: " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "stats ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "show your status window " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "char ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "show your character window " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "inv ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "show your inventory window " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "exit ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "leave the game " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "fight ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "challenge a monster " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "clear ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "clear the terminal " << std:: endl;
    }
    void Character::showChar() {
        int input;
        std::string YesOrNo;
        bool again = true;
        bool moreAgain;
        const char separator = ' ';
        const int nameWidth = 15;
        while(again) {
            line();
            if (std::cin.fail()) {
                std::cout << std::endl;
                std::cout << "You must enter a number!!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            } else {
                std::cout << std::endl;
                std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Character window: " << std::endl;
                std::cout << 0;
                std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << ". Weapon: ";
                std::cout << m_character[0].getName() << std::endl;
                std::cout << 1;
                std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << ". Helmet: ";
                std::cout << m_character[1].getName() << std::endl;
                std::cout << 2;
                std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << ". Armor: ";
                std::cout << m_character[2].getName() << std::endl;
                std::cout << 3;
                std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << ". Gloves: ";
                std::cout << m_character[3].getName() << std::endl;
                std::cout << 4;
                std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << ". Boots: ";
                std::cout << m_character[4].getName() << std::endl;
                std::cout << std::endl;
                std::cout << 5 << ". Back" << std::endl;

                std::cout << std::endl;
                std::cout << "Enter your input: " << std::endl;
                std::cin >> input;
                moreAgain = true;
                switch (input) {
                    case 0: {
                        while (moreAgain) {
                            std::cout << "Do you want to unequip this item? Press y(yes) or n(no)." << std::endl;
                            std::cin >> YesOrNo;
                            moreAgain = false;
                        }
                        if (YesOrNo == "y" || YesOrNo == "Y") {
                            if (m_inventory.size() < m_inventory.capacity()) {
                                if (m_character[0].getName() == "") {
                                    std::cout << "You do not have equipped weapon." << std::endl;
                                    m_character.erase(m_character.begin());
                                } else {
                                    m_inventory.push_back(getWeapon());
                                    m_character.erase(m_character.begin());
                                }
                                setWeapon(Weapon(5, 0, 0, 0, 0, 0, "", 0, 0));
                                m_character.insert(m_character.begin(), getWeapon());
                            } else {
                                std::cout << "There is not enough space in the inventory." << std::endl;
                                std::cout << "Inventory space: " << m_inventory.size() << "/" << m_inventory.capacity()
                                          << std::endl;
                            }
                        }
                        break;
                    }
                    case 1: {
                        while (moreAgain) {
                            std::cout << "Do you want to unequip this item? Press y(yes) or n(no)." << std::endl;
                            std::cin >> YesOrNo;
                            moreAgain = false;
                        }
                        if (m_character.size() < m_character.capacity()) {
                            if (YesOrNo == "y" || YesOrNo == "Y") {
                                if (m_character[1].getName() == "") {
                                    std::cout << "You do not have equipped helmet." << std::endl;
                                    m_character.erase(m_character.begin() + 1);
                                } else {
                                    m_inventory.push_back(getHelmet());
                                    m_character.erase(m_character.begin() + 1);
                                }
                                setHelmet(Helmet(0, 0, 0, 0, 0, 0, "", 0, 0));
                                m_character.insert(m_character.begin() + 1, getHelmet());
                            } else {
                                std::cout << "There is not enough space in the inventory." << std::endl;
                                std::cout << "Inventory space: " << m_inventory.size() << "/" << m_inventory.capacity()
                                          << std::endl;
                            }
                        }
                        break;
                    }
                    case 2: {
                        while (moreAgain) {
                            std::cout << "Do you want to unequip this item? Press y(yes) or n(no)." << std::endl;
                            std::cin >> YesOrNo;
                            moreAgain = false;
                        }
                        if (YesOrNo == "y" || YesOrNo == "Y") {
                            if (m_inventory.size() < m_inventory.capacity()) {
                                if (m_character[2].getName() == "") {
                                    std::cout << "You do not have equipped armor." << std::endl;
                                    m_character.erase(m_character.begin() + 2);
                                } else {
                                    m_inventory.push_back(getArmor());
                                    m_character.erase(m_character.begin() + 2);
                                }
                                setArmor(Armor(0, 0, 0, 0, 0, 0, "", 0, 0));
                                m_character.insert(m_character.begin() + 2, getArmor());
                            } else {
                                std::cout << "There is not enough space in the inventory." << std::endl;
                                std::cout << "Inventory space: " << m_inventory.size() << "/" << m_inventory.capacity()
                                          << std::endl;
                            }
                        }
                        break;
                    }
                    case 3: {
                        while (moreAgain) {
                            std::cout << "Do you want to unequip this item? Press y(yes) or n(no)." << std::endl;
                            std::cin >> YesOrNo;
                            moreAgain = false;
                        }
                        if (YesOrNo == "y" || YesOrNo == "Y") {
                            if (m_inventory.size() < m_inventory.capacity()) {
                                if (m_character[3].getName() == "") {
                                    std::cout << "You do not have equipped gloves." << std::endl;
                                    m_character.erase(m_character.begin() + 3);
                                } else {
                                    m_inventory.push_back(getGloves());
                                    m_character.erase(m_character.begin() + 3);
                                }
                                setGloves(Gloves(0, 0, 0, 0, 0, 0, "", 0, 0));
                                m_character.insert(m_character.begin() + 3, getGloves());
                            } else {
                                std::cout << "There is not enough space in the inventory." << std::endl;
                                std::cout << "Inventory space: " << m_inventory.size() << "/" << m_inventory.capacity()
                                          << std::endl;
                            }
                        }
                        break;
                    }
                    case 4: {
                        while (moreAgain) {
                            std::cout << "Do you want to unequip this item? Press y(yes) or n(no)." << std::endl;
                            std::cin >> YesOrNo;
                            moreAgain = false;
                        }
                        if (YesOrNo == "y" || YesOrNo == "Y") {
                            if (m_inventory.size() < m_inventory.capacity()) {
                                if (m_character[4].getName() == "") {
                                    std::cout << "You do not have equipped boots." << std::endl;
                                    m_character.erase(m_character.begin() + 4);
                                } else {
                                    m_inventory.push_back(getBoots());
                                    m_character.erase(m_character.begin() + 4);
                                }
                                setBoots(Boots(5, 0, 0, 0, 0, 0, "", 0, 0));
                                m_character.insert(m_character.begin() + 4, getBoots());
                            } else {
                                std::cout << "There is not enough space in the inventory." << std::endl;
                                std::cout << "Inventory space: " << m_inventory.size() << "/" << m_inventory.capacity()
                                          << std::endl;
                            }
                        }
                        break;
                    }
                    case 5: {
                        again = false;
                        break;
                    }
                    default:
                        std::cout << "Wrong input!!" << std::endl;
                }
            }
        }
    }
    void Character::reward(Monster* monster) {
    srand(time(0));
        int reward = rand() % 5;
        m_gold += reward + monster->getValue(0);
        std::cout << "You acquired this amount of gold: " << reward+monster->getValue(0) << std::endl;
        std::cout << "You acquired these items: " << std::endl;
    }
    void Character::exp(Monster* monster) {
    int count;
        if(m_exp < m_expLimit){
            m_exp += monster->getValue(1);
            while(m_exp > m_expLimit){
                m_exp -= m_expLimit;
                m_expLimit *= 1.2;
                count++;
                std::cout << "Level UP!!" << std::endl;
                m_hp = m_vitality * m_vitality;
                m_mp = m_intelligence * m_intelligence;
            }
            m_lvl += count;
            m_skillPoints += count;
        }
        std::cout << "You acquired this amount of exp: " << monster->getValue(1) << std::endl;
    }
    int Character::setHp(int hp) {
        m_hp = hp;
    }
    void Character::setName(){
        std::string name;
        std::cout << "Enter your nickname: \n";
        std::cin >> name;
        m_name = name;
    }
    std::string Character::getName() const{
        return m_name;
    }
    void Character::setWeapon(const Items& weapon) {
        m_currWeapon = weapon;
    }
    void Character::setArmor(const Items& armor){
        m_currArmor = armor;
    }
    Items Character::getWeapon() {
        return m_currWeapon;
    }
    Items Character::getArmor() {
        return  m_currArmor;
    }
    int Character::critDamage() const{
        srand(time(0));
        int crit = m_dmg / 2;
        int critChance = rand() % 10;
        if(critChance > 7){
            std::cout << getName() << " managed to do a Critical hit!!" << std::endl;
            return crit;
        }else{
            return 0;
        }
    }
    /*int Character::getPositionInInventory() {
        for(int i = 0; i < m_inventory.size(); ++i){

        }
    }
    Items Character::equipFromInv() {
        m_inventory.erase()
    }*/
    int Character::getDamage() const {
        return m_dmg + m_currWeapon.getDamage() + critDamage();
    }
    int Character::getBaseDmg(){
        return  m_dmg;
    }
    int Character::getDef() {
        return m_def + m_currArmor.getDefense() + m_currBoots.getDefense() + m_currGloves.getDefense() + m_currHelmet.getDefense();
    }
    void Character::setWeaponName(std::string wName){
        m_weaponName = wName;
    }
    void Character::setArmorName(std::string wName) {
        m_armorName = wName;
    }
    std::string Character::getWeaponName(){
        return m_weaponName;
    }
    int Character::getHp(){
        return m_hp;
    }
    int Character::getMp(){
        return m_mp;
    }
    int Character::getPrice(Items* item) const {
        return item->getPrice();
    }
    void Character::setHelmet(const Items& helmet){
        m_currHelmet = helmet;
    }
    void Character::setHelmetName(std::string wName){
        m_helmetName = wName;
    }
    std::string Character::getHelmetName(){
        return m_helmetName;
    }
    Items Character::getHelmet(){
        return m_currHelmet;
    }
    void Character::setGloves(const Items& gloves){
        m_currGloves = gloves;
    }
    void Character::setGlovesName(std::string wName){
        m_glovesName = wName;
    }
    std::string Character::getGlovesName(){
        return m_glovesName;
    }
    void Character::setGold(int newGold) {
        m_gold = newGold;
    }
    int Character::getGold() {
        return m_gold;
    }
    Items Character::getGloves(){
        return m_currGloves;
    }
    void Character::setPotion(int potion) {
        m_potions = potion;
    }
    void Character::setBoots(const Items& boots){
        m_currBoots = boots;
    }
    void Character::setBootsName(std::string wName){
        m_bootsName = wName;
    }
    std::string Character::getBootsName(){
        return m_bootsName;
    }
    Items Character::getBoots(){
        return m_currBoots;
    }
    void Character::setHolder(const Items& holder) {
        m_currHolder = holder;
    }
    Items Character::getHolder() {
        return m_currHolder;
    }
    void Character::weaponChar(int choice) {
        if(choice == 0) {
            m_character.erase(m_character.begin());
            m_character.insert(m_character.begin(), getWeapon());
        }else if(choice == 1){
            m_inventory.push_back(getHolder());
        }
    }
    void Character::armorChar(int choice) {
        if(choice == 0) {
            m_character.erase(m_character.begin()+2);
            m_character.insert(m_character.begin()+2, getArmor());
        }else if(choice == 1){
            m_inventory.push_back(getHolder());
        }
    }
    int Character::setMpRecovery(int mpRecovery) {
        m_mpRecovery = mpRecovery;
    }
    int Character::setHpRecovery(int hpRecovery) {
        m_hpRecovery = hpRecovery;
    }
        int Character::getMpRecovery() {
        return m_mpRecovery + m_currHelmet.getMpRecovery() + m_currArmor.getMpRecovery() + m_currGloves.getMpRecovery() + m_currBoots.getMpRecovery();
    }
    int Character::getHpRecovery() {
        return m_hpRecovery + m_currHelmet.getHpRecovery() + m_currArmor.getHpRecovery() + m_currGloves.getHpRecovery() + m_currBoots.getHpRecovery();
    }
    void Character::helmetChar(int choice) {
        if(choice == 0) {
            m_character.erase(m_character.begin()+1);
            m_character.insert(m_character.begin()+1, getHelmet());
    }else if(choice == 1){
            m_inventory.push_back(getHolder());
        }
    }
    void Character::glovesChar(int choice) {
        if(choice == 0) {
            m_character.erase(m_character.begin()+3);
            m_character.insert(m_character.begin()+3, getGloves());
    }else if(choice == 1){
            m_inventory.push_back(getHolder());
        }
    }
    void Character::bootsChar(int choice){
        if(choice == 0) {
            m_character.erase(m_character.begin()+4);
            m_character.insert(m_character.begin()+4, getBoots());
    }else if(choice == 1){
            m_inventory.push_back(getHolder());
        }
    }
    void Character::itemsChar() {
        m_character.insert(m_character.begin(), m_currWeapon);
        m_character.insert(m_character.begin()+1, m_currHelmet);
        m_character.insert(m_character.begin()+2, m_currArmor);
        m_character.insert(m_character.begin()+3, m_currGloves);
        m_character.insert(m_character.begin()+4, m_currBoots);
    }
    int Character::getIntelligence() {
        return m_intelligence;
    }
    int Character::setMp(int mp) {
        m_mp = mp;
    }
    void Character::chooseWeapon(Character* character){
    bool running = true;
    while(running) {
        Items *item = new Items(0, 0, 0, 0, 0, 0, "",0,0);
        Weapon *weapon = dynamic_cast<Weapon *>(item);
        Armor *armor = dynamic_cast<Armor *>(item);
        Helmet *helm = dynamic_cast<Helmet *>(item);
        Gloves *glove = dynamic_cast<Gloves *>(item);
        Boots *boot = dynamic_cast<Boots *>(item);

        std::vector<Weapon> m_weapons;
        std::vector<Armor> m_armors;
        std::vector<Helmet> m_helmets;
        std::vector<Gloves> m_gloves;
        std::vector<Boots> m_boots;

        size_t choice;
        std::string weaponName;
        std::string armorName;
        std::string helmetName;
        std::string glovesName;
        std::string bootsName;
        bool again;
        if (running) {
            again = false;
        }
        int n = 0;
        int choiceForSection;
        int back = 0;

        line();
        std::cout << std::endl;
        std::cout << "Shop window: " << std::endl;
        std::cout << "What do you wish to buy? " << std::endl;
        std::cout << std::endl;
        std::cout << n << ". Weapon" << std::endl;
        std::cout << n + 1 << ". Armor" << std::endl;
        std::cout << n + 2 << ". Helmet" << std::endl;
        std::cout << n + 3 << ". Gloves" << std::endl;
        std::cout << n + 4 << ". Boots" << std::endl;
        std::cout << std::endl;
        std::cout << n + 5 << ". Leave" << std::endl;
        std::cin >> choiceForSection;
        if (std::cin.fail()) {
            std::cout << "You must enter a number!!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        } else {


            // WEAPONS
            m_weapons.push_back(Weapon(10, 0, 0, 15, 0, 0, "Silver Sword",1,1));
            m_weapons.push_back(Weapon(25, 0, 0, 25, 0, 0, "Night's Edge",15,1));
            m_weapons.push_back(Weapon(50, 0, 0, 38, 0, 0, "Silent Spellblade",35,1));
            m_weapons.push_back(Weapon(90, 0, 0, 50, 0, 0, "Frost Razor",50,1));
            m_weapons.push_back(Weapon(120, 0, 10, 90, 0, 0, "Stormbringer, Breaker of Invocation",100,1));
            m_weapons.push_back(Weapon(180, 0, 5, 150, 0, 0, "Doomblade",160,1));
            m_weapons.push_back(Weapon(380, 0, 20, 300, 0, 0, "Dark Heart, Breaker of Lost Worlds",300,1));
            m_weapons.push_back(Weapon(800, 0, 50, 999, 0, 0, "Hellfire, Betrayer of Ended Dreams",500,1));
            m_weapons.push_back(Weapon(1000, 0, 200, 999, 0, 0, "God Slayer, Breaker of Heavens",1000,1));
            m_weapons.push_back(Weapon(3000, 0, 200, 999, 0, 0, "For Test Purpose",0,1));

            if (choiceForSection == 0) {
                while (!again) {
                    line();
                    std::cout << std::endl;
                    std::cout << "Which weapon do you want to buy? \n";
                    std::cout << std::endl;
                    for (size_t i = 0; i < m_weapons.size(); ++i) {
                        std::cout << std::setw(1) << std::left << i << std::setw(1) << std::left << ". " << std::setw(40) << std::left<< m_weapons[i].getName();
                        std::cout << std::setw(5) << std::right << m_weapons[i].getPrice() << " golds" << "\n";
                        if (i + 1 == m_weapons.size()) {
                            std::cout << std::endl;
                            std::cout << i + 1 << ". Back" << std::endl;
                            back = i + 1;
                        }
                    }
                    std::cin >> choice;
                    line();
                    std::cout << std::endl;
                    if (std::cin.fail()) {
                        std::cout << "You must enter a number!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                    } else if (choice == back) {
                        again = true;
                    } else {
                        if (choice < m_weapons.size() && m_weapons[choice].getPrice() <= character->getGold()) {
                            std::string yesOrNo;
                            std::cout << "Are you sure? Press y(yes) or n(no). " << std::endl;
                            std::cin >> yesOrNo;
                            yesOrNo[0] = std::toupper(yesOrNo[0]);
                            if (yesOrNo == "Y" && m_weapons[choice].getPrice() <= character->getGold()) {
                                yesOrNo = "";
                                std::cout << "Purchase was successful.";
                                character->setGold(character->getGold() - m_weapons[choice].getPrice());
                                std::cout << " Do you want to equip it? Press y(yes) or n(no)." << std::endl;
                                std::cin >> yesOrNo;
                                yesOrNo[0] = std::toupper(yesOrNo[0]);
                                if (yesOrNo == "Y") {
                                    character->setWeapon(m_weapons[choice]);
                                    weaponName = m_weapons[choice].getName();
                                    character->setWeaponName(weaponName);
                                    character->weaponChar(0);
                                    again = true;
                                } else {
                                    character->setHolder(m_weapons[choice]);
                                    character->weaponChar(1);
                                    again = true;
                                }
                            } else if (yesOrNo == "N") {
                                std::cout << "Purchase canceled." << std::endl;
                                again = true;
                            } else {
                                std::cout << "Wrong input!!" << std::endl;
                            }
                        }else if(m_weapons[choice].getPrice() > character->getGold()){
                                std::cout << "You do not have enough gold." << std::endl;
                        } else {
                            std::cout << "Wrong input!!";
                        }
                    }
                }
                again = false;
            } else if (choiceForSection == 1) {

                m_armors.push_back(Armor(0, 10, 0, 20, 0, 0, "Silver Armor",5,2));
                m_armors.push_back(Armor(0, 20, 0, 40, 0, 0, "Plate Armor",10,2));
                m_armors.push_back(Armor(0, 30, 0, 80, 0, 5, "Obsidian Armor",55,2));
                m_armors.push_back(Armor(0, 70, 0, 100, 10, 15, "Adamantite Armor",105,2));
                m_armors.push_back(Armor(0, 100, 0, 150, 30, 50, "Armor of Distant Powers",180,2));
                m_armors.push_back(Armor(0, 150, 0, 400, 80, 200, "Glory Armor of Pride's Fall",350,2));

                while (!again) {
                    line();
                    std::cout << std::endl;
                    std::cout << "Which armor do you want to buy? \n";
                    std::cout << std::endl;
                    for (size_t i = 0; i < m_armors.size(); ++i) {
                        std::cout << std::setw(1) << std::left << i << std::setw(1) << std::left << ". " << std::setw(40) << std::left<< m_armors[i].getName();
                        std::cout << std::setw(5) << std::right << m_armors[i].getPrice() << " golds" << "\n";
                        if (i + 1 == m_armors.size()) {
                            std::cout << std::endl;
                            std::cout << i + 1 << ". Back" << std::endl;
                            back = i + 1;
                        }
                    }
                    std::cin >> choice;
                    line();
                    std::cout << std::endl;
                    if (std::cin.fail()) {
                        std::cout << "You must enter a number!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                    } else if (choice == back) {
                        again = true;
                    } else {
                        if (choice < m_armors.size() && m_armors[choice].getPrice() <= character->getGold()) {
                            std::string yesOrNo;
                            std::cout << "Are you sure? Press y(yes) or n(no). " << std::endl;
                            std::cin >> yesOrNo;
                            yesOrNo[0] = std::toupper(yesOrNo[0]);
                            if (yesOrNo == "Y" && m_armors[choice].getPrice() <= character->getGold()) {
                                yesOrNo = "";
                                std::cout << "Purchase was successful.";
                                character->setGold(character->getGold() - m_armors[choice].getPrice());
                                std::cout << " Do you want to equip it? Press y(yes) or n(no)." << std::endl;
                                std::cin >> yesOrNo;
                                yesOrNo[0] = std::toupper(yesOrNo[0]);
                                if (yesOrNo == "Y") {
                                    character->setArmor(m_armors[choice]);
                                    armorName = m_armors[choice].getName();
                                    character->setArmorName(armorName);
                                    character->armorChar(0);
                                    again = true;
                                } else {
                                    character->setHolder(m_armors[choice]);
                                    character->armorChar(1);
                                    again = true;
                                }
                            } else if (yesOrNo == "N") {
                                std::cout << "Purchase canceled." << std::endl;
                                again = true;
                            } else {
                                std::cout << "Wrong input!!" << std::endl;
                            }
                        }else if(m_armors[choice].getPrice() > character->getGold()){
                            std::cout << "You do not have enough gold." << std::endl;
                        } else {
                            std::cout << "Wrong input!!";
                        }
                    }
                }
                again = false;
            } else if (choiceForSection == 2) {

                m_helmets.push_back(Helmet(0, 10, 0, 20, 0, 0, "Silver Helmet",5,3));
                m_helmets.push_back(Helmet(0, 30, 0, 30, 0, 5, "Obsidian Helmet",30,3));
                m_helmets.push_back(Helmet(0, 50, 0, 100, 10, 15, "Adamantite Helmet",80,3));

                while (!again) {
                    line();
                    std::cout << std::endl;
                    std::cout << "Which helmet do you want to buy? \n";
                    std::cout << std::endl;
                    for (size_t i = 0; i < m_helmets.size(); ++i) {
                        std::cout << std::setw(1) << std::left << i << std::setw(1) << std::left << ". " << std::setw(25) << std::left<< m_helmets[i].getName();
                        std::cout << std::setw(5) << std::right << m_helmets[i].getPrice() << " golds" << "\n";
                        if (i + 1 == m_helmets.size()) {
                            std::cout << std::endl;
                            std::cout << i + 1 << ". Back" << std::endl;
                            back = i + 1;
                        }
                    }
                    std::cin >> choice;
                    line();
                    std::cout << std::endl;
                    if (std::cin.fail()) {
                        std::cout << "You must enter a number!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                    } else if (choice == back) {
                        again = true;
                    } else {
                        if (choice < m_helmets.size() && m_helmets[choice].getPrice() <= character->getGold()) {
                            std::string yesOrNo;
                            std::cout << "Are you sure? Press y(yes) or n(no). " << std::endl;
                            std::cin >> yesOrNo;;
                            yesOrNo[0] = std::toupper(yesOrNo[0]);
                            if (yesOrNo == "Y") {
                                yesOrNo = "";
                                std::cout << "Purchase was successful.";
                                character->setGold(character->getGold() - m_helmets[choice].getPrice());
                                std::cout << " Do you want to equip it? Press y(yes) or n(no)." << std::endl;
                                std::cin >> yesOrNo;
                                yesOrNo[0] = std::toupper(yesOrNo[0]);
                                if (yesOrNo == "Y") {
                                    character->setHelmet(m_helmets[choice]);
                                    helmetName = m_helmets[choice].getName();
                                    character->setHelmetName(helmetName);
                                    character->helmetChar(0);
                                    again = true;
                                } else {
                                    character->setHolder(m_helmets[choice]);
                                    character->helmetChar(1);
                                    again = true;
                                }
                            } else if (yesOrNo == "N") {
                                std::cout << "Purchase canceled." << std::endl;
                                again = true;
                            } else {
                                std::cout << "Wrong input!!" << std::endl;
                            }
                        }else if(m_helmets[choice].getPrice() > character->getGold()){
                            std::cout << "You do not have enough gold." << std::endl;
                        } else {
                            std::cout << "Wrong input!!";
                        }
                    }
                }
                again = false;
            } else if (choiceForSection == 3) {

                m_gloves.push_back(Gloves(0, 10, 0, 20, 0, 0, "Silver Gloves",5,4));
                m_gloves.push_back(Gloves(0, 20, 0, 30, 0, 5, "Obsidian Gloves",30,4));
                m_gloves.push_back(Gloves(0, 50, 0, 100, 10, 15, "Adamantite Gloves",60,4));

                while (!again) {
                    line();
                    std::cout << std::endl;
                    std::cout << "Which gloves do you want to buy? \n";
                    std::cout << std::endl;
                    for (size_t i = 0; i < m_gloves.size(); ++i) {
                        std::cout << std::setw(1) << std::left << i << std::setw(1) << std::left << ". " << std::setw(25) << std::left<< m_gloves[i].getName();
                        std::cout << std::setw(5) << std::right << m_gloves[i].getPrice() << " golds" << "\n";
                        if (i + 1 == m_gloves.size()) {
                            std::cout << std::endl;
                            std::cout << i + 1 << ". Back" << std::endl;
                            back = i + 1;
                        }
                    }
                    std::cin >> choice;
                    line();
                    std::cout << std::endl;
                    if (std::cin.fail()) {
                        std::cout << "You must enter a number!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                    } else if (choice == back) {
                        again = true;
                    } else {
                        if (choice < m_gloves.size() && m_gloves[choice].getPrice() <= character->getGold()) {
                            std::string yesOrNo;
                            std::cout << "Are you sure? Press y(yes) or n(no). " << std::endl;
                            std::cin >> yesOrNo;;
                            yesOrNo[0] = std::toupper(yesOrNo[0]);
                            if (yesOrNo == "Y") {
                                yesOrNo = "";
                                std::cout << "Purchase was successful.";
                                character->setGold(character->getGold() - m_gloves[choice].getPrice());
                                std::cout << " Do you want to equip it? Press y(yes) or n(no)." << std::endl;
                                std::cin >> yesOrNo;
                                yesOrNo[0] = std::toupper(yesOrNo[0]);
                                if (yesOrNo == "Y") {
                                    character->setGloves(m_gloves[choice]);
                                    glovesName = m_gloves[choice].getName();
                                    character->setGlovesName(glovesName);
                                    character->glovesChar(0);
                                    again = true;
                                } else {
                                    character->setHolder(m_gloves[choice]);
                                    character->glovesChar(1);
                                    again = true;
                                }
                            } else if (yesOrNo == "N") {
                                std::cout << "Purchase canceled." << std::endl;
                                again = true;
                            } else {
                                std::cout << "Wrong input!!" << std::endl;
                            }
                        }else if(m_gloves[choice].getPrice() > character->getGold()){
                            std::cout << "You do not have enough gold." << std::endl;
                        } else {
                            std::cout << "Wrong input!!";
                        }
                    }
                }
                again = false;
            } else if (choiceForSection == 4) {

                m_boots.push_back(Boots(0, 10, 0, 20, 0, 0, "Silver Boots",5,5));
                m_boots.push_back(Boots(0, 20, 0, 40, 0, 5, "Obsidian Boots",30,5));
                m_boots.push_back(Boots(0, 50, 0, 80, 10, 15, "Adamantite Boots",70,5));

                while (!again) {
                    line();
                    std::cout << std::endl;
                    std::cout << "Which boots do you want to buy? \n";
                    std::cout << std::endl;
                    for (size_t i = 0; i < m_boots.size(); ++i) {
                        std::cout << std::setw(1) << std::left << i << std::setw(1) << std::left << ". " << std::setw(25) << std::left<< m_boots[i].getName();
                        std::cout << std::setw(5) << std::right << m_boots[i].getPrice() << " golds" << "\n";
                        if (i + 1 == m_boots.size()) {
                            std::cout << std::endl;
                            std::cout << i + 1 << ". Back" << std::endl;
                            back = i + 1;
                        }
                    }
                    std::cin >> choice;
                    line();
                    std::cout << std::endl;
                    if (std::cin.fail()) {
                        std::cout << "You must enter a number!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                    } else if (choice == back) {
                        again = true;
                    } else {
                        if (choice < m_boots.size() && m_boots[choice].getPrice() <= character->getGold()) {
                            std::string yesOrNo;
                            std::cout << "Are you sure? Press y(yes) or n(no). " << std::endl;
                            std::cin >> yesOrNo;;
                            yesOrNo[0] = std::toupper(yesOrNo[0]);
                            if (yesOrNo == "Y") {
                                yesOrNo = "";
                                std::cout << "Purchase was successful.";
                                character->setGold(character->getGold() - m_boots[choice].getPrice());
                                std::cout << " Do you want to equip it? Press y(yes) or n(no)." << std::endl;
                                std::cin >> yesOrNo;
                                yesOrNo[0] = std::toupper(yesOrNo[0]);
                                if (yesOrNo == "Y") {
                                    character->setBoots(m_boots[choice]);
                                    bootsName = m_boots[choice].getName();
                                    character->setBootsName(bootsName);
                                    character->bootsChar(0);
                                    again = true;
                                } else {
                                    character->setHolder(m_boots[choice]);
                                    character->bootsChar(1);
                                    again = true;
                                }
                            } else if (yesOrNo == "N") {
                                std::cout << "Purchase canceled." << std::endl;
                                again = true;
                            } else {
                                std::cout << "Wrong input!!" << std::endl;
                            }
                        }else if(m_boots[choice].getPrice() > character->getGold()){
                            std::cout << "You do not have enough gold." << std::endl;
                        } else {
                            std::cout << "Wrong input!!";
                        }
                    }
                }
                again = false;
            } else if (choiceForSection == 5) {
                running = false;
                std::cout << "You left the shop." << std::endl;
            } else {
                std::cout << "Wrong input!!" << std::endl;
            }
        }
    }
};
