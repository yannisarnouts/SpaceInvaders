//
// Created by Gebruiker on 3/03/2020.
//
#include <iostream>
#include "Game.h"
#include "../controller/AlienManager.h"
#include "PlayerManager.h"
#include "BonusManager.h"

Game::Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Game::Run() {
    A->init();
    Background *bg = A->createBackground(bgPath);
    PlayerManager *playerManager = new PlayerManager(this->A);
    PlayerShip *playerShip = playerManager->getPlayerShip();
    CanonManager *canon = new CanonManager(this->A, playerShip);
    AlienManager *aliens = new AlienManager(this->A, canon);
    BonusManager *bonusManager = new BonusManager(this->A);
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
        bonusManager->runBonusses();
        canon->runCannon();
        A->render();
    }
    bg->close();
    playerManager->getPlayerShip()->close();
    //alien->close();
    A->close();
}
