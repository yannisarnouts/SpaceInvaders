//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "../factory/AbstractFactory.h"

class Game {
public:
    Game(AbstractFactory *_A);
    void Run();

private:
    AbstractFactory *A;
};


#endif //PROJECT_GAME_H
