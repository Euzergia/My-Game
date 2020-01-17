//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#include "Items.h"

Items::Items(int dmg, int def, int agi, int dur, int mpRecovery, int hpRecovery, const std::string &name, int price, int index) {
    m_dmg = dmg;
    m_name = name;
    m_agility = agi;
    m_durability = dur;
    m_def = def;
    m_price = price;
    m_index = index;
    m_hpRecovery = hpRecovery;
    m_mpRecovery = mpRecovery;
}
int Items::getDefense() const {
    return m_def;
}
int Items::getIndex() const {
    return m_index;
}
std::string Items::getName() const {
    return m_name;
}
int Items::getAgility() const {
    return m_agility;
}
int Items::getDamage() const {
    return m_dmg;
}
int Items::getDurability() const {
    return m_durability;
}
int Items::getPrice() const {
    return  m_price;
}
int Items::getHpRecovery() {
    return m_hpRecovery;
}
int Items::getMpRecovery() {
    return m_mpRecovery;
}
