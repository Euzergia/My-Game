//
// Created by Lenovo on 14.12.2019.
//

#include "Weapon.h"

    Weapon::Weapon(int dmg, int def, int agi, int dur, const std::string& name):Items(dmg, def, agi, dur, name) {
    }
    int Weapon::getDamage() const {
        return m_dmg;
    }
    std::string Weapon::getName() const {
        return m_name;
    }
