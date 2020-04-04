//
// Created by Gebruiker on 1/04/2020.
//

#include <iostream>
#include "AlienCanon.h"
#include "../controller/KeyHandler.h"

Game::AlienCanon::AlienCanon() {}

//Game::AlienCanon::AlienCanon(Alien *alien) {
//    this->currentBullet = abstractFactory->createBullet(imgPath, 0, 0);
//    this->abstractFactory = abstractFactory;
//    this->alien = alien;
//    this->loadCannon();
//}

Game::Bullet *Game::AlienCanon::createBullet(std::string imgPath, int shipX, int shipY) {
//    Bullet *bullet = abstractFactory->createBullet(imgPath, shipX, shipY);
//    return bullet;
}

void Game::AlienCanon::runCannon() {
    canonLength--;
//    this->bullets[canonLength]->setXCoord(this->alien->getXCoord());
    this->fireCannon(this->bullets[canonLength]);
}

void Game::AlienCanon::fireCannon(Bullet *b) {
    this->currentBullet = b;
    b->Visualize();

}

void Game::AlienCanon::loadCannon() {
//    std::cout << this->alien->getXCoord();
    for (int i = 0; i < 100; ++i) {
//        bullets[i] = createBullet(this->imgPath, this->alien->getXCoord(), this->alien->getYCoord());
    }
}