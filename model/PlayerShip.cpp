//
// Created by Gebruiker on 3/03/2020.
//

#include <iostream>
#include "PlayerShip.h"
Game::PlayerShip::PlayerShip() {

}
Game::PlayerShip::PlayerShip(int xCoord, int yCoord, int width, int height) : Entity(xCoord, yCoord, width, height) {
}

int Game::PlayerShip::getLife() const {
    return life;
}

void Game::PlayerShip::setLife(int life) {
    PlayerShip::life = life;
}
