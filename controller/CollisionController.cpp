//
// Created by Gebruiker on 30/03/2020.
//

#include <iostream>
#include "CollisionController.h"

Game::CollisionController::CollisionController() {}

AlienType Game::CollisionController::bulletPlayerShip(Bullet *bullet, Alien *alien) {
    if ((bullet->getXCoord() >= (alien->getXCoord() - alien->getWidth()) && bullet->getXCoord() <= (alien->getXCoord() + alien->getWidth())) &&
            (bullet->getYCoord() >= alien->getYCoord() - alien->getHeight() && bullet->getYCoord() <= alien->getYCoord() + alien->getHeight())) {
        return alien->getAlienType();
    } else {
        return AlienType(1000);
    }
    //    return (bullet->getYCoord() >= yPos - 50 && bullet->getYCoord() <= yPos + 50) &&
//           (bullet->getXCoord() >= xPos - 50 && bullet->getXCoord() <= xPos + 75);
}

bool Game::CollisionController::bulletAlien(Game::AlienBullet *bullet, int xPos, int yPos) {
    if (((bullet->getYCoord() >= yPos-bullet->getWidth()/2) && (bullet->getYCoord() <= yPos + bullet->getWidth()/2)) && (bullet->getXCoord() >= xPos - 50 && bullet->getXCoord() <= xPos + 75)) {
        return true;
    } else {
        return false;
    }
}

bool Game::CollisionController::bonusPlayerShip(Game::Bonus *bonus, PlayerShip *playerShip) {
    if (((bonus->getYCoord() >= playerShip->getYCoord()-50) && (bonus->getYCoord() <= playerShip->getYCoord() + 50)) && (bonus->getXCoord() >= playerShip->getXCoord() - 50 && bonus->getXCoord() <= playerShip->getXCoord() + 75)) {
        return true;
    } else {
        return false;
    }
}
