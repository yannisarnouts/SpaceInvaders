//
// Created by Gebruiker on 22/04/2020.
//

#ifndef SPACEINVADERS_LEVELMANAGER_H
#define SPACEINVADERS_LEVELMANAGER_H


#include "ConfigReader.h"
#include "PlayerManager.h"
#include "CanonManager.h"
#include "AlienManager.h"
#include "BonusManager.h"

namespace Game {
    class LevelManager {
    public:
        LevelManager();
        LevelManager(ConfigReader *configReader, AbstractFactory *abstractFactory);
        virtual ~LevelManager();
        int getLevel() const;
        void setLevel(int level);

        PlayerManager *getPlayerManager() const;

        PlayerShip *getPlayerShip() const;

        CanonManager *getCanon() const;

        AlienManager *getAliens() const;

        BonusManager *getBonusManager() const;

    private:
        int level;
        AbstractFactory *A;
        ConfigReader *configReader;
        PlayerManager *playerManager;
        PlayerShip *playerShip;
        CanonManager *canon;
        AlienManager *aliens;
        BonusManager *bonusManager;
    };
}

#endif //SPACEINVADERS_LEVELMANAGER_H
