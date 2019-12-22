//
// Created by Lenovo on 14.12.2019.
//

#include "Character.h"
#include "Weapon.h"
#include "Armor.h"

Character::Character() : m_currWeapon(5,0,0,0, "Fists"), m_currArmor(0,0,0,0,""){
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
        const char separator = ' ';
        const int nameWidth = 15;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Inventory window: " << std::endl;
        for (int i = 0; i < m_inventory.size(); i++) {
            /*   if (m_inventory[i] != nullptr) {
                   std::cout << m_inventory[i] << std::endl;
               } else {
                   std::cout << "----Empty----" << std::endl;
               }
           }*/
            std::cout << std::endl;
            std::cout << "Gold/s: " << m_gold << std::endl;
        }
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
        m_character.reserve(10);
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
        return m_def + m_currArmor.getDefense();
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
    void Character::weapChar() {
        m_character.push_back(getWeapon());
        m_character.push_back(getArmor());
    }
    void Character::chooseWeapon(Character* character){
    Items* item = new Items(0, 0, 0, 0, "");
    Weapon* weapon = dynamic_cast<Weapon*>(item);
    Armor* armor = dynamic_cast<Armor*>(item);
    std::vector<Weapon> m_weapons;

    m_weapons.push_back(Weapon(10,0,0,15,"Bronze Sword"));
    m_weapons.push_back(Weapon(20,0,0, 20, "Silver Sword"));
    m_weapons.push_back(Weapon(50,0,0,30, "Sword of Justice"));
    m_weapons.push_back(Weapon(80,0,0,50, "Excalibur"));
    m_weapons.push_back(Weapon(110,0,0,70, "Hellbringer"));
    m_weapons.push_back(Weapon(150,0,0,100, "Heaven's Wish"));

    std::cout << "Choose a weapon: \n";
    for (size_t i = 0; i < m_weapons.size(); ++i) {
        std::cout << i << ". " << m_weapons[i].getName() << "\n";
    }
    std::vector<Armor> m_armors;

    m_armors.push_back(Armor(0,10,0,20, "Knight's armor"));
    m_armors.push_back(Armor(0,20,0,40, "King's armor"));
    m_armors.push_back(Armor(0,50,0,100, "Emperor's armor"));

    std::cout << "Choose an armor: \n";
    for (size_t i = 0; i < m_armors.size(); ++i) {
        std::cout << i << ". " << m_armors[i].getName() << "\n";
    }

    size_t choice;
    std::string weaponName;
    std::string armorName;
    std::cin >> choice;
    character->setWeapon(m_weapons[choice]);
    weaponName = m_weapons[choice].getName();
    character->setWeaponName(weaponName);
    character->weapChar();
    std::cin >> choice;
    character->setArmor(m_armors[choice]);
    armorName = m_armors[choice].getName();
    character->setArmorName(armorName);
    character->weapChar();
};
