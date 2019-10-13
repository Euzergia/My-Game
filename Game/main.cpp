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
    int m_speed;
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
        m_speed = (rand()%10)+1;
        m_gold = gold;
        m_silver = silver;
        m_copper = copper;

    }
    void setName(string newName) {
        m_name = newName;
    }
    string getName(){
        return m_name;
    }
    void printInfo(){
        cout << "Vitality: " << m_vitality << endl;
        cout << "Intelligence: " << m_intelligence << endl;
        cout << "Strength: " << m_strength << endl;
        cout << "Speed: " << m_speed << endl;
    }
    void getMoney(){
        cout << m_gold << "g, " << m_silver << "s, " << m_copper << "s" << endl;
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
    cout << "This is how much you have!" << endl;
    newChar->getMoney();
    return 0;
}