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
#include "../model/Aliens.h"

Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Run() {
    A->init(640, 480);
    Background *bg = A->createBackground(bgPath);
    PlayerShip *playerShip = A->createPlayerShip(shipPath);
    Aliens* aliens = new Aliens(this->A);
    Bullet *bullet = A->createBullet(bulletPath, playerShip->getXCoord(), playerShip->getYCoord());
    int bulletY = playerShip->getYCoord();
    while (A->pollEvents()) {
        bg->Visualize();
        playerShip->Visualize();
        aliens->Visualize(50);
        aliens->Visualize2(100);
        aliens->Visualize3(150);
        aliens->Visualize4(200);
        bullet->Visualize(playerShip->getXCoord(), bulletY);
        A->render();
    }
    bg->close();
    playerShip->close();
    //alien->close();
    A->close();
}
