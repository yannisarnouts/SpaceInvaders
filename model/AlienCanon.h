//
// Created by Gebruiker on 1/04/2020.
//

#ifndef PROJECT_ALIENCANON_H
#define PROJECT_ALIENCANON_H


#include "../controller/CollisionController.h"
namespace Game {
    class AlienCanon {
    public:
        AlienCanon();

        Bullet *createBullet(std::string imgPath, int shipX, int shipY);

        void runCannon();

        void fireCannon(Bullet *b);

        void loadCannon();

    private:
        std::string imgPath = "../assets/bullet.png";
        Bullet *bullets[100];
        int canonLength = 100;
        Bullet *currentBullet;
        bool shoot = false;
        CollisionController *collisionController = new CollisionController();
    };
}

#endif //PROJECT_ALIENCANON_H
