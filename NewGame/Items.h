//
// Created by Nguyen Viet Hoang on 22/12/2019.
//

#ifndef GAME_ITEMS_H
#define GAME_ITEMS_H

#include <iostream>

class Items {
protected:
    int m_dmg;
    int m_def;
    int m_agility;
    int m_durability;
    std::string m_name;
    int m_price;
    int m_index;

public:
    Items(int dmg, int def, int agi, int dur, const std::string& name, int price, int index);
    virtual int getDamage() const;
    virtual int getDefense() const;
    virtual int getAgility() const;
    virtual int getDurability() const;
    virtual int getPrice() const;
    virtual std::string getName() const;
    virtual int getIndex() const;
};



#endif //GAME_ITEMS_H
