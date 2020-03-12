//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include <string>
#include "../factory/AbstractFactory.h"

class Game {
public:
    Game(AbstractFactory *_A);
    void Run();

private:
    AbstractFactory *A;
    std::string shipPath = "../assets/spaceship.png";
    std::string bgPath = "../assets/bg.jpg";
};


#endif //PROJECT_GAME_H
