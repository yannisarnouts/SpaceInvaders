//
// Created by Gebruiker on 18/03/2020.
//

#include <iostream>
#include <zconf.h>
#include "Canon.h"
#include "../controller/KeyHandler.h"
#include "../controller/CollisionController.h"

Canon::Canon() {}

Canon::Canon(AbstractFactory *abstractFactory, PlayerShip *playerShip) {
    this->currentBullet = abstractFactory->createBullet("", 0, 0);
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
    this->currentBullet = b;
    if (b->getYCoord() <= 5) {
        shoot = false;
    }
    b->Visualize();
    checkCollision(100, 100);
}

void Canon::loadCannon() {
    for (int i = 0; i < 100; ++i) {
        bullets[i] = createBullet(this->imgPath, this->playerShip->getXCoord(), this->playerShip->getYCoord());
    }
}

bool Canon::checkCollision(int xPos, int yPos) {
    if (collisionController->bulletObject(currentBullet, xPos, yPos)) {
        shoot = false;
        this->currentBullet->setYCoord(0);
        return true;
    } else {
        return false;
    }
}

