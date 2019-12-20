//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#include "Core.h"

Core::Core() {
    m_running = true;
    m_input = "";
}

int Core::commands(std::string input) {
    m_commands.insert(std::pair<std::string,int>("Exit",1));
    m_commands.insert(std::pair<std::string,int>("Stats",2));
    m_commands.insert(std::pair<std::string,int>("Char",3));
    m_commands.insert(std::pair<std::string,int>("Bo",4));
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
    std::string input;
    Character* player = new Character();
    Fight* fight = new Fight();
    Monster* monster = new Monster();
    player->setName();
    player->chooseWeapon(player);
    while(m_running){
        std::cout << std::endl;
        std::cout << "Enter your command: ";
        std::cin >> input;
        input[0] = std::toupper(input[0]);
        switch(commands(input)){
            case 1:
                m_running = false;
                break;
            case 2:
                player->showStats();
                break;
            case 3:
                player->showChar();
                break;
            default:
                std::cout << "Command " << input << " does not exist." << std::endl;
        }
    }
}