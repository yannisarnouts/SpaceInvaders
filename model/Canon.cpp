//
// Created by Gebruiker on 18/03/2020.
//

#include <iostream>
#include "Canon.h"
#include "../controller/KeyHandler.h"

Canon::Canon(AbstractFactory *abstractFactory) {
    this->abstractFactory = abstractFactory;
    this->createBullet("../assets/spaceship.png");
}

void Canon::createBullet(std::string imgPath) {
    Bullet *bullet = abstractFactory->createBullet(imgPath, this->shipX, this->shipY);
    this->bullet = bullet;
}

void Canon::Visualize(int shipX, int shipY) {
    this->bullet->Visualize(shipX, shipY);
}

void Canon::shoot() {
    KeyHandler keyHandler;
    if (keyHandler.directions() == KeyP::UP) {
        std::cout << "shoot";
        this->bullet->Visualize(shipX, shipY - 5);
    }
}
