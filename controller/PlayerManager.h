//
// Created by Gebruiker on 6/04/2020.
//
/*
 * PlayerManager
 * Manages PlayerShip
 */
#ifndef PROJECT_PLAYERMANAGER_H
#define PROJECT_PLAYERMANAGER_H

#include "../factory/AbstractFactory.h"
#include "KeyHandler.h"
#include "ConfigReader.h"

namespace Game {
    class PlayerManager {
    public:
        PlayerManager();
        PlayerManager(AbstractFactory *abstractFactory, ConfigReader *configReader, int initLife);
        virtual ~PlayerManager();
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
        ConfigReader *configReader;
    };
}

#endif //PROJECT_PLAYERMANAGER_H
