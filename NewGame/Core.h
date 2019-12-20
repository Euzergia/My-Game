//
// Created by Nguyen Viet Hoang on 20/12/2019.
//

#ifndef GAME_CORE_H
#define GAME_CORE_H


class Core {
    std::srand(time(nullptr));
    int random = rand() % 2;
    bool again = false;
    std::string input;
    std::string playerName;
    Character* player = new Character();
    switch(random){
        case 1: return Dragon(new monster);
    }
    Fight* fight = new Fight;
    player->setName();
    player->chooseWeapon(player);
    fight->getFight(monster, player);
    delete monster;
    std::cout << "Do you want to fight another monster??\n" << "A: Yes\n" << "B: No\n";
    std::cin >> input;
    if(input == "a" || input == "A"){
        again = true;
        while(again){
            Monster* monster = new Monster();
            while(monster->getHp() > 0){
                fight->getFight(monster, player);
            }
            delete monster;
            std::cout << "Do you want to fight another monster??\n" << "A: Yes\n" << "B: No\n";
            std::cin >> input;
            if(input == "b" || input == "B"){
                again = false;
                std::cout << "The game has ended." << std::endl;
            }
        }
    }else {
        std::cout << "The game has ended.\n";
    }

    delete player;
    delete monster;
    delete fight;

};


#endif //GAME_CORE_H
