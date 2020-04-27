//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include <string>
#include "../factory/AbstractFactory.h"
#include "LevelManager.h"

namespace Game {
    class Game {
    public:
        Game(AbstractFactory *_A);
        virtual ~Game();
        void Run();
        void updateStatistics();

    private:
        AbstractFactory *A;
        ConfigReader *configReader;
        Background *bg;
        LevelManager *levelManager;
        time_t start;
    };
}

#endif //PROJECT_GAME_H
