//
// Created by Gebruiker on 17/03/2020.
//

#include "Bullet.h"

Game::Bullet::Bullet() {}

Game::Bullet::Bullet(int xCoord, int yCoord, int width, int height) : Entity(xCoord, yCoord, width, height) {
}

void Game::Bullet::shootBullet() {
    setYCoord(getYCoord() - 15);
}
