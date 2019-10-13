#include <iostream>
#include <ctime>
#include <random>

using namespace std;

class Character{
private:
    string m_name;
    int m_vitality;
    int m_intelligence;
    int m_strength;
    int m_agility;
    int m_gold;
    int m_silver;
    int m_copper;
public:
    Character(int gold, int silver, int copper){
        srand((unsigned)time(0));

            m_name = "";
            m_vitality = (rand()%10)+1;
            m_intelligence = (rand()%10)+1;
            m_strength = (rand()%10)+1;
            m_agility = (rand()%10)+1;
            m_gold = gold;
            m_silver = silver;
            m_copper = copper;


    }
    void setGodMode(){
        if (m_name == "God"){
            m_strength += 100;
            m_intelligence += 100;
            m_vitality += 100;
            m_agility += 100;
            m_gold = 999999;
        }
    }
    void setName(string newName) {
        m_name = newName;
        setGodMode();
    }
    string getName(){
        return m_name;
    }
    void printInfo(){
        cout << "Vitality: " << m_vitality << endl;
        cout << "Intelligence: " << m_intelligence << endl;
        cout << "Strength: " << m_strength << endl;
        cout << "Agility: " << m_agility << endl;
    }
    void getMoney(){
        cout << m_gold << " gold/s, " << m_silver << " silver/s, " << m_copper << " copper/s" << endl;
    }
};

int main() {
    string name;
    Character* newChar = new Character(0,0,0);
    cout << "Enter your name: ";
    getline(cin,name);
    newChar->setName(name);

    cout << "Welcome to the game, " << newChar->getName() << '!' << endl;
    cout << "These are your base stats!" << endl;
    newChar->printInfo();
    cout << "You have this much money!" << endl;
    newChar->getMoney();
    return 0;
}