//
// Created by Gebruiker on 30/03/2020.
//

#include <iostream>
#include "CollisionController.h"

Game::CollisionController::CollisionController() {}

/*
 * collision detection on bullet from the playership and an alien
 */
AlienType Game::CollisionController::bulletPlayerShip(Bullet *bullet, Alien *alien) {
    if ((bullet->getXCoord() >= (alien->getXCoord() - alien->getWidth()) && bullet->getXCoord() <= (alien->getXCoord() + 100)) &&
        (bullet->getYCoord() >= alien->getYCoord() && bullet->getYCoord() <= (alien->getYCoord() + alien->getHeight()))) {
        return alien->getAlienType();
    } else {
        return AlienType(1000);
    }
}

/*
 * collision detection on alien bullet and playership
 */
bool Game::CollisionController::bulletAlien(Game::AlienBullet *bullet, PlayerShip *playerShip) {
    return bullet->getXCoord() + bullet->getWidth() >= playerShip->getXCoord() &&
            bullet->getXCoord() <= playerShip->getXCoord() + playerShip->getWidth() &&
            bullet->getYCoord() + bullet->getHeight() >= playerShip->getYCoord() &&
            bullet->getYCoord() <= playerShip->getYCoord() + playerShip->getHeight();
}

/*
 * collsion detection on bonus and playership
 */
bool Game::CollisionController::bonusPlayerShip(Game::Bonus *bonus, PlayerShip *playerShip) {
    return bonus->getXCoord() + bonus->getWidth() >= playerShip->getXCoord() &&
           bonus->getXCoord() <= playerShip->getXCoord() + playerShip->getWidth() &&
           bonus->getYCoord() + bonus->getHeight() >= playerShip->getYCoord() &&
           bonus->getYCoord() <= playerShip->getYCoord() + playerShip->getHeight();
}
