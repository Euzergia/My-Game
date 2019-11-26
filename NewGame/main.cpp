#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Player{
private:
    int m_hp;
    int m_mp;
    int m_strength;
    int m_agility;
    int m_vitality;
    int m_intelligence;

public:
    Player(){
        std::srand(time(nullptr));
        m_hp = m_vitality * m_vitality;
        m_mp = m_intelligence * m_intelligence;
        m_strength = std::rand () % 11;
        m_agility = std::rand () % 11;
        m_vitality = std::rand () % 11;
        m_intelligence = std::rand () % 11;
    }
};
class Monster{
private:
    int m_hp;
    int m_mp;
    int m_strength;
    int m_agility;
    int m_vitality;
    int m_intelligence;

public:

};

int main() {

    return 0;
}