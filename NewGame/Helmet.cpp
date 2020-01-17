//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#include "Helmet.h"

Helmet::Helmet(int dmg, int def, int agi, int dur, int mpRecovery, int hpRecovery, const std::string& name, int price, int index):Items(dmg, def, agi, dur, mpRecovery, hpRecovery, name, price, index) {
}
int Helmet::getDamage() const {
    return m_dmg;
}
std::string Helmet::getName() const {
    return m_name;
}
