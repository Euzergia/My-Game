//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include <iostream>

class Armor {
private:
    int m_def;
    std::string m_name;

public:
    Armor(int def, const std::string& name);
    int getDef() const;
    std::string getName() const;
};


#endif //GAME_ARMOR_H
