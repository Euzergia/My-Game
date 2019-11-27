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

public:
    Character() : m_currWeapon(0, "Fists"){
        std::srand(time(nullptr));
        m_hp = m_vitality * m_vitality;
        m_mp = m_intelligence * m_intelligence;
        m_strength = std::rand () % 11;
        m_agility = std::rand () % 11;
        m_vitality = std::rand () % 11;
        m_intelligence = std::rand () % 11;
        m_dmg = m_strength * m_strength;
    }
    void setWeapon(const Weapon& weapon) {
        m_currWeapon = weapon;
    }
    int getDamage() const {
        return m_dmg + m_currWeapon.getDamage();
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
        std::cin >> choice;
        character->setWeapon(m_weapons[choice]);
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
        m_hp = m_vitality * m_vitality;
        m_mp = m_intelligence * m_intelligence;
        m_strength = std::rand () % 21;
        m_agility = std::rand () % 21;
        m_vitality = std::rand () % 21;
        m_intelligence = std::rand () % 21;
    }
};

int main() {
    Character* player = new Character();
    chooseWeapon(player);

    return 0;
}