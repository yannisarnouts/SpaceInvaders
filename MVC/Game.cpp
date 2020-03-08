//
// Created by Gebruiker on 3/03/2020.
//

#include <iostream>
#include "Game.h"
#include "../model/AbstractPlayerShip.h"

Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Run() {
    AbstractPlayerShip *playerShip = A->createPlayerShip();
    playerShip->Visualize(*playerShip);
    AbstractAlien *alien = A->createAlien();
    alien->Visualize(*alien);
    AbstractBullet *abstractBullet = A->createBullet();
    abstractBullet->Visualize(*abstractBullet);
}
