//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#include "Armor.h"

    Armor::Armor(int dmg, int def, int agi, int dur, int mpRecovery, int hpRecovery, const std::string& name, int price, int index):Items(dmg, def, agi, dur, mpRecovery, hpRecovery, name, price, index) {
        m_def = def;
        m_name = name;
    }
    int Armor::getDefense() const {
        return m_def;
    }
    std::string Armor::getName() const{
        return m_name;
    }