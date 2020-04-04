//
// Created by Gebruiker on 18/03/2020.
//

#ifndef PROJECT_CANON_H
#define PROJECT_CANON_H


#include "../factory/AbstractFactory.h"
#include "../controller/CollisionController.h"
#include "Score.h"

namespace Game {
    class Canon {
    public:
        Canon();

        Canon(AbstractFactory *abstractFactory, PlayerShip *playerShip);

        Bullet *createBullet(std::string imgPath, int shipX, int shipY);

        void runCannon();

        void fireCannon(Bullet *b);

        void loadCannon();

        bool checkCollision(int xPos, int yPos);

    private:
        AbstractFactory *abstractFactory;
        std::string imgPath = "../assets/bullet.png";
        PlayerShip *playerShip;
        Bullet *bullets[200];
        int canonLength = 100;
        Bullet *currentBullet;
        bool shoot = false;
        CollisionController *collisionController = new CollisionController();
        Score* score;
    };
}

#endif //PROJECT_CANON_H
