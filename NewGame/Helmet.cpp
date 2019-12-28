//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#include "Helmet.h"

Helmet::Helmet(int dmg, int def, int agi, int dur, const std::string& name, int price):Items(dmg, def, agi, dur, name, price) {
}
int Helmet::getDamage() const {
    return m_dmg;
}
std::string Helmet::getName() const {
    return m_name;
}