cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game main.cpp Weapon.cpp Weapon.h Monster.cpp Monster.h Character.cpp Character.h Fight.cpp Fight.h Dragon.cpp Dragon.h Core.cpp Core.h Armor.cpp Armor.h Items.cpp Items.h Helmet.cpp Helmet.h Gloves.cpp Gloves.h Boots.cpp Boots.h Quest.h)