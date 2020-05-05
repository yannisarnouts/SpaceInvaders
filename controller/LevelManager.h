//
// Created by Gebruiker on 22/04/2020.
//
/*
 * Manage the level
 */
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
        LevelManager(ConfigReader *configReader, AbstractFactory *abstractFactory, Timer *timer);
        virtual ~LevelManager();
        PlayerManager *getPlayerManager() const;
        PlayerShip *getPlayerShip() const;
        CanonManager *getCanon() const;
        AlienManager *getAliens() const;
        BonusManager *getBonusManager() const;
        void createLevel();
        bool isHasWon() const;
        void setHasWon(bool hasWon);
        int getScore() const;
        void setScore(int score);
        int getBonusses() const;
        void setBonusses(int bonusses);
        int getShipLife() const;
        void setShipLife(int shipLife);
        int getAliensKilled() const;
        void setAliensKilled(int aliensKilled);
        int getBulletsFired() const;
        void setBulletsFired(int bulletsFired);
        Level *getLevel() const;
        void setLevel(Level *level);
        void runLevel();
        void cleanLevel();

    private:
        Level *level;
        AbstractFactory *A;
        ConfigReader *configReader;
        PlayerManager *playerManager;
        PlayerShip *playerShip;
        CanonManager *canon;
        AlienManager *aliens;
        BonusManager *bonusManager;
        Timer *timer;
        bool hasWon = false;
        int score = 0;
        int bonusses = 0;
        int shipLife;
        int aliensKilled = 0;
        int bulletsFired = 0;
    };
}

#endif //SPACEINVADERS_LEVELMANAGER_H
