//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#include "Core.h"

Core::Core() {
    m_running = true;
    m_input = "";
}

void Core::clear() {
    std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
    std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
    std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
    std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
    std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
    std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
}

int Core::commands(std::string input) {
    m_commands.insert(std::pair<std::string,int>("Exit",1));
    m_commands.insert(std::pair<std::string,int>("Stats",2));
    m_commands.insert(std::pair<std::string,int>("Inv",3));
    m_commands.insert(std::pair<std::string,int>("Help",4));
    m_commands.insert(std::pair<std::string,int>("Char",5));
    m_commands.insert(std::pair<std::string,int>("Fight",6));
    m_commands.insert(std::pair<std::string,int>("Shop",7));
    m_commands.insert(std::pair<std::string,int>("Clear",8));
    m_commands.insert(std::pair<std::string,int>("Test",9));
    m_commands.insert(std::pair<std::string,int>("Quest",10));

    m_input = input;
    std::map<std::string, int>::iterator itr;
    for(auto itr = m_commands.find(input); itr == m_commands.find(input);){
        if(itr == m_commands.find(input)){
            return itr->second;
        }else{
            return 0;
        }
    }
}

void Core::run() {
    bool onOff = false;
    std::string input;
    srand(time(0));
    int randIndex = rand() % 10;
    Character* player = new Character();
    Fight* fight = new Fight();
    Monster* monster = new Monster();
    player->setName();
    player->itemsChar();
    while(m_running){
        std::cout << std::endl;
        std::cout << "Enter your command: ";
        std::cin >> input;
        std::cout << std::endl;
        input[0] = std::toupper(input[0]);
        switch(commands(input)){
            case 1:
                m_running = false;
                delete monster;
                delete fight;
                delete player;
                break;
            case 2:
                player->showStats();
                break;
            case 3:
                player->showInventory();
                break;
            case 4:
                player->showHelp();
                break;
            case 5:
                player->showChar();
                break;
            case 6:
                monster->randMonster();
                fight->getFight(monster, player);
                break;
            case 7:
                player->chooseWeapon(player);
                break;
            case 8:
                clear();
                break;
            case 9: {
                if(!onOff) {
                    player->testMode(0);
                    onOff = true;
                }else if(onOff){
                    player->testMode(1);
                    onOff = false;
                }
                break;
            }
            case 10:
                player->quest();
                player->showQuests();
                break;
            default:
                std::cout << "Command " << input << " does not exist." << std::endl;
        }
    }
}