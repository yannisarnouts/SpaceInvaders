//
// Created by Gebruiker on 12/03/2020.
//

#include <iostream>
#include "Alien.h"

Game::Alien::Alien() {}


Game::Alien::Alien(int xCoord, int yCoord, int width, int height, AlienType alienType) : Entity(xCoord, yCoord, width,
                                                                                          height),
                                                                                   alienType(alienType) {
}

void Game::Alien::move() {
    setXCoord(getXCoord() + (2 * getMoveAlien()));
}

void Game::Alien::setMoveAlien(int moveAlien) {
    Alien::moveAlien = moveAlien;
}

int Game::Alien::getMoveAlien() const {
    return moveAlien;
}
