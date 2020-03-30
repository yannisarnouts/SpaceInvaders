//
// Created by Gebruiker on 12/03/2020.
//

#include <iostream>
#include "Alien.h"

Alien::Alien() {}

Alien::Alien(int width, int height, AlienType alienType, int xPos, int yPos) {
    this->alienWidth = width / 15;
    this->alienHeight = height / 20;
    this->yCoord = yPos;
    this->xCoord = xPos;
    this->alienType = alienType;
}

int Alien::getAlienWidth() const {
    return alienWidth;
}

int Alien::getAlienHeight() const {
    return alienHeight;
}

int Alien::getXCoord() const {
    return xCoord;
}

int Alien::getYCoord() const {
    return yCoord;
}

void Alien::setYCoord(int yCoord) {
    Alien::yCoord = yCoord;
}

void Alien::moveLeft() {
    this->goDown = false;
    if (this->turnLeft) {
        this->xCoord -= 2;
    }
    if (this->getXCoord() <= 0 - this->alienWidth) {
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

void Alien::setXCoord(int xCoord) {
    Alien::xCoord = xCoord;
}
