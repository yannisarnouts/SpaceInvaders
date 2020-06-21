//
// Created by Gebruiker on 3/04/2020.
//

#include "Score.h"

int Game::Score::getPoints() const {
    return points;
}

void Game::Score::setPoints(int points) {
    Score::points = points;
}

Game::Score::~Score() {

}

Game::Score::Score(int xCoord, int yCoord, int width, int height) : Entity(xCoord, yCoord, width, height) {}
