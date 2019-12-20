//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#include "Armor.h"

Armor::Armor(int def, const std::string& name) {
    m_def = def;
    m_name = name;
}
int Armor::getDef() const {
    return m_def;
}
std::string Armor::getName() const{
    return m_name;
}