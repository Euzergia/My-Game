//
// Created by Lenovo on 14.12.2019.
//

#include "Dragon.h"

Dragon::Dragon() {
    m_strength = 150;
    m_agility = 120;
    m_vitality = 100;
    m_intelligence = 115;
    m_hp = m_vitality * 100;
    m_mp = m_intelligence * 100;
}
std::string Dragon::getName(){
    m_monsterName = "Dragon";
    return m_monsterName;
}
