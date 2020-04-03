//
// Created by Gebruiker on 1/04/2020.
//

#ifndef PROJECT_ALIENCANON_H
#define PROJECT_ALIENCANON_H


#include "../factory/AbstractFactory.h"
#include "../controller/CollisionController.h"
namespace Game {
    class AlienCanon {
    public:
        AlienCanon();

        AlienCanon(AbstractFactory *abstractFactory, Alien *alien);

        Bullet *createBullet(std::string imgPath, int shipX, int shipY);

        void runCannon();

        void fireCannon(Bullet *b);

        void loadCannon();

    private:
        AbstractFactory *abstractFactory;
        std::string imgPath = "../assets/bullet.png";
        Alien *alien;
        Bullet *bullets[100];
        int canonLength = 100;
        Bullet *currentBullet;
        bool shoot = false;
        CollisionController *collisionController = new CollisionController();
    };
}

#endif //PROJECT_ALIENCANON_H
