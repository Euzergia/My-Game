#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

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
    std::string m_weaponName;

public:
    Character() : m_currWeapon(0, "Fists"){
        std::srand(time(nullptr));
        m_strength = std::rand () % 11;
        m_agility = std::rand () % 11;
        m_vitality = std::rand () % 11;
        m_intelligence = std::rand () % 11;
        m_dmg = m_strength * m_strength;
        m_hp = m_vitality * m_vitality;
        m_mp = m_intelligence * m_intelligence;
    }
    void setWeapon(const Weapon& weapon) {
        m_currWeapon = weapon;
    }
    int getDamage() const {
        return m_dmg + m_currWeapon.getDamage();
    }
    void setName(std::string wname){
        m_weaponName = wname;
    }
    std::string getName(){
        return m_weaponName;
    }
};

static void chooseWeapon(Character* character){
        std::vector<Weapon> m_weapons;

        m_weapons.push_back(Weapon(10, "Bronze Sword"));
        m_weapons.push_back(Weapon(20, "Silver Sword"));
        m_weapons.push_back(Weapon(150, "Sword of Justice"));

        std::cout << "Choose a weapon: \n";
        for (size_t i = 0; i < m_weapons.size(); ++i)
            std::cout << i << ". " << m_weapons[i].getName() << "\n";

        size_t choice;
        std::string weapon;
        std::cin >> choice;
        character->setWeapon(m_weapons[choice]);
        weapon = m_weapons[choice].getName();
        character->setName(weapon);
};

class Monster {
private:
    int m_hp;
    int m_mp;
    int m_strength;
    int m_agility;
    int m_vitality;
    int m_intelligence;

public:
    Monster(){
        std::srand(time(nullptr));
        m_strength = std::rand () % 21;
        m_agility = std::rand () % 21;
        m_vitality = std::rand () % 21;
        m_intelligence = std::rand () % 21;
        m_hp = m_vitality * m_vitality * 3;
        m_mp = m_intelligence * m_intelligence * 3;
    }
    int getRand(){
        return m_vitality;
    }
    int getHp(){
        return m_hp;
    }
};

class Fight {
    std::string input = "";
public:
    int getFight(Monster* monster, Character* character){
        int hp = monster->getHp();
        while(hp > 0) {
            std::cout << "Weapon: " << character->getName() << std::endl;
            std::cout << "Leo " << hp << std::endl;
            std::cin >> input;
            if (input == "a" || input == "A") {
                hp -= character->getDamage();
            }
        }
        std::cout << "Leo " << hp << " is dead.\n";
        return hp;
    }
};

int main() {
    Character* player = new Character();
    Monster* monster = new Monster();
    Fight* fight = new Fight;
    chooseWeapon(player);
    fight->getFight(monster, player);

    return 0;
}