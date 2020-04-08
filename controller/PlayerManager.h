//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_PLAYERMANAGER_H
#define PROJECT_PLAYERMANAGER_H

#include "../factory/AbstractFactory.h"
#include "KeyHandler.h"

namespace Game {
    class PlayerManager {
    public:
        PlayerManager();
        PlayerManager(AbstractFactory *abstractFactory);
        PlayerShip *getPlayerShip() const;
        void runPlayer();
        void setLife();
        void moveShip();

    private:
        AbstractFactory *abstractFactory;
        PlayerShip *playerShip;
        Life *life;
        KeyHandler *keyHandler;
        Timer *timer;
        int SCREEN_WIDTH = 950;
        std::string shipPath = "";
    };
}

#endif //PROJECT_PLAYERMANAGER_H
