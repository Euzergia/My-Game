//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#include "Gloves.h"

Gloves::Gloves(int dmg, int def, int agi, int dur, int mpRecovery, int hpRecovery, const std::string& name, int price, int index):Items(dmg, def, agi, dur, mpRecovery, hpRecovery, name, price, index) {
}
int Gloves::getDefense() const {
    return m_def;
}
std::string Gloves::getName() const{
    return m_name;
}