//
// Created by Gebruiker on 30/03/2020.
//

#include <iostream>
#include "CollisionController.h"

Game::CollisionController::CollisionController() {}

bool Game::CollisionController::bulletObject(Bullet *bullet, int xPos, int yPos) {
    return (bullet->getYCoord() >= yPos - bullet->getHeight()/2 && bullet->getYCoord() <= yPos + bullet->getHeight()/2) &&
           (bullet->getXCoord() >= xPos - bullet->getHeight()/2 && bullet->getXCoord() <= xPos + bullet->getHeight()/2);
}