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
        m_value = 0;
        m_lvl = 1;
        m_defense = 0;
        /*m_monsterName = "Dragon";*/
    }
    Monster::~Monster() {

    }
    int Monster::setHp(int hp){
        m_hp = hp;
    }
    int Monster::getHp(){
        return m_hp;
    }
    std::string Monster::getName() const{
        return m_monsterName;
    }
    int Monster::setMp(int mp) {
        m_mp = mp;
    }
    int Monster::setAgility(int agility) {
        m_agility = agility;
    }
    void Monster::setName(std::string name) {
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
    void Monster::setDmg(int dmg) {
        m_dmg = dmg;
    }
    int Monster::getDmg() {
        return m_dmg + critDamage();
    }
    int Monster::getLevel() {
        return m_lvl;
    }
    int Monster::critDamage() const{
        srand(time(0));
        int crit = m_dmg / 2;
        int critChance = 10 + (rand() % 100);
        if(critChance > 95){
            std::cout << getName() << " managed to do a Critical hit!!" << std::endl;
            return crit;
        }else{
            return 0;
        }
    }
    void Monster::setAttackName(std::string attackName) {
        m_attackName = attackName;
    }
    std::string Monster::getAttackName() {
        return m_attackName;
    }
    void Monster::setMonsterType(std::string type) {
        m_monster = type;
    }
    std::string Monster::getMonsterType() {
        return m_monster;
    }
    void Monster::dragonNames(int tier, int attType) {
        std::srand(time(0));
        if(tier == 1 && attType == 0){
            std::string DragonName[4] = {"Drogllis", "Annaphira", "Dracona", "Razen"};
            int randIndex = rand() % 4;
            setName("Dragon - " + DragonName[randIndex]);
        }else if(tier == 2 && attType == 0){
            std::string DragonName[4] = {"Firellis", "Wikora", "Annariona", "Zologia"};
            int randIndex = rand() % 4;
            setName("Dragon Elder - " + DragonName[randIndex]);
        }else if(tier == 3 && attType == 0){
            std::string DragonName[3] = {"Wiseria", "Bahamut", "Doom"};
            int randIndex = rand() % 3;
            setName("BOSS Dragon - " + DragonName[randIndex]);
        }
        if(tier == 0 && attType == 1){
            std::string AttackName[3] = {"Claw Attack", "Fire Breath"};
            int randIndex = rand() % 2;
            setAttackName(AttackName[randIndex]);
        }
    }
    void Monster::wolfNames(int tier, int attType){
        std::srand(time(0));
        if(tier == 1 && attType == 0) {
            std::string WolfName[1] = {"Wolf"};
            int randIndex = 0;
            setName(WolfName[randIndex]);
        }else if(tier == 2 && attType == 0){
            std::string WolfName[3] = {"Zonya", "Geros", "Gesa"};
            int randIndex = rand() % 3;
            setName("Wolf Leader - " + WolfName[randIndex]);
        }else if(tier == 3 && attType == 0){
            std::string WolfName[1] = {"Raiga"};
            int randIndex = 0;
            setName("Wolf BOSS - " + WolfName[randIndex]);
        }
        if(tier == 0 && attType == 1){
            std::string AttackName[3] = {"Claw Attack", "Bite Attack"};
            int randIndex = rand() % 2;
            setAttackName(AttackName[randIndex]);
        }
    }
    void Monster::goblinNames(int tier, int attType) {
        std::srand(time(0));
        if(tier == 1 && attType == 0){
            std::string GoblinName[1] = {"Goblin"};
            int randIndex = 0;
            setName(GoblinName[randIndex]);
         }else if(tier == 2 && attType == 0){
            std::string GoblinName[3] = {"Gardnermenace", "Longgobble", "Holmesfur"};
            int randIndex = rand() % 3;
            setName("Goblin Captain - " + GoblinName[randIndex]);
        }else if(tier == 3 && attType == 0){
            std::string GoblinName[2] = {"Fangwart Ballclaw", "RemEnd Clawson"};
            int randIndex = rand() % 2;
            setName("Goblin BOSS - " + GoblinName[randIndex]);
        }
        if(tier == 0 && attType == 1){
            std::string AttackName[3] = {"Swift Attack", "Sneak Attack"};
            int randIndex = rand() % 2;
            setAttackName(AttackName[randIndex]);
        }
    }
    void Monster::orcNames(int tier, int attType) {
        std::srand(time(0));
        if(tier == 1 && attType == 0){
        std::string OrcName[1] = {"Orc"};
        int randIndex = 0;
        setName(OrcName[randIndex]);
        }else if(tier == 2 && attType == 0){
            std::string OrcName[4] = {"Azcer", "Fosterzog", "Morenorms", "Harperolg"};
            int randIndex = rand() % 4;
            setName("Orc General - " + OrcName[randIndex]);
        }else if(tier == 3 && attType == 0){
            std::string OrcName[1] = {"Tusk"};
            int randIndex = 0;
            setName("Orc BOSS - " + OrcName[randIndex]);
        }
        if(tier == 0 && attType == 1){
            std::string AttackName[3] = {"Powered Attack", "Rampage Powered Attack"};
            int randIndex = rand() % 2;
            setAttackName(AttackName[randIndex]);
        }
    }
    void Monster::ogreNames(int tier, int attType) {
        std::srand(time(0));
        if(tier == 1 && attType == 0){
        std::string OgreName[1] = {"Ogre"};
        int randIndex = 0;
        setName(OgreName[randIndex]);
        }else if(tier == 2 && attType == 0){
            std::string OgreName[3] = {"Thudner", "Scostomp", "Sustink"};
            int randIndex = rand() % 3;
            setName("Ogre General - " + OgreName[randIndex]);
        }else if(tier == 3 && attType == 0){
            std::string OgreName[1] = {"Greenwell"};
            int randIndex = 0;
            setName("Ogre BOSS - " + OgreName[randIndex]);
        }
        if(tier == 0 && attType == 1){
            std::string AttackName[3] = {"Mace Attack", "Slam Barrage"};
            int randIndex = rand() % 2;
            setAttackName(AttackName[randIndex]);
        }
    }
    int Monster::getValue(int type) {
        if(type == 0) {
            return m_value;
        }else if(type == 1){
            return m_expValue;
        }
    }
    void Monster::setDefense(int defense) {
        m_defense = defense;
    }
    int Monster::getDefense() {
        return m_defense;
    }
    void Monster::setValue(int value, int type) {
        if(type == 0) {
            m_value = value + (rand() % value);
        }else if(type == 1){
            m_expValue = value + (rand() % value);
        }
    }
    void Monster::setLevel(int level) {
        m_lvl = level;
    }
    void Monster::randMonster() {
        std::srand(time(0));
        int randIndex = 1 + (rand() % 5);
        switch (randIndex) {
            case 1: { //DRAGON
                setMonsterType("dragon");
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
                        setLevel((rand() % 30) + 1);
                        setStrength( getLevel() + 25 + rand() % 50);
                        setVitality(getLevel() + 25 + rand() % 50);
                        setIntelligence(getLevel() + 25 + rand() % 50);
                        setAgility(getLevel() + 25 + rand() % 50);
                        setDefense(getLevel() + 25 + rand() % 50);
                        setHp(getVitality() * (1 + (rand() % 50)) + (rand() % 200));
                        setMp(getIntelligence() * (1 + (rand() % 50)) + (rand() % 200));
                        dragonNames(1,0);
                        setDmg(getStrength() * 5);
                        setValue(5,0);
                        setValue(1200,1);
                        break;
                    }
                    case 2: {
                        setLevel((rand() % 40) + 31);
                        setStrength(getLevel() + 35 + rand() % 70);
                        setVitality(getLevel() + 35 + rand() % 70);
                        setIntelligence(getLevel() + 35 + rand() % 70);
                        setAgility(getLevel() + 35 + rand() % 70);
                        setDefense(getLevel() + 35 + rand() % 70);
                        setHp(getVitality() * (1 + (rand() % 100)) + (rand() % 500));
                        setMp(getIntelligence() * (1 + (rand() % 100)) + (rand() % 500));
                        dragonNames(2,0);
                        setDmg(getStrength() * 5);
                        setValue(20,0);
                        setValue(2600,1);
                        break;
                    }
                    case 3: {
                        setLevel((rand() % 30) + 71);
                        setStrength(getLevel() + 50 + rand() % 100);
                        setVitality(getLevel() + 50 + rand() % 100);
                        setIntelligence(getLevel() + 50 + rand() % 100);
                        setAgility(getLevel() + 50 + rand() % 100);
                        setDefense(getLevel() + 50 + rand() % 100);
                        setHp(getVitality() * (1 + (rand() % 200)) + (rand() % 1000));
                        setMp(getIntelligence() * (1 + (rand() % 200)) + (rand() % 1000));
                        dragonNames(3,0);
                        setDmg(getStrength() * 5);
                        setValue(40,0);
                        setValue(5600,1);
                        break;
                    }
                    default:
                        std::cout << "Error occured!!" << std::endl;
                }
                break;
            }
            case 2: { //WOLF
                setMonsterType("wolf");
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
                        setLevel((rand() % 30) + 1);
                        setStrength(getLevel() + 15 + rand() % 10);
                        setVitality(getLevel() + 10 + rand() % 10);
                        setIntelligence(getLevel() + 0 + rand() % 10);
                        setAgility(getLevel() + 20 + rand() % 10);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 10)) + (rand() % 10));
                        setMp(getIntelligence() * ( 1 + (rand() % 10)) + (rand() % 10));
                        wolfNames(1,0);
                        setDmg(getStrength() * 5);
                        setValue(5,0);
                        setValue(200,1);
                        break;
                    }
                    case 2: {
                        setLevel((rand() % 30) + 31);
                        setStrength(getLevel() + 15 + rand() % 20);
                        setVitality(getLevel() + 10 + rand() % 20);
                        setIntelligence(getLevel() + 0 + rand() % 20);
                        setAgility(getLevel() + 20 + rand() % 20);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 20)) + (rand() % 20));
                        setMp(getIntelligence() * ( 1 + (rand() % 20)) + (rand() % 20));
                        wolfNames(2,0);
                        setDmg(getStrength() * 5);
                        setValue(20,0);
                        setValue(500,1);
                        break;
                    }
                    case 3: {
                        setLevel((rand() % 30) + 71);
                        setStrength(getLevel() + 15 + rand() % 30);
                        setVitality(getLevel() + 10 + rand() % 30);
                        setIntelligence(getLevel() + 0 + rand() % 30);
                        setAgility(getLevel() + 20 + rand() % 30);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 20)) + (rand() % 30));
                        setMp(getIntelligence() * ( 1 + (rand() % 20)) + (rand() % 30));
                        wolfNames(3,0);
                        setDmg(getStrength() * 5);
                        setValue(40,0);
                        setValue(1300,1);
                        break;
                    }
                    default: std::cout << "Error occured!!" << std::endl;
                }
            }
            case 3:{ //ORC
                setMonsterType("orc");
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
                        setLevel((rand() % 30) + 1);
                        setStrength(getLevel() + 10 + rand() % 10);
                        setVitality(getLevel() + 10 + rand() % 10);
                        setIntelligence(getLevel() + 2 + rand() % 10);
                        setAgility(getLevel() + 5 + rand() % 10);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 5)) + (rand() % 10));
                        setMp(getIntelligence() * ( 1 + (rand() % 5)) + (rand() % 10));
                        orcNames(1,0);
                        setDmg(getStrength() * 5);
                        setValue(5,0);
                        setValue(200,1);
                        break;
                    }
                    case 2: {
                        setLevel((rand() % 30) + 31);
                        setStrength(getLevel() + 15 + rand() % 10);
                        setVitality(getLevel() + 15 + rand() % 10);
                        setIntelligence(getLevel() + 2 + rand() % 10);
                        setAgility(getLevel() + 8 + rand() % 10);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 15)) + (rand() % 15));
                        setMp(getIntelligence() * ( 1 + (rand() % 15)) + (rand() % 15));
                        orcNames(2,0);
                        setDmg(getStrength() * 5);
                        setValue(20,0);
                        setValue(600,1);
                        break;
                    }
                    case 3: {
                        setLevel((rand() % 30) + 71);
                        setStrength(getLevel() + 25 + rand() % 20);
                        setVitality(getLevel() + 20 + rand() % 20);
                        setIntelligence(getLevel() + 10 + rand() % 20);
                        setAgility(getLevel() + 15 + rand() % 20);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 30)) + (rand() % 20));
                        setMp(getIntelligence() * ( 1 + (rand() % 30)) + (rand() % 20));
                        orcNames(3,0);
                        setDmg(getStrength() * 5);
                        setValue(40,0);
                        setValue(1000,1);
                        break;
                    }
                    default: std::cout << "Error occured!!" << std::endl;
                }
            }
            case 4:{ //OGRE
                setMonsterType("ogre");
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
                        setLevel((rand() % 30) + 1);
                        setStrength(getLevel() + 30 + rand() % 20);
                        setVitality(getLevel() + 20 + rand() % 10);
                        setIntelligence(getLevel() + 0 + rand() % 10);
                        setAgility(getLevel() + 3 + rand() % 10);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 50)) + (rand() % 10));
                        setMp(getIntelligence() * ( 1 + (rand() % 50)) + (rand() % 10));
                        ogreNames(1,0);
                        setDmg(getStrength() * 5);
                        setValue(5,0);
                        setValue(350,1);
                        break;
                    }
                    case 2: {
                        setLevel((rand() % 30) + 31);
                        setStrength(getLevel() + 35 + rand() % 20);
                        setVitality(getLevel() + 20 + rand() % 20);
                        setIntelligence(getLevel() + 5 + rand() % 20);
                        setAgility(getLevel() + 10 + rand() % 20);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 50)) + (rand() % 20));
                        setMp(getIntelligence() * ( 1 + (rand() % 50)) + (rand() % 20));
                        ogreNames(2,0);
                        setDmg(getStrength() * 5);
                        setValue(20,0);
                        setValue(700,1);
                        break;
                    }
                    case 3: {
                        setLevel((rand() % 30) + 71);
                        setStrength(getLevel() + 40 + rand() % 30);
                        setVitality(getLevel() + 30 + rand() % 30);
                        setIntelligence(getLevel() + 10 + rand() % 30);
                        setAgility(getLevel() + 12 + rand() % 30);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 50)) + (rand() % 30));
                        setMp(getIntelligence() * ( 1 + (rand() % 50)) + (rand() % 30));
                        ogreNames(3,0);
                        setDmg(getStrength() * 5);
                        setValue(40,0);
                        setValue(1100,1);
                        break;
                    }
                    default: std::cout << "Error occured!!" << std::endl;
                }
            }
            case 5:{ //GOBLIN
                setMonsterType("goblin");
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
                        setLevel((rand() % 30) + 1);
                        setStrength(getLevel() + 5 + rand() % 10);
                        setVitality(getLevel() + 2 + rand() % 10);
                        setIntelligence(getLevel() + 2 + rand() % 10);
                        setAgility(getLevel() + 5 + rand() % 10);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 50)) + (rand() % 10));
                        setMp(getIntelligence() * ( 1 + (rand() % 50)) + (rand() % 10));
                        goblinNames(1,0);
                        setDmg(getStrength() * 5);
                        setValue(5,0);
                        setValue(250,1);
                        break;
                    }
                    case 2: {
                        setLevel((rand() % 30) + 31);
                        setStrength(getLevel() + 10 + rand() % 20);
                        setVitality(getLevel() + 5 + rand() % 20);
                        setIntelligence(getLevel() + 5 + rand() % 20);
                        setAgility(getLevel() + 10 + rand() % 20);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 50)) + (rand() % 20));
                        setMp(getIntelligence() * ( 1 + (rand() % 50)) + (rand() % 20));
                        goblinNames(2,0);
                        setDmg(getStrength() * 5);
                        setValue(20,0);
                        setValue(450,1);
                        break;
                    }
                    case 3: {
                        setLevel((rand() % 30) + 71);
                        setStrength(getLevel() + 20 + rand() % 30);
                        setVitality(getLevel() + 10 + rand() % 30);
                        setIntelligence(getLevel() + 10 + rand() % 30);
                        setAgility(getLevel() + 15 + rand() % 30);
                        setDefense(getLevel());
                        setHp(getVitality() * ( 1 + (rand() % 50)) + (rand() % 30));
                        setMp(getIntelligence() * ( 1 + (rand() % 50)) + (rand() % 30));
                        goblinNames(3,0);
                        setDmg(getStrength() * 5);
                        setValue(40,0);
                        setValue(850,1);
                        break;
                    }
                    default: std::cout << "Error occured!!" << std::endl;
                }
            }
            default: std::cout << "" << std::endl;
        }
    }