//
// Created by Lenovo on 14.12.2019.
//

#include "Character.h"

    Character::Character() : m_currWeapon(0, "Fists"){
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
        const char separator = ' ';
        const int nameWidth = 15;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Inventory window: " << std:: endl;
        m_inventory.resize(10);
        for (int i = 0; i < m_inventory.size(); i++) {
            if (m_inventory[i] != nullptr) {
                std::cout << m_inventory[i] << std::endl;
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
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "shows your status window " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "char ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "shows your character window " << std:: endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "inv ";
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "shows your inventory window " << std:: endl;
    }
    void Character::showChar() {
        m_character.resize(5);
        const char separator = ' ';
        const int nameWidth = 15;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Character window: " << std::endl;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Sword: ";
        if(!m_character.empty()) {
            std::cout << m_character[0] << std::endl;
        }else{
            std::cout << "----empty----" << std::endl;
        }
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Helmet: ";
        if(m_character[1] != nullptr) {
            std::cout << m_character[1] << std::endl;
        }else{
            std::cout << "----empty----" << std::endl;
        }
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Armor: ";
        if(m_character[2] != nullptr) {
            std::cout << m_character[2] << std::endl;
        }else{
            std::cout << "----empty----" << std::endl;
        }
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Gloves: ";
        if(m_character[3] != nullptr) {
            std::cout << m_character[3] << std::endl;
        }else{
            std::cout << "----empty----" << std::endl;
        }
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Boots: ";
        if(m_character[4] != nullptr) {
            std::cout << m_character[4] << std::endl;
        }else{
            std::cout << "----empty----" << std::endl;
        }
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
    void Character::setWeapon(const Weapon& weapon) {
        m_currWeapon = weapon;
    }

    int Character::getDamage() const {
        return m_dmg + m_currWeapon.getDamage();
    }
    int Character::getBaseDmg(){
        return  m_dmg;
    }
    void Character::setWeaponName(std::string wName){
        m_weaponName = wName;
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
    void Character::chooseWeapon(Character* character){
    std::vector<Weapon> m_weapons;

    m_weapons.push_back(Weapon(10, "Bronze Sword"));
    m_weapons.push_back(Weapon(20, "Silver Sword"));
    m_weapons.push_back(Weapon(50, "Sword of Justice"));
    m_weapons.push_back(Weapon(80, "Excalibur"));
    m_weapons.push_back(Weapon(110, "Hellbringer"));
    m_weapons.push_back(Weapon(150, "Heaven's Wish"));

    std::cout << "Choose a weapon: \n";
    for (size_t i = 0; i < m_weapons.size(); ++i)
        std::cout << i << ". " << m_weapons[i].getName() << "\n";

    size_t choice;
    std::string weapon;
    std::cin >> choice;
    character->setWeapon(m_weapons[choice]);
    weapon = m_weapons[choice].getName();
    character->setWeaponName(weapon);
};
