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
    int m_adv = 0;
    string m_start;
    string m_continue;
public:
    // Constructor
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

    // God mode
    void setGodMode(){
        if (m_name == "God"){
            m_strength += 100;
            m_intelligence += 100;
            m_vitality += 100;
            m_agility += 100;
            m_gold = 999999;
        }
    }

    // Player's name
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

    // Money
    void getMoney(){
        cout << m_gold << " gold/s, " << m_silver << " silver/s, " << m_copper << " copper/s" << endl;
    }

    // set Start for the adventure
    void setStart(string start){
        m_start = start;
    }

    // Set continue
    void setContinue(string continuee){
        m_continue = continuee;

    }
    // Adventure Trigger
    void getStart(){
        if (m_start == "Start"){
            cout << "Your adventure is beginning!" << endl;
            m_adv++;
        }else{
            cout << "Learn to write the right word!" << endl;
        }
    }

    // Adventure Choice Adv == 2
    void getContinue2(){
        if (m_continue == "A" && m_adv == 2){
            cout << "You have stepped outside. The only thing you see is dark. After a while, you hear something growl not so far from you. What is your next move?" << endl;
            cout << "Press:" << endl;
            cout << "A: I am going to try to find a weapon." << endl;
            cout << "B: I am going to call for help." << endl;
            cout << "C: I am going to check my pockets." << endl;
            m_adv++;
        }else if(m_continue == "B" && m_adv == 2){
            cout << "You are looking around the room. The only things in the room is a bed and a table. After proper searching, you have noticed a letter lying on the table. What is your next move?" << endl;
            cout << "Press:" << endl;
            cout << "A: I am going to open it. " << endl;
            cout << "B: I am not interested in the letter, I am searching for other things." << endl;
            cout << "C: I am going to head out, because I didn't find anything useful." << endl;
        }else if(m_continue == "C" && m_adv == 3){
            cout << "You have lied down and started thinking about your meaningless life and your entire existence. What is your next move?" << endl;
            cout << "Press:" << endl;
            cout << "A: I am going to commit suicide." << endl;
            cout << "B: I am going to pray to Jesus." << endl;
            cout << "C: I am going to think about something nice." << endl;
        }
    }

    // Continue 3(Adv == 3), A(Adv == 2) == Continue21A
    void getContinue3A(){
        if (m_continue == "A" && m_adv == 3){
            cout << "You are trying to find a weapon, but it's dark.. GRROOOOOWLL.. Suddenly you are feeling chills all over your body. \"Something\" is getting closer.. What is your next move? " << endl;
            cout << "Press:" << endl;
            cout << "A: I am going to panic and scream for help." << endl;
            cout << "B: I am determined to fight it." << endl;
            cout << "C: I am starting to have seizure." << endl;
        }else if(m_continue == "B" && m_adv == 3){
            cout << "You are calling for help, but there is no response. \"Something\" has heard you, and it's running fast towards you.  What is your next move?" << endl;
            cout << "Press:" << endl;
            cout << "A: I am determined to fight. " << endl;
            cout << "B: I am going to use magic, even though I don't know any." << endl;
            cout << "C: I feel like I am going to die." << endl;
        }else if(m_continue == "C" && m_adv == 3){
            cout << "You are checking your pockets just to find a key in them. The key has a weird shape like a dragon's shape. You feel some magic power coming out from it. What is your next move?" << endl;
            cout << "Press:" << endl;
            cout << "A: I am going to look for any keyhole." << endl;
            cout << "B: I am going to try absorb the magic from it. " << endl;
            cout << "C: I am going to throw it away." << endl;
        }
    }
    // Adventure begins
    void getBegin(){
        if(m_adv == 1) {
            cout << "You have woken up in an unknown room. You are looking around, but you don't see anything interesting. What are you going to do?" << endl;
            cout << "Press:" << endl;
            cout << "A: I am going to head outside." << endl;
            cout << "B: I am going to inspect the room in details." << endl;
            cout << "C: I am not planning to do anything." << endl;
            m_adv++;

        }else{
            cout << "You are not allowed to play. Restart the game!" << endl;
        }

    }


};

int main() {
    string name;
    string start;
    string continuee;

    // Create character
    Character* newChar = new Character(0,0,0);
    cout << "Enter your name: ";
    getline(cin,name);
    newChar->setName(name);

    // Character's info
    cout << "Welcome to the game, " << newChar->getName() << '!' << endl;
    cout << "These are your base stats!" << endl;
    newChar->printInfo();
    cout << "You have this much money!" << endl;
    newChar->getMoney();

    // Adventure - Beginning
    cout << "Are you ready? Write \"Start\"." << endl;
    getline(cin,start);
    newChar->setStart(start);
    newChar->getStart();
    newChar->getBegin();

    // Adventure continues
    getline(cin,continuee);
    newChar->setContinue(continuee);
    newChar->getContinue2();
    getline(cin,continuee);
    newChar->setContinue(continuee);
    newChar->getContinue3A();

    return 0;
}