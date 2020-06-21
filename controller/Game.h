//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include <string>
#include "../factory/AbstractFactory.h"
#include "LevelManager.h"
#include "FileWriter.h"

namespace Game {
    class Game {
    public:
        Game(AbstractFactory *_A);
        virtual ~Game();
        void Run();
        void updateStatistics();
        void startGame();

    private:
        AbstractFactory *A;
        ConfigReader *configReader;
        Background *bg;
        LevelManager *levelManager;
        Timer *timer;
        FileWriter *fileWriter;
        bool won = false;
    };
}

#endif //PROJECT_GAME_H
