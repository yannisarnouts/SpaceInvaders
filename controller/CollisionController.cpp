//
// Created by Gebruiker on 30/03/2020.
//

#include <iostream>
#include "CollisionController.h"

Game::CollisionController::CollisionController() {}

AlienType Game::CollisionController::bulletPlayerShip(Bullet *bullet, Alien *alien) {
    if ((bullet->getXCoord() >= (alien->getXCoord()) && bullet->getXCoord() <= (alien->getXCoord() + alien->getWidth())) &&
        (bullet->getYCoord() >= alien->getYCoord() - alien->getHeight() && bullet->getYCoord() <= alien->getYCoord() + alien->getHeight())) {
        return alien->getAlienType();
    } else {
        return AlienType(1000);
    }
}

bool Game::CollisionController::bulletAlien(Game::AlienBullet *bullet, PlayerShip *playerShip) {
    if (((bullet->getYCoord() >= playerShip->getYCoord()-bullet->getHeight()/2) && (bullet->getYCoord() <= playerShip->getYCoord() + bullet->getHeight()/2)) && (bullet->getXCoord() >= playerShip->getXCoord() - playerShip->getWidth()/2 && bullet->getXCoord() <= playerShip->getXCoord() + playerShip->getWidth()/2)) {
        return true;
    } else {
        return false;
    }
}

bool Game::CollisionController::bonusPlayerShip(Game::Bonus *bonus, PlayerShip *playerShip) {
    if (((bonus->getYCoord() >= playerShip->getYCoord()-bonus->getHeight()/2) && (bonus->getYCoord() <= playerShip->getYCoord() + bonus->getHeight()/2)) && (bonus->getXCoord() >= playerShip->getXCoord() - playerShip->getWidth() && bonus->getXCoord() <= playerShip->getXCoord() + playerShip->getWidth())) {
        return true;
    } else {
        return false;
    }
}
