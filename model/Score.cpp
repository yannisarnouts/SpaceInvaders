//
// Created by Gebruiker on 3/04/2020.
//

#include "Score.h"

Score::Score() {}

int Score::getPoints() const {
    return points;
}

void Score::setPoints(int points) {
    Score::points = points;
}
