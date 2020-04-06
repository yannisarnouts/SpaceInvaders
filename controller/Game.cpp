//
// Created by Gebruiker on 3/03/2020.
//
#include <iostream>
#include "Game.h"
#include "../controller/AlienManager.h"
#include "PlayerManager.h"

Game::Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Game::Run() {
    A->init();
    Background *bg = A->createBackground(bgPath);
    PlayerManager* playerManager = new PlayerManager(this->A);
    PlayerShip* playerShip = playerManager->getPlayerShip();
    Canon* canon = new Canon(this->A, playerShip);
    AlienManager* aliens = new AlienManager(this->A, canon);
    while (A->pollEvents() && playerShip->getLife() > 0) {
        bg->Visualize();
        playerManager->runPlayer();
        aliens->Visualize(AlienType::michiel);
        aliens->Visualize(AlienType::thomas);
        aliens->Visualize(AlienType::ruben);
        aliens->Visualize(AlienType::clifford);
        if(aliens->checkCollision(playerShip->getXCoord(), playerShip->getYCoord())) {
            playerManager->setLife();
        };
        canon->runCannon();
        A->render();
    }
    bg->close();
    playerManager->getPlayerShip()->close();
    //alien->close();
    A->close();
}
