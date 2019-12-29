//
// Created by Lenovo on 14.12.2019.
//

#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"
#include "Boots.h"
#include "Gloves.h"

Character::Character() : m_currWeapon(5,0,0,0, "Fists",0), m_currArmor(0,0,0,0,"",0), m_currHelmet(0,0,0,0,"",0), m_currGloves(0,0,0,0,"",0), m_currBoots(0,0,0,0,"",0), m_currHolder(0,0,0,0,"",0){
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
        m_gold = 10;
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
    m_inventory.reserve(10);
        const char separator = ' ';
        const int nameWidth = 15;
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Inventory window: " << std::endl;
        for (int i = 0; i < m_inventory.size(); ++i) {
                std::cout << i << ". " << m_inventory[i].getName() << std::endl;
        }
            std::cout << std::endl;
            std::cout << "Gold/s: " << m_gold << std::endl;
            std::cout << "Slots used: " << m_inventory.size() << "/" << m_inventory.capacity() << std::endl;
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
        std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Weapon: ";
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
    void Character::reward() {
    srand(time(0));
        int reward = rand() % 5;
        m_gold += reward;
        std::cout << "You acquired this amount of gold: " << reward << std::endl;
        std::cout << "You acquired these items: " << std::endl;
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
    void Character::chooseWeapon(Character* character){
    bool running = true;
    while(running) {
        Items *item = new Items(0, 0, 0, 0, "",0);
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

        std::cout << std::endl;
        std::cout << "Shop window: " << std::endl;
        std::cout << "What do you wish to buy? " << std::endl;
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
            m_weapons.push_back(Weapon(10, 0, 0, 15, "Bronze Sword",2));
            m_weapons.push_back(Weapon(80, 0, 0, 50, "Excalibur",50));
            m_weapons.push_back(Weapon(150, 0, 0, 100, "Heaven's Wish",100));
            m_weapons.push_back(Weapon(5000, 0, 0, 5000, "God's Power",1000));

            if (choiceForSection == 0) {
                while (!again) {
                    std::cout << "Which weapon do you want to buy? \n";
                    for (size_t i = 0; i < m_weapons.size(); ++i) {
                        std::cout << std::setw(1) << std::left << i << std::setw(1) << std::left << ". " << std::setw(25) << std::left<< m_weapons[i].getName();
                        std::cout << std::setw(5) << std::right << m_weapons[i].getPrice() << " golds" << "\n";
                        if (i + 1 == m_weapons.size()) {
                            std::cout << std::endl;
                            std::cout << i + 1 << ". Back" << std::endl;
                            back = i + 1;
                        }
                    }
                    std::cin >> choice;
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

                m_armors.push_back(Armor(0, 10, 0, 20, "Knight's armor",2));
                m_armors.push_back(Armor(0, 20, 0, 40, "King's armor",10));
                m_armors.push_back(Armor(0, 50, 0, 100, "Emperor's armor",15));

                while (!again) {
                    std::cout << "Which armor do you want to buy? \n";
                    for (size_t i = 0; i < m_armors.size(); ++i) {
                        std::cout << std::setw(1) << std::left << i << std::setw(1) << std::left << ". " << std::setw(25) << std::left<< m_armors[i].getName();
                        std::cout << std::setw(5) << std::right << m_armors[i].getPrice() << " golds" << "\n";
                        if (i + 1 == m_armors.size()) {
                            std::cout << std::endl;
                            std::cout << i + 1 << ". Back" << std::endl;
                            back = i + 1;
                        }
                    }
                    std::cin >> choice;
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

                m_helmets.push_back(Helmet(0, 10, 0, 20, "Bronze helmet",2));
                m_helmets.push_back(Helmet(0, 20, 0, 40, "Helmet of justice",5));
                m_helmets.push_back(Helmet(0, 50, 0, 100, "Emperor's helmet",15));

                while (!again) {
                    std::cout << "Which helmet do you want to buy? \n";
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

                m_gloves.push_back(Gloves(0, 10, 0, 20, "Bronze gloves",2));
                m_gloves.push_back(Gloves(0, 20, 0, 40, "Silver gloves",8));
                m_gloves.push_back(Gloves(0, 50, 0, 100, "Emperor's gloves",15));

                while (!again) {
                    std::cout << "Which gloves do you want to buy? \n";
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

                m_boots.push_back(Boots(0, 10, 0, 20, "Bronze boots",2));
                m_boots.push_back(Boots(0, 20, 0, 40, "Random boots",5));
                m_boots.push_back(Boots(0, 50, 0, 100, "Emperor's boots",15));

                while (!again) {
                    std::cout << "Which boots do you want to buy? \n";
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
