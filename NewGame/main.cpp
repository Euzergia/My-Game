#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <array>

class Weapon {
private:
    int m_dmg;
    std::string m_name;

public:
    Weapon(int dmg, const std::string& name) {
        m_dmg = dmg;
        m_name = name;
    }
    int getDamage() const {
        return m_dmg;
    }
    std::string getName() const {
        return m_name;
    }
};

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
    Character() : m_currWeapon(0, "Fists"){
        std::srand(time(nullptr));
        m_strength = std::rand () % 11;
        m_agility = std::rand () % 11;
        m_vitality = std::rand () % 11;
        m_intelligence = std::rand () % 11;
        m_name = "";
        m_dmg = m_strength * m_strength;
        m_hp = m_vitality * m_vitality;
        m_mp = m_intelligence * m_intelligence;
    }
    void setName(){
        std::string name;
        std::cout << "Enter your nickname: \n";
        std::cin >> name;
        m_name = name;
    }
    std::string getName(){
        return m_name;
    }
    void setWeapon(const Weapon& weapon) {
        m_currWeapon = weapon;
    }
    int getDamage() const {
        return m_dmg + m_currWeapon.getDamage();
    }
    int getBaseDmg(){
        return  m_dmg;
    }
    void setWeaponName(std::string wname){
        m_weaponName = wname;
    }
    std::string getWeaponName(){
        return m_weaponName;
    }
    int getHp(){
        return m_hp;
    }
    int getMp(){
        return m_mp;
    }
};

static void chooseWeapon(Character* character){
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

class Monster {
private:
    int m_hp;
    int m_mp;
    int m_strength;
    int m_agility;
    int m_vitality;
    int m_intelligence;
    std::array<std::string, 5> m_monsterName;
    int m_randIndex;

public:
    Monster(){
        std::srand(time(nullptr));
        m_strength = std::rand () % 21;
        m_agility = std::rand () % 21;
        m_vitality = std::rand () % 21;
        m_intelligence = std::rand () % 21;
        m_hp = m_vitality * m_vitality * 3;
        m_mp = m_intelligence * m_intelligence * 3;
        m_randIndex = rand() % 6;
        m_monsterName = {"Goblin", "Dragon", "Joker", "Evil King", "Wyvern"};
    }
    int setHp(int hp){
        m_hp = hp;
    }
    int getHp(){
        return m_hp;
    }
    std::string getName(){
        return m_monsterName[m_randIndex];
    }
};

class Fight {
    std::string input = "";
public:
    void line(){
        std::cout << "--------------------------\n";
    }
    int getFight(Monster* monster, Character* character){
        int hp = monster->getHp();
        while(hp > 0) {
            std::cout << "Weapon: " << character->getWeaponName() << std::endl;
            std::cout << monster->getName() << " " << hp << std::endl;
            std::cin >> input;
            if (input == "a" || input == "A"){
                hp -= character->getDamage();
                std::cout << "Name: " << character->getName() << std::endl;
                std::cout << "HP: " << character->getHp() << std::endl;
                std::cout << "MP: " << character->getMp() << std::endl;
                std::cout << "Dmg: " << character->getDamage() << std::endl;
                std::cout << "Base Dmg: " << character->getBaseDmg() << std::endl;
            }
        }
        if(hp < 0){
            std::cout << monster->getName() << " " << hp << " is dead.\n";
            std::cout << "Overkill!!\n";
            monster->setHp(hp);
        }else {
            std::cout << monster->getName() << " " << hp << " is dead.\n";
            monster->setHp(hp);
        }
        line();

        return hp;
    }
};

int main() {
    bool again = false;
    std::string input;
    std::string playerName;
    Character* player = new Character();
    Monster* monster = new Monster();
    Fight* fight = new Fight;
    player->setName();
    chooseWeapon(player);
    fight->getFight(monster, player);
    delete monster;
    std::cout << "Do you want to fight another monster??\n" << "A: Yes\n" << "B: No\n";
    std::cin >> input;
    if(input == "a" || input == "A"){
        again = true;
        while(again){
            Monster* monster = new Monster();
            while(monster->getHp() > 0){
                fight->getFight(monster, player);
            }
            delete monster;
            std::cout << "Do you want to fight another monster??\n" << "A: Yes\n" << "B: No\n";
            std::cin >> input;
            if(input == "b" || input == "B"){
                again = false;
            }
        }
    }else {
        std::cout << "The game has ended.\n";
    }

    delete player;
    delete monster;
    delete fight;

    return 0;
}