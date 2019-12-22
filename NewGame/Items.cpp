//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#include "Items.h"

Items::Items(int dmg, int def, int agi, int dur, const std::string &name) {
    m_dmg = dmg;
    m_name = name;
    m_agility = agi;
    m_durability = dur;
    m_def = def;
}
int Items::getDefense() const {
    return m_def;
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
