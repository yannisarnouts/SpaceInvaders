//
// Created by Gebruiker on 3/03/2020.
//
#include <iostream>
#include "Game.h"
#include "PlayerManager.h"
#include "BonusManager.h"
#include "ConfigReader.h"
#include "FileWriter.h"

Game::Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Game::Run() {
    configReader = new ConfigReader();
    bg = A->createBackground(bgPath);;
    playerManager = new PlayerManager(this->A, configReader);
    playerShip = playerManager->getPlayerShip();
    canon = new CanonManager(this->A, playerShip, configReader);
    aliens = new AlienManager(this->A, canon, configReader);
    bonusManager = new BonusManager(this->A, playerManager, canon, configReader);
    while (A->pollEvents() && playerShip->getLife() > 0 && aliens->getAlienLength() > 0) {
        bg->Visualize();
        playerManager->runPlayer();
        aliens->Visualize(AlienType::michiel);
        aliens->Visualize(AlienType::thomas);
        aliens->Visualize(AlienType::boss);
        aliens->Visualize(AlienType::clifford);
        if(aliens->checkCollision(playerShip->getXCoord(), playerShip->getYCoord())) {
            playerManager->setLife();
        };
        bonusManager->runBonusses();
        canon->runCannon();
        A->render();
    }
//    updateStatistics(canon);
    bg->close();
    playerManager->getPlayerShip()->close();
    //alien->close();
    A->close();
}

void Game::Game::updateStatistics() {
    FileWriter *fileWriter = new FileWriter();
    fileWriter->writeFile("HIGH_SCORE=");
}
