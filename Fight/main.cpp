#include <iostream>
#include <ctime>
#include <random>
using namespace std;

class Character {
private:
    string m_name;
    int m_vitality;
    int m_intelligence;
    int m_endurance;
    int m_strength;
    int m_agility;
    int m_gold;
    string m_start;
    string m_continue;
    int m_mhp = (rand() % 250) + 1;
    int m_hp;
    int m_mp;
    int m_potions = 2;

public:

    Character(int gold) {
        srand((unsigned) time(0));

        m_name = "";
        m_vitality = (rand() % 10) + 1;
        m_intelligence = (rand() % 10) + 1;
        m_endurance = (rand() % 10) + 1;
        m_strength = (rand() % 10) + 1;
        m_agility = (rand() % 10) + 1;
        m_mp = m_intelligence * 10;
        m_hp = m_vitality * 15;
        m_gold = gold;
    }

    void setGodMode() {
        if (m_name == "God" || m_name == "god") {
            m_strength += 100;
            m_intelligence += 100;
            m_endurance += 100;
            m_vitality += 100;
            m_agility += 100;
            m_hp = m_vitality * 15;
            m_mp = m_intelligence * 10;
            m_gold = 999999;
        }
    }

    void setName(string newName) {
        m_name = newName;
        setGodMode();
    }

    string getName() {
        return m_name;
    }

    void printInfo() {
        cout << "Vitality: " << m_vitality << endl;
        cout << "Intelligence: " << m_intelligence << endl;
        cout << "Endurance: " << m_endurance << endl;
        cout << "Strength: " << m_strength << endl;
        cout << "Agility: " << m_agility << endl;
    }

    void getMoney() {
        cout << m_gold << " gold/s" << endl;
    }

    void setStart(string start) {
        m_start = start;
    }

    void setContinue(string cont) {
        m_continue = cont;
    }

    void getStart() {
        if (m_start == "S" || m_start == "s") {
            cout << "Your adventure is beginning!" << endl;
        }else {
            cout << "" << endl;
        }
    }

    void getBegin() {
        if (m_start == "S" || m_start == "s") {
            cout << "You have met a monster!" << endl;
            cout << "Press:" << endl;
            cout << "A: Fight." << endl;
            cout << "B: Run." << endl;
        }else {
            cout << "GAME OVER! Restart the game, retard!!" << endl;
            exit(0);
        }
    }

    int getStartDmg() {
        if (m_continue == "A" || m_continue == "a") {
            cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
            cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
            cout << "A: Punch" << endl;
            cout << "B: Fireball" << endl;
            cout << "C: Heal Potion (" << m_potions << "/2)" << endl;

            return m_mhp;
        }else {
            cout << "You ran away. Restart the game, coward!!" << endl;

            exit(0);
        }
    }

    int getFight() {
        if (m_continue == "A" || m_continue == "a") {
            if (m_hp <= 0 && m_mhp <= 0) {
                m_hp = 0;
                m_mhp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "Randalf is dead. You died." << endl;
            }else if (m_hp <= 0) {
                m_hp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "You have died." << endl;
            }else if (m_mhp <= 0) {
                m_mhp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "Randalf is dead." << endl;
            }else if (m_mhp > 0 && m_mp > 0) {
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                cout << "C: Heal Potion (" << m_potions << "/2)" << endl;
            }else {
                m_mp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "C: Heal Potion (" << m_potions << "/2)" << endl;
            }
            return m_mhp;
        }else if (m_continue == "B" || m_continue == "b") {
            if (m_hp <= 0 && m_mhp <= 0) {
                m_hp = 0;
                m_mhp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "Randalf is dead. You died." << endl;
            }else if (m_hp <= 0) {
                m_hp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "You have died." << endl;
            }else if (m_mhp <= 0) {
                m_mhp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "Randalf is dead." << endl;
            }else if (m_mp > 0) {
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                cout << "C: Heal Potion (" << m_potions << "/2)" << endl;
            }else {
                m_mp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "C: Heal Potion (" << m_potions << "/2)" << endl;
            }

        }
        else if(m_continue == "C" || m_continue == "c"){
            if (m_mhp > 0 && m_mp > 0) {
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                cout << "C: Heal Potion (" << m_potions << "/2)" << endl;
            }else if(m_mp <= 0) {
                m_mp = 0;
                cout << "Enemy: Randalf  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "C: Heal Potion (" << m_potions << "/2)" << endl;
            }
            return m_mhp;
        }
    }
    int getDmg() {
        if (m_continue == "A" || m_continue == "a") {
            m_mhp -= m_strength * 3;
            m_hp -= (rand() % 10) + 1;

            return m_mhp;
        }else if ((m_continue == "B" || m_continue == "b") && m_mp > 0) {
                m_mhp -= m_intelligence * 5;
                m_mp -= m_intelligence * 4;
                m_hp -= (rand() % 6) + 1;

                return m_mhp;
        }else if((m_continue == "B" || m_continue == "b") && m_mp <= 0){
                cout << "You don't have enough mp!" << endl;
        }
        else if(m_continue == "C" || m_continue == "c"){
            getPotion();
        }
    }
    int getPotion(){
        if(m_potions > 0) {
            m_hp += 50;
            m_potions--;
        }else{
            cout << "You don't have any potions!" << endl;
        }
        return m_hp;
    }
    int getHp(){

        return m_mhp;
    }
    int getHp2(){

        return m_hp;
    }
};
int main() {
    string name;
    string start;
    string cont;

    Character* newChar = new Character(0);
    cout << "Enter your name: ";
    getline(cin,name);
    newChar->setName(name);

    // Character's info
    cout << "Welcome to the game, " << newChar->getName() << '!' << endl;
    cout << "These are your base stats!" << endl;
    newChar->printInfo();
    cout << "You have this much money!" << endl;
    newChar->getMoney();

    cout << "Are you ready? Write \"S\"." << endl;
    getline(cin,start);
    newChar->setStart(start);
    newChar->getStart();
    newChar->getBegin();

    getline(cin,cont);
    newChar->setContinue(cont);
    newChar->getStartDmg();

    while (newChar->getHp() > 0 && newChar->getHp2() > 0) {
        getline(cin, cont);
        newChar->setContinue(cont);
        newChar->getDmg();
        newChar->getFight();
    }

    delete newChar;

    return 0;
}