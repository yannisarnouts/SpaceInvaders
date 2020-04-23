//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_ALIENS_H
#define PROJECT_ALIENMANAGER_H


#include <vector>
#include "../factory/AbstractFactory.h"
#include "CollisionController.h"
#include "../model/Timer.h"
#include "CanonManager.h"
#include "ConfigReader.h"

namespace Game {
    class AlienManager {
    public:
        AlienManager(AbstractFactory *abstractFactory, CanonManager *canon, ConfigReader *configReader, int level);
        void Visualize();
        void createAliens();
        void moveAndCheck(int length);
        void handleCollision(int i, int length);
        bool checkCollision(PlayerShip *playerShip);
        void alienShoot(int a);
        int getAlienLength() const;
        int getAliensKilled() const;
        void initLevel();

    private:
        AbstractFactory *abstractFactory;
        std::vector<Alien * > aliens;
        std::vector<AlienBullet*> bullets;
        int bulletLength = 500;
        CanonManager *canon; AlienBullet *currentBullet;
        CollisionController *collisionController;
        ConfigReader *configReader;
        int alienLength; int aliensKilled; int alienTypes;
        int level;
    };
}

#endif //PROJECT_ALIENS_H
