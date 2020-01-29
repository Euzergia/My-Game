//
// Created by Nguyen Viet Hoang on 1/29/2020.
//
#include <iostream>
#include "Items.h"

#ifndef GAME_QUEST_H
#define GAME_QUEST_H

struct Quest{
    int m_expectedNumber;
    std::string m_text;
    Items* m_item;
    int m_goldReward;
    int m_count;
};

#endif //GAME_QUEST_H
