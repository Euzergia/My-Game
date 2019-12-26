//
// Created by Lenovo on 14.12.2019.
//

#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"
#include "Boots.h"
#include "Gloves.h"

Character::Character() : m_currWeapon(5,0,0,0, "Fists"), m_currArmor(0,0,0,0,""), m_currHelmet(0,0,0,0,""), m_currGloves(0,0,0,0,""), m_currBoots(0,0,0,0,""){
        std::srand(time(nullptr));
        m_strength = std::rand () % 11;
        m_agility = std::rand () % 11;
        m_vitality = std::rand () % 11;
        m_intelligence = std::rand () % 11;
        m_name = "";
        m_lvl = 1;
        m_exp = 0;
        m_expLimit = 1000;
        m_dmg = m_strength * m_strength;
        m_def = 0;
        m_hp = m_vitality * m_vitality;
        m_mp = m_intelligence * m_intelligence;
        m_gold = 0;
    }
    void Character::showStats() {
        const char separator = ' ';
        const int nameWidth = 15;
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
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Vitality: ";
        std::cout << m_vitality << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Intelligence: ";
        std::cout << m_intelligence << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Strength: ";
        std::cout << m_strength << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Agility: ";
        std::cout << m_agility << std::endl;

    }
    void Character::showInventory() {
        m_inventory.resize(10);
        const char separator = ' ';
        const int nameWidth = 15;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Inventory window: " << std::endl;
        for (int i = 0; i < m_inventory.size(); ++i) {
            if (m_inventory[i] != nullptr) {
                   std::cout << m_inventory[i]->getName() << std::endl;
               } else {
                   std::cout << "----Empty----" << std::endl;
               }
           }
            std::cout << std::endl;
            std::cout << "Gold/s: " << m_gold << std::endl;
        }
    void Character::showHelp() {
        const char separator = ' ';
        const int nameWidth = 15;
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
    }
    void Character::showChar() {
        const char separator = ' ';
        const int nameWidth = 15;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Character window: " << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Sword: ";
        std::cout << m_character[0].getName() << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Helmet: ";
        std::cout << m_character[1].getName() << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Armor: ";
        std::cout << m_character[2].getName() << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Gloves: ";
        std::cout << m_character[3].getName() << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Boots: ";
        std::cout << m_character[4].getName() << std::endl;

    }
    void Character::setName(){
        std::string name;
        std::cout << "Enter your nickname: \n";
        std::cin >> name;
        m_name = name;
    }
    std::string Character::getName(){
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
    int Character::getDamage() const {
        return m_dmg + m_currWeapon.getDamage();
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
    Items Character::getGloves(){
        return m_currGloves;
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
    void Character::itemChar() {
        m_character.push_back(getWeapon());
        m_character.push_back(getHelmet());
        m_character.push_back(getArmor());
        m_character.push_back(getGloves());
        m_character.push_back(getBoots());
    }
    void Character::chooseWeapon(Character* character){
    Items* item = new Items(0, 0, 0, 0, "");
    Weapon* weapon = dynamic_cast<Weapon*>(item);
    Armor* armor = dynamic_cast<Armor*>(item);
    Helmet* helm = dynamic_cast<Helmet*>(item);
    Gloves* glove = dynamic_cast<Gloves*>(item);
    Boots* boot = dynamic_cast<Boots*>(item);

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
    bool again = false;

    std::cout << "Choose your equipment: " << std::endl;
    std::cout << std::endl;

    m_weapons.push_back(Weapon(10,0,0,15,"Bronze Sword"));
    m_weapons.push_back(Weapon(80,0,0,50, "Excalibur"));
    m_weapons.push_back(Weapon(150,0,0,100, "Heaven's Wish"));
    m_weapons.push_back(Weapon(5000,0,0,5000, "God's Power"));

    while(!again) {
        std::cout << "Choose a weapon: \n";
        for (size_t i = 0; i < m_weapons.size(); ++i) {
            std::cout << i << ". " << m_weapons[i].getName() << "\n";
        }
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cout << "You must enter a number!!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }else {
            if (choice < m_weapons.size()) {
                character->setWeapon(m_weapons[choice]);
                weaponName = m_weapons[choice].getName();
                character->setWeaponName(weaponName);
                again = true;
            } else {
                std::cout << "Wrong input!!";
            }
            std::cout << std::endl;
        }
    }
    again = false;

    m_armors.push_back(Armor(0,10,0,20, "Knight's armor"));
    m_armors.push_back(Armor(0,20,0,40, "King's armor"));
    m_armors.push_back(Armor(0,50,0,100, "Emperor's armor"));

    while(!again) {
        std::cout << "Choose an armor: \n";
        for (size_t i = 0; i < m_armors.size(); ++i) {
            std::cout << i << ". " << m_armors[i].getName() << "\n";
        }
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cout << "You must enter a number!!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }else {
            if (choice < m_armors.size()) {
                character->setArmor(m_armors[choice]);
                armorName = m_armors[choice].getName();
                character->setArmorName(armorName);
                again = true;
            } else {
                std::cout << "Wrong input!!";
            }
            std::cout << std::endl;
        }
    }
    again = false;

    m_helmets.push_back(Helmet(0,10,0,20, "Bronze helmet"));
    m_helmets.push_back(Helmet(0,20,0,40, "Helmet of justice"));
    m_helmets.push_back(Helmet(0,50,0,100, "Emperor's helmet"));

        while(!again) {
            std::cout << "Choose a helmet: \n";
            for (size_t i = 0; i < m_helmets.size(); ++i) {
                std::cout << i << ". " << m_helmets[i].getName() << "\n";
            }
            std::cin >> choice;
            if(std::cin.fail()) {
                std::cout << "You must enter a number!!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }else {
                if (choice < m_helmets.size()) {
                    character->setHelmet(m_helmets[choice]);
                    helmetName = m_helmets[choice].getName();
                    character->setHelmetName(helmetName);
                    again = true;
                } else {
                    std::cout << "Wrong input!!";
                }
                std::cout << std::endl;
            }
        }
    again = false;

    m_gloves.push_back(Gloves(0,10,0,20, "Bronze gloves"));
    m_gloves.push_back(Gloves(0,20,0,40, "Silver gloves"));
    m_gloves.push_back(Gloves(0,50,0,100, "Emperor's gloves"));

    while(!again) {
        std::cout << "Choose gloves: \n";
        for (size_t i = 0; i < m_gloves.size(); ++i) {
            std::cout << i << ". " << m_gloves[i].getName() << "\n";
        }
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cout << "You must enter a number!!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }else {
            if (choice < m_gloves.size()) {
                character->setGloves(m_gloves[choice]);
                glovesName = m_gloves[choice].getName();
                character->setGlovesName(glovesName);
                again = true;
            } else {
                std::cout << "Wrong input!!";
            }
            std::cout << std::endl;
        }
    }
    again = false;

    m_boots.push_back(Boots(0,10,0,20, "Bronze boots"));
    m_boots.push_back(Boots(0,20,0,40, "Random boots"));
    m_boots.push_back(Boots(0,50,0,100, "Emperor's boots"));

    while(!again) {
        std::cout << "Choose boots: \n";
        for (size_t i = 0; i < m_boots.size(); ++i) {
            std::cout << i << ". " << m_boots[i].getName() << "\n";
        }
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cout << "You must enter a number!!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }else {
            if (choice < m_boots.size()) {
                character->setBoots(m_boots[choice]);
                bootsName = m_boots[choice].getName();
                character->setBootsName(bootsName);
                character->itemChar();
                again = true;
            } else {
                std::cout << "Wrong input!!";
            }
            std::cout << std::endl;
        }
    }
};
