//
// Created by Lenovo on 14.12.2019.
//

#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include <iostream>


class Weapon {
private:
    int m_dmg;
    std::string m_name;

public:
    Weapon(int dmg, const std::string& name);
    int getDamage() const;
    std::string getName() const;
};


#endif //GAME_WEAPON_H
