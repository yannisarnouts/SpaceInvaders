//
// Created by Gebruiker on 3/03/2020.
//

#include <zconf.h>
#include <iostream>
#include "Game.h"
#include "../SDLClasses/SDLPlayerShip.h"
#include "../model/Background.h"
#include "../model/Alien.h"
#include "../model/Bullet.h"

Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Run() {
    A->init(640, 480);
    Background *bg = A->createBackground(bgPath);
    PlayerShip *playerShip = A->createPlayerShip(shipPath);
    Alien *alien = A->createAlien(AlienType::michiel, michielAlien);
    Bullet *bullet = A->createBullet(bulletPath, playerShip->getXCoord(), playerShip->getYCoord());
    while (A->pollEvents()) {
        bg->Visualize();
        playerShip->Visualize();
        alien->Visualize();
        bullet->Visualize(playerShip->getXCoord(), playerShip->getYCoord());
        A->render();
    }
    bg->close();
    playerShip->close();
    alien->close();
    bullet->close();
    A->close();
}
