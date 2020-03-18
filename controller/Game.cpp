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
#include "../model/Canon.h"

Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Run() {
    A->init(1280, 950);
    Background *bg = A->createBackground(bgPath);
    PlayerShip *playerShip = A->createPlayerShip(shipPath);
    Aliens* aliens = new Aliens(this->A);
    Canon* canon = new Canon(this->A);
    while (A->pollEvents()) {
        bg->Visualize();
        playerShip->Visualize();
        aliens->Visualize(100, AlienType::michiel);
        aliens->Visualize(200, AlienType::thomas);
        aliens->Visualize(300, AlienType::ruben);
        aliens->Visualize(400, AlienType::clifford);
        canon->Visualize(playerShip->getXCoord(), playerShip->getYCoord());
        canon->shoot();
        A->render();
    }
    bg->close();
    playerShip->close();
    //alien->close();
    A->close();
}
