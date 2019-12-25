//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#ifndef GAME_CORE_H
#define GAME_CORE_H

#include "Character.h"
#include "Monster.h"
#include "Dragon.h"
#include "Fight.h"
#include <map>

class Core {
    //std::srand(time(nullptr));
    //int random = rand() % 2;
    bool m_running;
    std::string m_input;
    std::map<std::string, int> m_commands;
public:
    Core();
    void run();
    void restart(Monster **monster);
    int commands(std::string input);

};


#endif //GAME_CORE_H
