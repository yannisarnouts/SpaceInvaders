//
// Created by Gebruiker on 27/04/2020.
//

#include "Level.h"

Game::Level::Level() {}

Game::Level::~Level() {

}

int Game::Level::getLevel() const {
    return level;
}

void Game::Level::setLevel(int level) {
    Level::level = level;
}

Game::Level::Level(int xCoord, int yCoord, int width, int height) : Entity(xCoord, yCoord, width, height) {}
