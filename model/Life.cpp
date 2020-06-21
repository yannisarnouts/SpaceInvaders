//
// Created by Gebruiker on 6/04/2020.
//

#include "Life.h"

Game::Life::Life() {}

int Game::Life::getLife() const {
    return life;
}

void Game::Life::setLife(int life) {
    Life::life = life;
}

Game::Life::~Life() {

}

Game::Life::Life(int xCoord, int yCoord, int width, int height) : Entity(xCoord, yCoord, width, height) {}
