//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#include "Gloves.h"

Gloves::Gloves(int dmg, int def, int agi, int dur, const std::string& name, int price):Items(dmg, def, agi, dur, name, price) {
}
int Gloves::getDefense() const {
    return m_def;
}
std::string Gloves::getName() const{
    return m_name;
}