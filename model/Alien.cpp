//
// Created by Gebruiker on 12/03/2020.
//

#include <iostream>
#include "Alien.h"

Alien::Alien() {}


Alien::Alien(int xCoord, int yCoord, int width, int height, AlienType alienType) : Entity(xCoord, yCoord, width,
                                                                                          height),
                                                                                   alienType(alienType) {
    this->alienType = alienType;
}

void Alien::moveLeft() {
    this->goDown = false;
    if (this->turnLeft) {
        this->setXCoord(getXCoord() - 2);
    }
    if (this->getXCoord() <= 0 - this->getWidth()) {
        this->turnLeft = false;
        this->goDown = true;
    }
}

bool Alien::isGoDown() const {
    return goDown;
}

void Alien::setGoDown(bool goDown) {
    Alien::goDown = goDown;
}

bool Alien::isTurnLeft() const {
    return turnLeft;
}

void Alien::setTurnLeft(bool turnLeft) {
    Alien::turnLeft = turnLeft;
}
