//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#include "Armor.h"

    Armor::Armor(int dmg, int def, int agi, int dur, const std::string& name, int price):Items(dmg, def, agi, dur, name, price) {
        m_def = def;
        m_name = name;
    }
    int Armor::getDefense() const {
        return m_def;
    }
    std::string Armor::getName() const{
        return m_name;
    }