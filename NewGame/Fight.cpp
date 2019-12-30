//
// Created by Lenovo on 14.12.2019.
//

#include "Fight.h"


    void Fight::line(){
        std::cout << "--------------------------\n";
    }
    void Fight::attackName(Monster *monster) {
        if(monster->getMonsterType() == "dragon"){
            monster->dragonNames(0,1);
        }else if(monster->getMonsterType() == "wolf"){
            monster->wolfNames(0,1);
        }else if(monster->getMonsterType() == "orc"){
            monster->orcNames(0,1);
        }else if(monster->getMonsterType() == "ogre"){
            monster->ogreNames(0,1);
        }else if(monster->getMonsterType() == "goblin"){
            monster->goblinNames(0,1);
        }
    }
    int Fight::getFight(Monster* monster, Character* character){
        int run = 0;
        int hp = monster->getHp();
        while(hp > 0) {
            std::cout << monster->getName() << " " << hp << " HP" << std::endl;
            std::cout << character->getName() << " " << character->getHp() << " HP" << std::endl;
            std::cout << "A: Attack" << std::endl;
            std::cout << "B: Magic" << std::endl;
            std::cout << "C: Potion" << std::endl;
            std::cin >> input;
            if (input == "a" || input == "A"){
                hp -= character->getDamage();
                std::cout << std::endl;
                attackName(monster);
                std::cout << monster->getName() << " used " << monster->getAttackName() << std::endl;
                character->setHp(character->getHp() - monster->getDmg());
            }else if(input == "b" || input == "B"){
                hp -= character->getDamage() * 2;
                std::cout << std::endl;
                attackName(monster);
                std::cout << monster->getName() << " used " << monster->getAttackName() << std::endl;
                character->setHp(character->getHp() - monster->getDmg());
            }else if(input == "c" || input == "C") {

            }else if(input == "exit" || input == "Exit"){
                    exit(0);
            }else if(input == "run" || input == "Run"){
                run = 1;
                hp = 0;
            }else if(input == "help" || input == "Help"){
                const char separator = ' ';
                const int nameWidth = 15;
                int switchForHelp = 1;
                std::string inputForHelp;
                while(switchForHelp == 1) {
                   std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Help window:" << std::endl;
                   std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Commands:";
                   std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Action:" << std::endl;
                   std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "run ";
                   std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "run away from the fight " << std::endl;
                   std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "exit ";
                   std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "leave the game " << std::endl;

                   std::cout << std::endl;
                   std::cout << "Write \"esc\" to leave help desk." << std::endl;
                   std::cin >> inputForHelp;
                   if(inputForHelp == "esc" || inputForHelp == "Esc"){
                       switchForHelp = 0;
                   }
               }
            }
        }
        if(run == 1 && hp == 0){
            std::cout << "You ran away." << std::endl;
        }else if(hp < 0){
            std::cout << "Overkill!!\n";
            std::cout << monster->getName() << " " << hp << " HP is dead.\n";
            monster->setHp(hp);
            character->reward(monster);
        }else{
            std::cout << monster->getName() << " " << hp << " HP is dead.\n";
            monster->setHp(hp);
            character->reward(monster);
        }

        return hp;
    }
