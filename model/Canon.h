//
// Created by Gebruiker on 18/03/2020.
//

#ifndef PROJECT_CANON_H
#define PROJECT_CANON_H


#include "../factory/AbstractFactory.h"

class Canon {
public:
    Canon(AbstractFactory *abstractFactory, PlayerShip *playerShip);
    Bullet* createBullet(std::string imgPath, int shipX, int shipY);
    void runCannon();
    void fireCannon(Bullet* b);
    void loadCannon();
private:
    AbstractFactory* abstractFactory;
    std::string imgPath = "../assets/bullet.png";
    PlayerShip* playerShip;
    int shipX; int shipY;
    Bullet* bullets[100]; Bullet* firingBullets[100];
    int canonLength = 100, nFiring = 0;
    bool shoot = false;
};


#endif //PROJECT_CANON_H
