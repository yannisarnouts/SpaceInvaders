//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_PLAYERMANAGER_H
#define PROJECT_PLAYERMANAGER_H

#include "../factory/AbstractFactory.h"
#include "KeyHandler.h"
#include "ConfigReader.h"

namespace Game {
    class PlayerManager {
    public:
        PlayerManager();
        PlayerManager(AbstractFactory *abstractFactory, ConfigReader *configReader);
        PlayerShip *getPlayerShip() const;
        void runPlayer();
        void setLife();
        void moveShip();
        void initShip();

    private:
        AbstractFactory *abstractFactory;
        PlayerShip *playerShip;
        Life *life;
        KeyHandler *keyHandler;
        Timer *timer;
        ConfigReader *configReader;
    };
}

#endif //PROJECT_PLAYERMANAGER_H
