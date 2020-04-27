//
// Created by Gebruiker on 6/04/2020.
//

#include <iostream>
#include "Bonus.h"

Game::Bonus::Bonus() {}

Game::Bonus::Bonus(int xCoord, int yCoord, int width, int height) : Entity(xCoord, yCoord, width, height) {}

Game::Bonus::Bonus(int xCoord, int yCoord, int width, int height, Game::BonusType bonusType) : Entity(xCoord, yCoord,
                                                                                                      width, height),
                                                                                               bonusType(bonusType) {
}

Game::BonusType Game::Bonus::getBonusType() const {
    return bonusType;
}

void Game::Bonus::setBonusType(Game::BonusType bonusType) {
    Bonus::bonusType = bonusType;
}

Game::Bonus::~Bonus() {}
