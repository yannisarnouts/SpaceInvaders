//
// Created by Gebruiker on 4/04/2020.
//

#include "AlienBullet.h"

Game::AlienBullet::AlienBullet() {}

Game::AlienBullet::AlienBullet(int xCoord, int yCoord, int width, int height) : Entity(xCoord, yCoord, width, height) {}

void Game::AlienBullet::shootBullet() {
    setYCoord(getYCoord() + 5);
}
