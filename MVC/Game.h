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
    std::string michielAlien = "../assets/michiel.png";
    std::string rubenAlien = "../assets/ruben.png";
    std::string thomasAlien = "../assets/thomas.png";
    std::string cliffAlien = "../assets/cliff.png";
};


#endif //PROJECT_GAME_H
