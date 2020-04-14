//
// Created by Gebruiker on 18/03/2020.
//

#ifndef PROJECT_CANONMANAGER_H
#define PROJECT_CANONMANAGER_H


#include "../factory/AbstractFactory.h"
#include "CollisionController.h"
#include "../model/Score.h"
#include "ConfigReader.h"

namespace Game {
    class CanonManager {
    public:
        CanonManager();
        CanonManager(AbstractFactory *abstractFactory, PlayerShip *playerShip, ConfigReader *configReader);
        Bullet *createBullet(int shipX, int shipY);
        void runCannon();
        void fireCannon(Bullet *b);
        void loadCannon();
        bool checkCollision(Alien *alien);

        Score *getScore() const;

    private:
        AbstractFactory *abstractFactory;
        PlayerShip *playerShip;
        Bullet *bullets[200];
        int canonLength;
        Bullet *currentBullet;
        Timer *timer;
        bool shoot = false;
        CollisionController *collisionController;
        ConfigReader *configReader;
        Score* score;
    };
}

#endif //PROJECT_CANONMANAGER_H
