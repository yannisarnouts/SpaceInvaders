//
// Created by Gebruiker on 3/04/2020.
//

#include "Score.h"

Game::Score::Score() {}

int Game::Score::getPoints() const {
    return points;
}

void Game::Score::setPoints(int points) {
    Score::points = points;
}
