//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#include "Boots.h"

Boots::Boots(int dmg, int def, int agi, int dur, const std::string& name, int price, int index):Items(dmg, def, agi, dur, name, price, index) {
}
int Boots::getDefense() const {
    return m_def;
}
std::string Boots::getName() const{
    return m_name;
}