#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>
#include <string>
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
    int m_currency;
    string m_start;
    string m_continue;
    int m_mhp;
    int m_hp;
    int m_mp;
    int m_potions;
    int RandIndex;
    string arrayString[10] = {"Slime", "Lizard", "Skeleton", "Dragon", "Goblin", "Troll", "Whisp", "Demon", "Ape", "Wolf"};
    int y;
    int m_lvl;
    int m_exp;
    int m_maxHp;
    int m_maxMp;
    int m_maxPotions;

public:

    Character() {
        srand((unsigned) time(0));

        m_name = "";
        m_vitality = (rand() % 10) + 1;
        m_intelligence = (rand() % 10) + 1;
        m_endurance = (rand() % 10) + 1;
        m_strength = (rand() % 10) + 1;
        m_agility = (rand() % 10) + 1;
        m_maxHp = m_vitality * 15;
        m_maxMp = m_intelligence * 10;
        m_hp = m_maxHp;
        m_mp = m_maxMp;
        m_mhp  = (rand() % 250) + 1;
        m_start = "";
        m_continue = "";
        m_gold = 0;
        m_currency = 0;
        m_maxPotions = 3;
        m_potions = m_maxPotions;
        RandIndex = rand() % 10;
        y = 0;
        m_lvl = 1;
        m_exp = 0;

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
            m_currency = m_gold;
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

    void line(){
        cout << "---------------------------------------" << endl;
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
    void helpMenu(){
        while(y == 1) {
            cout << "------Name------   ------Action------   ------Command------" << endl;
            cout << "God's Blessing     Restore Full HP      gb/Gb/GB" << endl;
            cout << "Status Window      Open Status Win.     stat/Stat" << endl;
            cout << "Exit               Exit game            exit/Exit" << endl;

            cout << "" << endl;
            cout << "Write 'Esc/esc' to go back." << endl;
            line();
            cin >> m_continue;
            if(m_continue == "Esc" || m_continue == "esc") {
                cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                potions();

                line();
                y = 0;
            }
            else if(m_continue == "Exit" || m_continue == "exit"){
                exit(0);
            }
        }
    }

    void statusWindow(){
        while(y == 1) {
            cout << "Name:           " << m_name << endl;
            cout << "Level:          " << m_lvl << endl;
            cout << "Exp:            " << m_exp << endl;
            cout << "HP:             " << m_hp << endl;
            cout << "MP:             " << m_mp << endl;
            cout << "Vitality:       " << m_vitality << endl;
            cout << "Intelligence:   " << m_intelligence << endl;
            cout << "Strength:       " << m_strength << endl;
            cout << "Endurance:      " << m_endurance << endl;
            cout << "Agility:        " << m_agility << endl;
            cout << "" << endl;
            cout << "Gold/s:         " << m_currency << endl;

            cout << "" << endl;
            cout << "Write \"Esc/esc\" to go back." << endl;
            line();
            cin >> m_continue;
            if(m_continue == "Esc" || m_continue == "esc"){
                cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                potions();

                line();
                y = 0;
            }else if(m_continue == "Exit" || m_continue == "exit"){
                exit(0);
            }
        }
    }

    void getBegin() {
        if (m_start == "S" || m_start == "s") {
            cout << "You have met a monster!" << endl;
            cout << "Press:" << endl;
            cout << "A: Fight." << endl;
            cout << "B: Run." << endl;

            line();
        }else {
            cout << "GAME OVER! Restart the game, retard!!" << endl;
            exit(0);
        }
    }

    int getStartDmg() {
        if (m_continue == "A" || m_continue == "a") {
            cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
            cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
            cout << "A: Punch" << endl;
            cout << "B: Fireball" << endl;
            potions();

            line();
            return m_mhp;
        }else if(m_continue == "Help" || m_continue == "help") {
            helpMenu();
            y = 1;
        }else if(m_continue == "Stat" || m_continue == "stat") {
            statusWindow();
            y = 1;
        }else if(m_continue == "gb" || m_continue == "GB" || m_continue == "Gb"){
            godBlessing();
            cout << "You were blessed." << endl;
            cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
            cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
            cout << "A: Punch" << endl;
            cout << "B: Fireball" << endl;
            potions();

            line();
        }else {
            cout << "You have run away. Restart the game, coward!!" << endl;

            exit(0);
        }
    }

    int getGold(){
        m_gold = (rand() % 5) + 1;
        return m_gold;
    }

    void reward(){
        cout << "You have acquired these items: " << endl;
        cout << getGold() << " gold/s" << endl;
    }

    int currency(){
        m_currency += m_gold;

        return m_currency;
    }

    int getFight() {
        if (m_continue == "A" || m_continue == "a") {
            if (m_hp <= 0 && m_mhp <= 0) {
                m_hp = 0;
                m_mhp = 0;
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << arrayString[RandIndex] << " is dead. You died." << endl;

                line();
            } else if (m_hp <= 0) {
                m_hp = 0;
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "You have died." << endl;

                line();
            } else if (m_mhp <= 0) {
                m_mhp = 0;
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << arrayString[RandIndex] << " is dead." << endl;

                reward();
                currency();
                line();
            } else if (m_mhp > 0 && m_mp > manaDrain()) {
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                potions();

                line();
            } else {
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                potions();

                line();
            }
            return m_mhp;
        }else if(m_continue == "gb" || m_continue == "GB" || m_continue == "Gb"){
                godBlessing();
                cout << "You were blessed." << endl;
                cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                potions();

                line();
        }else if (m_continue == "Help" || m_continue == "help") {
            helpMenu();
            y = 1;
        }else if(m_continue == "Stat" || m_continue == "stat") {
                statusWindow();
                y = 1;
        }else if(m_continue == "exit" || m_continue == "Exit") {
            exit(0);
        }else if (m_continue == "B" || m_continue == "b") {
            if (m_hp <= 0 && m_mhp <= 0) {
                m_hp = 0;
                m_mhp = 0;
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << arrayString[RandIndex] << " is dead. You died." << endl;

                line();
            }else if (m_hp <= 0) {
                m_hp = 0;
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "You have died." << endl;

                line();
            }else if (m_mhp <= 0 && m_mp <= manaDrain()) {
                m_mhp = 0;
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << arrayString[RandIndex] << " is dead." << endl;

                reward();
                currency();
                line();
            }else if (m_mhp <= 0) {
                m_mhp = 0;
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << arrayString[RandIndex] << " is dead." << endl;

                reward();
                currency();
                line();
            }else if (m_mp > manaDrain()) {
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                potions();

                line();
            }else {
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                potions();

                line();
            }

        }
        else if(m_continue == "C" || m_continue == "c"){
            if (m_mhp > 0 && m_mp > manaDrain()) {
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                potions();

                line();
            }else if(m_mp < manaDrain()) {
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                potions();

                line();
            }
            return m_mhp;
        }
    }
    void potions(){
        cout << "C: Heal Potion (" << m_potions << "/3)" << endl;
    }
    int manaDrain(){       //Fireball = -mana
        int drain = m_intelligence * 4;
        return drain;
    }

    int getDmg() {
        if (m_continue == "A" || m_continue == "a") {
            if ((rand() % 15) > 10) {
                cout << "Critical Hit!!" << endl;
                m_mhp -= m_strength * 3 + (rand() % 20);
            } else {
                m_mhp -= m_strength * 3 + (rand() % 5);
            }
            m_hp -= (rand() % 10) + 1;

            return m_mhp;
        } else if (m_continue == "B" || m_continue == "b") {
            if (m_mp >= manaDrain()) {
                if ((rand() % 15) > 10) {
                    cout << "Critical Hit!!" << endl;
                    m_mhp -= m_intelligence * 5 + (rand() % 20);
                } else {
                    m_mhp -= m_intelligence * 5 + (rand() % 5);
                }
                m_mp -= manaDrain();
                m_hp -= (rand() % 12) + 1;
            } else if (m_mp < manaDrain()) {
                cout << "You don't have enough mp!" << endl;
            }
            return m_mhp;
        }else if (m_continue == "C" || m_continue == "c") {
            getPotion();
        } else if (m_continue == "Help" || m_continue == "help") {
            helpMenu();
            y = 1;
        } else if (m_continue == "Stat" || m_continue == "stat") {
            statusWindow();
            y = 1;
        }
    }

    int getPotion(){
        int a = 50;
        if(m_potions > 0) {
            if((a + m_hp) > m_maxHp){
                while((a + m_hp) != m_maxHp){
                    if((a + m_hp) > m_maxHp) {
                        a--;
                    }else{
                        break;
                    }
                }
                m_hp += a;
            }else {
                m_hp += a;
            }
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

    int monsterStats() {
        m_mhp = (rand() % 250) + 1;
        RandIndex = rand() % 10;

        return m_mhp, RandIndex;
    }

    void godBlessing(){
        m_hp = m_maxHp;
        m_mp = m_maxMp;
        m_potions = m_maxPotions;

    }

    void levelUp(){
        m_lvl++;
    }

    int getExp(){
        int 
    }

};


int main() {
        string name;
        string start;
        string cont;
        string a;
        int x = 0;

        Character *newChar = new Character();
        cout << "Enter your name: ";
        getline(cin, name);
        newChar->setName(name);
        newChar->line();

        // Character's info
        cout << "Welcome to the game, " << newChar->getName() << '!' << endl;
        cout << "" << endl;
        cout << "These are your base stats!" << endl;
        newChar->printInfo();
        cout << "" << endl;
        cout << "You have this much money!" << endl;
        newChar->getMoney();
        newChar->line();

        cout << "Are you ready? Write \"S\"." << endl;
        newChar->line();
        getline(cin, start);
        newChar->setStart(start);
        newChar->getStart();
        newChar->getBegin();

        getline(cin, cont);
        newChar->setContinue(cont);
        newChar->getStartDmg();

        while (newChar->getHp() > 0 && newChar->getHp2() > 0) {
            getline(cin, cont);
            newChar->setContinue(cont);
            newChar->getDmg();
            newChar->getFight();
            newChar->setContinue(cont);
        }
        if(newChar->getHp2() > 0) {
            while (x == 0) {
                cout << "You have finished the fight!" << endl;
                cout << "A: Fight new monster" << endl;
                cout << "B: Exit the game" << endl;
                newChar->line();
                getline(cin, cont);
                newChar->setContinue(cont);
                newChar->monsterStats();
                if (cont == "A" || cont == "a") {
                    newChar->getFight();
                    while (newChar->getHp() > 0 && newChar->getHp2() > 0) {
                        getline(cin, cont);
                        newChar->setContinue(cont);
                        newChar->getDmg();
                        newChar->getFight();
                        newChar->setContinue(cont);
                        if (newChar->getHp2() <= 0) {
                            x = 1;
                        }
                    }
                } else if (cont == "B" || cont == "b") {
                    x = 1;
                }
            }
        }
    delete newChar;
    return 0;
}