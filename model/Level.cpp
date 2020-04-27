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
