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

void Alien::move() {
    setXCoord(getXCoord() + (2 * getMoveAlien()));
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

void Alien::setMoveAlien(int moveAlien) {
    Alien::moveAlien = moveAlien;
}

int Alien::getMoveAlien() const {
    return moveAlien;
}
