//
// Created by Gebruiker on 3/03/2020.
//
#include <iostream>
#include "Game.h"
#include "../model/Aliens.h"

Game::Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Game::Run() {
    A->init();
    Background *bg = A->createBackground(bgPath);
    PlayerShip *playerShip = A->createPlayerShip(shipPath);
    Canon* canon = new Canon(this->A, playerShip);
    Aliens* aliens = new Aliens(this->A, canon);
    while (A->pollEvents()) {
        bg->Visualize();
        playerShip->Visualize();
        aliens->Visualize(AlienType::michiel);
        aliens->Visualize(AlienType::thomas);
        aliens->Visualize(AlienType::ruben);
        aliens->Visualize(AlienType::clifford);
        canon->runCannon();
        A->render();
    }
    bg->close();
    playerShip->close();
    //alien->close();
    A->close();
}
