//
// Created by Gebruiker on 18/03/2020.
//

#include "Canon.h"
#include "../controller/KeyHandler.h"

Game::Canon::Canon() {}

Game::Canon::Canon(AbstractFactory *abstractFactory, PlayerShip *playerShip) {
    this->currentBullet = abstractFactory->createBullet("", 0, 0);
    this->abstractFactory = abstractFactory;
    this->playerShip = playerShip;
    this->loadCannon();
}

Game::Bullet* Game::Canon::createBullet(std::string imgPath, int shipX, int shipY) {
    Bullet *bullet = abstractFactory->createBullet(imgPath, shipX, shipY);
    return bullet;
}

void Game::Canon::runCannon() {
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

void Game::Canon::fireCannon(Bullet *b) {
    this->currentBullet = b;
    if (b->getYCoord() <= 5) {
        shoot = false;
    }
    b->Visualize();
}

void Game::Canon::loadCannon() {
    for (int i = 0; i < 100; ++i) {
        bullets[i] = createBullet(this->imgPath, this->playerShip->getXCoord(), this->playerShip->getYCoord());
    }
}

bool Game::Canon::checkCollision(int xPos, int yPos) {
    if (collisionController->bulletObject(currentBullet, xPos, yPos)) {
        shoot = false;
        this->currentBullet->setYCoord(0);
        return true;
    } else {
        return false;
    }
}

