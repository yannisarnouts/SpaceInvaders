//
// Created by Gebruiker on 12/03/2020.
//

#include "Alien.h"

Game::Alien::Alien() {}


Game::Alien::Alien(int xCoord, int yCoord, int width, int height, AlienType alienType) : Entity(xCoord, yCoord, width,
                                                                                          height),
                                                                                   alienType(alienType) {
}

void Game::Alien::move(double timer) {
    setXCoord(getXCoord() + (timer * 2 * getMoveAlien()));
}

void Game::Alien::setMoveDirection(int moveAlien) {
    Alien::moveAlien = moveAlien;
}

int Game::Alien::getMoveAlien() const {
    return moveAlien;
}

bool Game::Alien::isAlive() const {
    return alive;
}

void Game::Alien::setAlive(bool alive) {
    Alien::alive = alive;
}

bool Game::Alien::hitBoundary(int field_width) {
    if (getXCoord() <= 0 - getWidth()) {
        return true;
    } else if (getXCoord() >= field_width - (getWidth() * 2) - 50) {
        return true;
    }
    return false;
}

AlienType Game::Alien::getAlienType() const {
    return alienType;
}

Game::Alien::~Alien() {

}
