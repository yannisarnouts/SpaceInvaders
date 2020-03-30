//
// Created by Gebruiker on 3/03/2020.
//

#include <iostream>
#include "PlayerShip.h"
PlayerShip::PlayerShip() {

}

void PlayerShip::moveShip() {}

PlayerShip::PlayerShip(int xCoord, int yCoord, int width, int height) : Entity(xCoord, yCoord, width, height) {
}