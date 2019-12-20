//
// Created by Lenovo on 14.12.2019.
//

#include "Weapon.h"

    Weapon::Weapon(int dmg, const std::string& name) {
        m_dmg = dmg;
        m_name = name;
    }
    int Weapon::getDamage() const {
        return m_dmg;
    }
    std::string Weapon::getName() const {
        return m_name;
    }
