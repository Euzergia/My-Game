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
    int w;
    int x;
    int m_lvl;
    int m_exp;
    int m_maxHp;
    int m_maxMp;
    int m_maxPotions;
    int m_lvlcap;
    int m_skillpoint;
    int lvl;

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
        w = 0;
        x = 0;
        m_lvl = 1;
        m_exp = 0;
        m_lvlcap = 400;
        m_skillpoint = 0;
        lvl = 0;

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
            cout << "---------Name---------   ---------Action----------   ---------Command---------" << endl;
            cout << "God's Blessing           Restore Full HP             gb/Gb/GB" << endl;
            cout << "Test Mode ON             Full HP, MP, potions        test/Test" << endl;
            cout << "Test mode OFF            Cancel test mode            canc/Canc" << endl;
            cout << "Status Window            Open Status Win.            stat/Stat" << endl;
            cout << "Stats Up *               Use skill point/s           vit/1, int/2, str/3, end/4, agi/5" << endl;
            cout << "         * - must be used in Status Window" << endl;
            cout << "Shop                     Open Shop                   shop/Shop" << endl;
            cout << "Clear                    Clear                       clear/Clear" << endl;
            cout << "Exit                     Exit game                   exit/Exit" << endl;

            cout << "" << endl;
            cout << "Write 'Esc/esc' to go back." << endl;
            line();
            cin >> m_continue;
            if((m_continue == "Esc" || m_continue == "esc") && m_mp <= 0) {
                space();
                cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                potions();

                line();
                y = 0;
            }else if(m_continue == "Esc" || m_continue == "esc") {
                space();
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

    void clear(){
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        if(m_mp <= 0){
            cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
            cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
            cout << "A: Punch" << endl;
            potions();

            line();
        }else{
            cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
            cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
            cout << "A: Punch" << endl;
            cout << "B: Fireball" << endl;
            potions();

            line();
        }
    }

    void statusWindow(){
        while(y == 1) {
            cout << "Name:              " << m_name << endl;
            cout << "Level:             " << m_lvl << endl;
            cout << "Exp:               " << m_exp << "/" << m_lvlcap << endl;
            cout << "HP:                " << m_hp << endl;
            cout << "MP:                " << m_mp << endl;
            cout << "Vitality(1):       " << m_vitality << endl;
            cout << "Intelligence(2):   " << m_intelligence << endl;
            cout << "Strength(3):       " << m_strength << endl;
            cout << "Endurance(4):      " << m_endurance << endl;
            cout << "Agility(5):        " << m_agility << endl;
            cout << endl;
            cout << "Skill point/s:     " << m_skillpoint << endl;
            cout << "Gold/s:            " << m_currency << endl;

            cout << endl;
            cout << "Write \"Esc/esc\" to go back." << endl;
            line();
            cin >> m_continue;
            if((m_continue == "Esc" || m_continue == "esc") && m_mp <= 0){
                space();
                cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                potions();

                line();
                y = 0;
                }else if(m_continue == "Esc" || m_continue == "esc"){
                space();
                cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                potions();

                line();
                y = 0;
            }else if(m_continue == "Exit" || m_continue == "exit"){
                exit(0);
            }else if(m_skillpoint > 0) {
                if(m_continue == "str" || m_continue == "Str" || m_continue == "3")
                {
                    m_skillpoint--;
                    m_strength++;
                }else if (m_continue == "vit" || m_continue == "Vit" || m_continue == "1"){
                    m_skillpoint--;
                    m_vitality++;
                    m_hp += 15;
                } else if (m_continue == "int" || m_continue == "Int" || m_continue == "2"){
                    m_skillpoint--;
                    m_intelligence++;
                } else if (m_continue == "agi" || m_continue == "Agi" || m_continue == "5") {
                    m_skillpoint--;
                    m_agility++;
                } else if (m_continue == "end" || m_continue == "End" || m_continue == "4") {
                    m_skillpoint--;
                    m_endurance++;
                }
            }else if(m_skillpoint == 0){
                space();
                cout << "You do not have skill points." << endl;
            }
        }
    }

    int testMode() {
        if (w == 1) {
            if (m_continue == "A" || m_continue == "a") {
                if ((rand() % 15) > 10) {
                    cout << "Critical Hit!!" << endl;
                    m_mhp -= m_strength * 3 + (rand() % 20);
                } else {
                    m_mhp -= m_strength * 3 + (rand() % 5);
                }
                return m_mhp;
            } else if (m_continue == "B" || m_continue == "b") {
                if (m_mp >= manaDrain()) {
                    if ((rand() % 15) > 10) {
                        cout << "Critical Hit!!" << endl;
                        m_mhp -= m_intelligence * 5 + (rand() % 20);
                    } else {
                        m_mhp -= m_intelligence * 5 + (rand() % 5);
                    }
                }
                return m_mhp;
            } else if (m_continue == "C" || m_continue == "c") {
                getPotion();
            } else if (m_continue == "Help" || m_continue == "help") {
                space();
                helpMenu();
                y = 1;
            } else if (m_continue == "Stat" || m_continue == "stat") {
                space();
                statusWindow();
                y = 1;
            } else if ((m_continue == "canc" || m_continue == "Canc") && w == 1) {
                w = 0;
                cout << "Test mode OFF." << endl;
            } else if(m_continue == "Clear" || m_continue == "clear") {
                clear();
            } else if(m_continue == "Shop" || m_continue == "shop"){
                space();
                shop();
                y = 1;
            }
        }
    }

    void getBegin() {
        if (m_start == "S" || m_start == "s") {
            space();
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
            space();
            cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
            cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
            cout << "A: Punch" << endl;
            cout << "B: Fireball" << endl;
            potions();

            line();
            return m_mhp;
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
        cout << "You have gained: " << lvl << " Exp" << endl;
        cout << "You have acquired these items: " << getGold() << " gold/s" << endl;
    }

    int currency(){
        m_currency += m_gold;

        return m_currency;
    }

    int getFight() {
        if (m_continue == "A" || m_continue == "a") {
            space();
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

                space();
                getExp();
                levelUp();
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
                space();
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
        }else if(m_continue == "Clear" || m_continue == "clear") {
            clear();
        }else if(m_continue == "exit" || m_continue == "Exit") {
            exit(0);
        }else if(m_continue == "Shop" || m_continue == "shop") {
            shop();
            y = 1;
        }else if (m_continue == "B" || m_continue == "b") {
            space();
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

                space();
                getExp();
                levelUp();
                reward();
                currency();
                line();
            }else if (m_mhp <= 0) {
                m_mhp = 0;
                cout << "Enemy: " << arrayString[RandIndex] << " " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << arrayString[RandIndex] << " is dead." << endl;

                space();
                getExp();
                levelUp();
                reward();
                currency();
                line();
            }else if (m_mp >= manaDrain()) {
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
            space();
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

    void space(){
        cout << endl;
    }

    void shop(){
        while(y == 1) {
            cout << "A: Weapons" << endl;
            cout << "B: Armors" << endl;
            cout << "C: Potions" << endl;
            cout << endl;
            cout << "Write Esc/esc to go back." << endl;
            cin >> m_continue;
            if((m_continue == "Esc" || m_continue == "esc") && m_mp <= 0){
                space();
                cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                potions();

                line();
                y = 0;
            }else if(m_continue == "Esc" || m_continue == "esc"){
                space();
                cout << "Enemy: " << arrayString[RandIndex] << "  " << m_mhp << " hp" << endl;
                cout << "Player: " << m_name << "  " << m_hp << " hp / " << m_mp << " mp" << endl;
                cout << "A: Punch" << endl;
                cout << "B: Fireball" << endl;
                potions();

                line();
                y = 0;
            }else if(m_continue == "Exit" || m_continue == "exit"){
                exit(0);
            }else if(m_continue == "A" || m_continue == "a"){
                y = 0;
                x = 1;
                weaponsShop();
            }else if(m_continue == "B" || m_continue == "b") {
                y = 0;
                x = 1;
                armorsShop();
            }else if(m_continue == "C" || m_continue == "c") {
                y = 0;
                x = 1;
                potionsShop();
            }
        }
    }

    void weaponsShop() {
        string a1 = "Classic Sword";
        string a2 = "Bloodsucking Sword";
        string a3 = "Excalibur";
        string a4 = "Heaven's Sword";
        string a5 = "Hellfire Sword";
        while (x == 1) {
            space();
            cout << "Name:                           Price" << endl;
            cout << "1: Classic Sword                3 golds" << endl;
            cout << "2: Bloodsucking Sword           10 golds" << endl;
            cout << "3: Excalibur                    20 golds" << endl;
            cout << "4: Heaven's Sword               30 golds" << endl;
            cout << "5: Hellfire Sword               30 golds" << endl;

            cin >> m_continue;
            if (m_continue == "1") {
                x = 0;
                cout << "Are you sure, you want to buy it?" << endl;
                cout << "A: Yes" << endl;
                cout << "B: No" << endl;
                cin >> m_continue;
                if ((m_continue == "A" || m_continue == "a") && m_currency >= 3) {
                    cout << "You have bought " << a1 << "." << endl;
                    m_currency -= 3;
                }else {
                    cout << " You don't have enough golds!" << endl;
                    x = 1;
                    weaponsShop();
                }
            }
            if (m_continue == "2") {
                x = 0;
                cout << "Are you sure, you want to buy it?" << endl;
                cout << "A: Yes" << endl;
                cout << "B: No" << endl;
                cin >> m_continue;
                if ((m_continue == "A" || m_continue == "a") && m_currency >= 10) {
                    cout << "You have bought " << a2 << "." << endl;
                    m_currency -= 10;
                }else {
                    cout << " You don't have enough golds!" << endl;
                    x = 1;
                    weaponsShop();
                }
            }
            if (m_continue == "3") {
                x = 0;
                cout << "Are you sure, you want to buy it?" << endl;
                cout << "A: Yes" << endl;
                cout << "B: No" << endl;
                cin >> m_continue;
                if ((m_continue == "A" || m_continue == "a") && m_currency >= 20) {
                    cout << "You have bought " << a3 << "." << endl;
                    m_currency -= 20;
                }else {
                    cout << " You don't have enough golds!" << endl;
                    x = 1;
                    weaponsShop();
                }
            }
            if (m_continue == "4") {
                x = 0;
                cout << "Are you sure, you want to buy it?" << endl;
                cout << "A: Yes" << endl;
                cout << "B: No" << endl;
                cin >> m_continue;
                if ((m_continue == "A" || m_continue == "a") && m_currency >= 30) {
                    cout << "You have bought " << a4 << "." << endl;
                    m_currency -= 30;
                }else {
                    cout << " You don't have enough golds!" << endl;
                    x = 1;
                    weaponsShop();
                }
            }
            if (m_continue == "5") {
                x = 0;
                cout << "Are you sure, you want to buy it?" << endl;
                cout << "A: Yes" << endl;
                cout << "B: No" << endl;
                cin >> m_continue;
                if ((m_continue == "A" || m_continue == "a") && m_currency >= 30) {
                    cout << "You have bought " << a5 << "." << endl;
                    m_currency -= 30;
                }else {
                    cout << " You don't have enough golds!" << endl;
                    x = 1;
                    weaponsShop();
                }
            }
        }
    }

    void armorsShop(){
        while(x == 1){

        }
    }

    void potionsShop(){
        while(x == 1){

        }
    }

    void potions(){
        cout << "C: Heal Potion (" << m_potions << "/3)" << endl;
    }
    int manaDrain(){       //Fireball = -mana
        int drain;
        if(m_intelligence >= 5) {
            drain = m_intelligence * 4 - (m_intelligence + 5);
        }else{
            drain = 2;
        }
        return drain;
    }

    int getDmg() {
        int dodge;
        int def;
        int a = (rand() % 21);
        if(m_agility >= 10) {
            dodge = m_agility - 10;
        }else {
            dodge = 0;
        }
        if(m_endurance >= 5){
            def = m_endurance - 5;
        }else {
            def = 0;
        }
        if(w == 0) {
            if (m_continue == "A" || m_continue == "a") {
                if ((rand() % 15) > 10) {
                    cout << "Critical Hit!!" << endl;
                    m_mhp -= m_strength * 3 + (rand() % 20);
                } else {
                    m_mhp -= m_strength * 3 + (rand() % 5);
                }
                if(m_agility > (rand() % 11) + dodge) {
                    if ((rand() % 11) > 6) {
                        cout << "You have dodged." << endl;
                    } else {
                        if (a > def) {
                            m_hp -= (a - def);
                        } else {
                            cout << "Monster was't able to scratch you." << endl;
                        }
                    }
                }else if (a > def) {
                    m_hp -= (a - def);
                } else {
                    cout << "Monster was't able to scratch you." << endl;
                }
            } else if (m_continue == "B" || m_continue == "b") {
                if (m_mp >= manaDrain()) {
                    if ((rand() % 15) > 10) {
                        cout << "Critical Hit!!" << endl;
                        m_mhp -= m_intelligence * 5 + (rand() % 20);
                    } else {
                        m_mhp -= m_intelligence * 5 + (rand() % 5);
                    }
                        if(m_agility > (rand() % 11) + dodge) {
                            if ((rand() % 11) > 5) {
                                cout << "You have dodged." << endl;
                            } else {
                                if (a > def) {
                                    m_hp -= (a - def);
                                } else {
                                    cout << "Monster was't able to scratch you." << endl;
                                }
                            }
                        }else if (a > def) {
                            m_hp -= (a - def);
                        } else {
                            cout << "Monster was't able to scratch you." << endl;
                        }
                    m_mp -= manaDrain();
                } else if (m_mp < manaDrain()) {
                    cout << "You don't have enough mp!" << endl;
                }
            } else if (m_continue == "C" || m_continue == "c") {
                getPotion();
            } else if (m_continue == "Help" || m_continue == "help") {
                space();
                helpMenu();
                y = 1;
            } else if (m_continue == "Stat" || m_continue == "stat") {
                space();
                statusWindow();
                y = 1;
            } else if ((m_continue == "test" || m_continue == "Test") && w == 0) {
                w = 1;
                cout << "Test mode ON." << endl;
            } else if(m_continue == "Clear" || m_continue == "clear") {
                clear();
            } else if(m_continue == "Shop" || m_continue == "shop") {
                space();
                shop();
                y = 1;
            }
        }
        return m_mhp;
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

    int getExp(){
        lvl = (rand() % 1000);

        return lvl;
    }

    int levelUp(){
        m_exp += lvl;
        if(m_lvlcap <= m_exp){
            m_exp -= m_lvlcap;
            m_lvl++;
            m_lvlcap += 400;
            m_skillpoint++;
            if(m_lvlcap < m_exp){
                m_exp -= m_lvlcap;
                m_lvl++;
                m_lvlcap += 300;
                cout << "Level Up!!   +2 skill point" << endl;
                m_skillpoint++;
            }else {
                cout << "Level Up!!   +1 skill point" << endl;
            }
        }
        return m_exp;
    }

};

class Weaponry{
private:
    int a;
    int b;
    int c;
    int d;

public:
    void classicSword(){

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
            newChar->testMode();
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
                        newChar->testMode();
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