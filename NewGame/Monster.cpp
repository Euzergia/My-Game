//
// Created by Lenovo on 14.12.2019.
//

#include "Monster.h"

    Monster::Monster(){
        m_strength = 0;
        m_agility = 0;
        m_vitality = 0;
        m_intelligence = 0;
        m_hp = 0;
        m_mp = 0;
        /*m_monsterName = "Dragon";*/
    }
    int Monster::setHp(int hp){
        m_hp = hp;
    }
    int Monster::getHp(){
        return m_hp;
    }
    std::string Monster::getName(){
        return m_monsterName;
    }
    int Monster::setMp(int mp) {
        m_mp = mp;
    }
    int Monster::setAgility(int agility) {
        m_agility = agility;
    }
    std::string Monster::setName(std::string name) {
        m_monsterName = name;
    }
    int Monster::setIntelligence(int intelligence) {
        m_intelligence = intelligence;
    }
    int Monster::setVitality(int vitality) {
        m_vitality = vitality;
    }
    int Monster::setStrength(int strength) {
        m_strength = strength;
    }
    int Monster::getVitality() {
        return  m_vitality;
    }
    int Monster::getMp() {
        return m_mp;
    }
    int Monster::getIntelligence() {
        return m_intelligence;
    }
    int Monster::getAgility() {
        return m_agility;
    }
    int Monster::getStrength() {
        return m_strength;
    }
    void Monster::dragonNames() {
        std::srand(time(0));
        std::string DragonName[] = {"Drogllis", "Annaphira", "Dracona", "Razen"};
        int randIndex = rand() % 4;
        setName("Dragon - " + DragonName[randIndex]);
    }
    void Monster::dragonNames2() {
        std::srand(time(0));
        std::string DragonName[] = {"Firellis", "Wikora", "Annariona", "Zologia"};
        int randIndex = rand() % 4;
        setName("Dragon Elder - " + DragonName[randIndex]);
    }
    void Monster::dragonNames3() {
        std::srand(time(0));
        std::string DragonName[] = {"Wiseria", "Bahamut", "Doom"};
        int randIndex = rand() % 3;
        setName("BOSS Dragon - " + DragonName[randIndex]);
    }
    void Monster::wolfNames(){
            std::string WolfName[] = {"Wolf"};
            int randIndex = 1;
            setName(WolfName[randIndex]);
    }
    void Monster::wolfNames2(){
        std::srand(time(0));
        std::string WolfName[] = {"Zonya", "Geros", "Gesa"};
        int randIndex = rand() % 3;
        setName("Wolf General - " + WolfName[randIndex]);
    }
    void Monster::wolfNames3(){
        std::srand(time(0));
        std::string WolfName[] = {"Raiga"};
        int randIndex = 1;
        setName("Wolf BOSS - " + WolfName[randIndex]);
    }
    void Monster::randMonster() {
        std::srand(time(0));
        int randIndex = 1 + (rand() % (5 - 1));
        switch (randIndex) {
            case 1: {
                int choice = 0;
                int randIndexLvl = rand() % 10;
                if (randIndexLvl >= 0 && randIndexLvl <= 5) {
                    choice = 1;
                } else if (randIndexLvl > 5 && randIndexLvl <= 8) {
                    choice = 2;
                } else if (randIndexLvl > 8){
                    choice = 3;
                }
                switch (choice) {
                    case 1:
                        setStrength(25 + rand() % 50);
                        setVitality(25 + rand() % 50);
                        setIntelligence(25 + rand() % 50);
                        setAgility(25 + rand() % 50);
                        setHp(getVitality() * (rand() % 50) + (rand() % 200));
                        setMp(getIntelligence() * (rand() % 50) + (rand() % 200));
                        dragonNames();
                        break;
                    case 2:
                        setStrength(35 + rand() % 70);
                        setVitality(35 + rand() % 70);
                        setIntelligence(35 + rand() % 70);
                        setAgility(35 + rand() % 70);
                        setHp(getVitality() * (rand() % 100) + (rand() % 500));
                        setMp(getIntelligence() * (rand() % 100) + (rand() % 500));
                        dragonNames2();
                        break;
                    case 3:
                        setStrength(50 + rand() % 100);
                        setVitality(50 + rand() % 100);
                        setIntelligence(50 + rand() % 100);
                        setAgility(50 + rand() % 100);
                        setHp(getVitality() * (rand() % 200) + (rand() % 1000));
                        setMp(getIntelligence() * (rand() % 200) + (rand() % 1000));
                        dragonNames3();
                        break;
                    default:
                        std::cout << "Error occured!!" << std::endl;
                }
                break;
            }
            case 2: {
                int choice = 0;
                int randIndexLvl = rand() % 10;
                if (randIndexLvl >= 0 && randIndexLvl <= 5) {
                    choice = 1;
                } else if (randIndexLvl > 5 && randIndexLvl <= 8) {
                    choice = 2;
                } else if (randIndexLvl > 8){
                    choice = 3;
                }
                switch (choice) {
                    case 1: {
                        setStrength(10 + rand() % 10);
                        setVitality(10 + rand() % 10);
                        setIntelligence(10 + rand() % 10);
                        setAgility(10 + rand() % 10);
                        setHp(getVitality() * (rand() % 10) + (rand() % 10));
                        setMp(getIntelligence() * (rand() % 10) + (rand() % 10));
                        wolfNames();
                        break;
                    }
                    case 2: {
                        setStrength(10 + rand() % 20);
                        setVitality(10 + rand() % 20);
                        setIntelligence(10 + rand() % 20);
                        setAgility(10 + rand() % 20);
                        setHp(getVitality() * (rand() % 20) + (rand() % 20));
                        setMp(getIntelligence() * (rand() % 20) + (rand() % 20));
                        wolfNames2();
                        break;
                    }
                    case 3: {
                        setStrength(10 + rand() % 30);
                        setVitality(10 + rand() % 30);
                        setIntelligence(10 + rand() % 30);
                        setAgility(10 + rand() % 30);
                        setHp(getVitality() * (rand() % 20) + (rand() % 30));
                        setMp(getIntelligence() * (rand() % 20) + (rand() % 30));
                        wolfNames3();
                        break;
                    }
                    default: std::cout << "Error occured!!" << std::endl;
                }
            }
            case 3:
                std::cout << "case 3" << std::endl;
                break;
            case 4:
                std::cout << "case 4" << std::endl;
                break;
            case 5:
                std::cout << "case 5" << std::endl;
                break;
        }
    }