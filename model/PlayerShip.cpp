//
// Created by Gebruiker on 3/03/2020.
//

#include <iostream>
#include "PlayerShip.h"
PlayerShip::PlayerShip() {

}

void PlayerShip::moveShip() {}

PlayerShip::PlayerShip(int width, int height){
    this->shipWidth = width / 7;
    this->shipHeight = height / 7;
    this->xCoord = width / 2 - 50;
    this->yCoord = height - (this->shipHeight + 350);
    std::cout << yCoord;
}

int PlayerShip::getXCoord() const {
    return xCoord;
}

int PlayerShip::getYCoord() const {
    return yCoord;
}

int PlayerShip::getShipWidth() const {
    return shipWidth;
}

int PlayerShip::getShipHeight() const {
    return shipHeight;
}

void PlayerShip::setXCoord(int xCoord) {
    PlayerShip::xCoord = xCoord;
}
