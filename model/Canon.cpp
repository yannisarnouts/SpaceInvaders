//
// Created by Gebruiker on 18/03/2020.
//

#include <iostream>
#include <zconf.h>
#include "Canon.h"
#include "../controller/KeyHandler.h"

Canon::Canon(AbstractFactory *abstractFactory, PlayerShip *playerShip) {
    this->abstractFactory = abstractFactory;
    this->playerShip = playerShip;
    this->loadCannon();
}

Bullet *Canon::createBullet(std::string imgPath, int shipX, int shipY) {
    Bullet *bullet = abstractFactory->createBullet(imgPath, shipX, shipY);
    return bullet;
}

void Canon::runCannon() {
    KeyHandler keyHandler;
    int direction = keyHandler.directions();
    if (direction == KeyP::UP && !shoot) {
        canonLength--;
        Bullet* bullet = createBullet(this->imgPath, this->playerShip->getXCoord(), this->playerShip->getYCoord());
        this->bullets[canonLength]->setXCoord(this->playerShip->getXCoord());
        shoot = true;
    }
    if (canonLength == 1) {
        this->loadCannon();
    }
    if (shoot) {
        this->fireCannon(this->bullets[canonLength]);
    }
}

void Canon::fireCannon(Bullet *b) {
    if (b->getYCoord() <= 5) {
        shoot = false;
    }
    b->Visualize();
}

void Canon::loadCannon() {
    for (int i = 0; i < 100; ++i) {
        bullets[i] = createBullet(this->imgPath, this->playerShip->getXCoord(), this->playerShip->getYCoord());
    }
}