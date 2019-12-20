//
// Created by Lenovo on 14.12.2019.
//

#include "Fight.h"


    void Fight::line(){
        std::cout << "--------------------------\n";
    }
    int Fight::getFight(Monster* monster, Character* character){
        int hp = monster->getHp();
        while(hp > 0) {
            std::cout << "Weapon: " << character->getWeaponName() << std::endl;
            std::cout << monster->getName() << " " << hp << std::endl;
            std::cin >> input;
            if (input == "a" || input == "A"){
                hp -= character->getDamage();
                std::cout << "Name: " << character->getName() << std::endl;
                std::cout << "HP: " << character->getHp() << std::endl;
                std::cout << "MP: " << character->getMp() << std::endl;
                std::cout << "Dmg: " << character->getDamage() << std::endl;
                std::cout << "Base Dmg: " << character->getBaseDmg() << std::endl;
            }
        }
        if(hp < 0){
            std::cout << monster->getName() << " " << hp << " is dead.\n";
            std::cout << "Overkill!!\n";
            monster->setHp(hp);
        }else {
            std::cout << monster->getName() << " " << hp << " is dead.\n";
            monster->setHp(hp);
        }
        line();

        return hp;
    }
