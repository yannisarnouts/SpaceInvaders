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

bool Game::CollisionController::bulletAlien(Game::AlienBullet *bullet, int xPos, int yPos) {
    if (((bullet->getYCoord() >= yPos-bullet->getWidth()/2) && (bullet->getYCoord() <= yPos + bullet->getWidth()/2)) && (bullet->getXCoord() >= xPos - bullet->getHeight()/2 && bullet->getXCoord() <= xPos + bullet->getHeight()/2)) {
        return true;
    } else {
        return false;
    }
}
