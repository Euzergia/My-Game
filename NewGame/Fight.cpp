//
// Created by Lenovo on 14.12.2019.
//

#include "Fight.h"


    void Fight::line(){
        std::cout << "-----------------------------\n";
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
    int Fight::getFight(Monster* monster, Character* character) {
        int run = 0;
        int hp = monster->getHp();
        int mpDrain = (character->getMpLimit() / 4);
        while (hp > 0) {
            line();
            std::cout << std::endl;
            std::cout << monster->getName() << " " << hp << " HP" << std::endl;
            std::cout << character->getName() << " " << character->getHp() << " HP | " << character->getMp() << " MP"
                      << std::endl;
            std::cout << "A: Attack" << std::endl;
            std::cout << "B: Magic" << std::endl;
            std::cout << "C: Potion (" << character->getPotion() << "/" << character->getPotionLimit() << ")"
                      << std::endl;
            std::cin >> input;
            if (input == "a" || input == "A") {
                std::cout << std::endl;
                hp -= character->getDamage();
                if (hp > 0) {
                    std::cout << std::endl;
                    attackName(monster);
                    std::cout << monster->getName() << " used " << monster->getAttackName() << std::endl;
                    character->setHp(character->getHp() - monster->getDmg());
                }
                if(character->getHp() <= 0){
                    hp = 0;
                }
                if(character->getHp() < (character->getHpLimit())){
                    character->setHp(character->getHp() + character->getHpRecovery());
                }
                if(character->getMp() < (character->getMpLimit())) {
                    character->setMp(character->getMp() + character->getMpRecovery());
                }
            } else if ((input == "b" || input == "B")) {
                std::cout << std::endl;
                if(((character->getMp() - mpDrain) > 0)) {
                    hp -= character->getDamage() * (character->getIntelligence() - (character->getIntelligence() / 2));
                    character->setMp(character->getMp() - mpDrain);
                    if (hp > 0) {
                        std::cout << std::endl;
                        attackName(monster);
                        std::cout << monster->getName() << " used " << monster->getAttackName() << std::endl;
                        character->setHp(character->getHp() - monster->getDmg());
                    }
                    if(character->getHp() <= 0){
                        hp = 0;
                    }
                    if (character->getHp() < (character->getHpLimit())) {
                        character->setHp(character->getHp() + character->getHpRecovery());
                    }
                    if (character->getMp() < (character->getMpLimit())) {
                        character->setMp(character->getMp() + character->getMpRecovery());
                    }
                }else{
                    std::cout << "You do not have enough mp!!" << std::endl;
                }
            } else if (input == "c" || input == "C") {
                character->minusPotion(0);
            } else if (input == "exit" || input == "Exit") {
                exit(0);
            } else if (input == "run" || input == "Run") {
                run = 1;
                hp = 0;
            } else if (input == "help" || input == "Help") {
                const char separator = ' ';
                const int nameWidth = 15;
                int switchForHelp = 1;
                std::string inputForHelp;
                while (switchForHelp == 1) {
                    std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Help window:"
                              << std::endl;
                    std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Commands:";
                    std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "Action:" << std::endl;
                    std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "run ";
                    std::cout << std::setw(nameWidth) << std::left << std::setfill(separator)
                              << "run away from the fight " << std::endl;
                    std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "exit ";
                    std::cout << std::setw(nameWidth) << std::left << std::setfill(separator) << "leave the game "
                              << std::endl;

                    std::cout << std::endl;
                    std::cout << "Write \"esc\" to leave help desk." << std::endl;
                    std::cin >> inputForHelp;
                    if (inputForHelp == "esc" || inputForHelp == "Esc") {
                        switchForHelp = 0;
                    }
                }
            }
        }
        if (run == 1 && hp == 0) {
            std::cout << "You ran away." << std::endl;
        } else if(character->getHp() <= 0 && hp == 0){
            bool rip = true;
            int cin;
            std::cout << std::endl;
            std::cout << character->getName() << " " << character->getHp() << " HP | " << character->getMp() << " MP"
                      << std::endl;
            std::cout << std::endl;
            std::cout << "You died. Your adventure is over." << std::endl;
            while(rip){
                std::cout << "Restart the game!!" << std::endl;
                std::cin >> cin;
                if (std::cin.fail()) {
                    line();
                    std::cout << std::endl;
                    std::cout << "You must enter a number!! Enter 0 - 5." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << std::endl;
                } else {
                    switch(cin){
                        case 0:
                            std::cout << "Vaserion: \"Mess with us and we'll do something worse than kill you. We'll kill your children.\"" << std::endl;
                            break;
                        case 1:
                            std::cout << "Randaror: \"If I ever get the chance to betray you, I will. If the opportunity arises to pay you back, I'll take it. You'll never be able to trust me..\"" << std::endl;
                            break;
                        case 2:
                            std::cout << "Zevion: \"What if I take you apart and turn you into a toaster oven, how would you like that tin can?\"" << std::endl;
                            break;
                        case 3:
                            std::cout << "Ugher: \"Don't fuck with me, fellas. This ain't my first time at the rodeo.\"" << std::endl;
                            break;
                        case 4:
                            std::cout << "Crowen: \"Keep your eyes open, Fireheart. Keep your ears pricked. Keep looking behind you. Because one day I'll find you, and then you'll be crowfood.\"" << std::endl;
                            break;
                        case 5:
                            std::cout << "Jangeo: \"Look how we take your children and sacrifice them and there’s nothing you can do. If you lift a finger, we will destroy every last one of you. Just as we did in Ravanor.\"" << std::endl;
                            break;
                        default: std:: cout << "Wrong input!!" << std::endl;
                    }
                }
            }
        }else if (hp < 0) {
            std::cout << std::endl;
            std::cout << "Overkill!!\n";
            std::cout << monster->getName() << " " << hp << " HP is dead.\n";
            monster->setHp(hp);
            character->exp(monster);
            character->reward(monster);
        } else{
            std::cout << character->getName() << " " << character->getHp() << " HP | " << character->getMp() << " MP" << std::endl;
            std::cout << std::endl;
            std::cout << monster->getName() << " " << hp << " HP is dead.\n";
            monster->setHp(hp);
            character->exp(monster);
            character->reward(monster);
        }

        return hp;
    }
