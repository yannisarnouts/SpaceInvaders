//
// Created by Gebruiker on 3/03/2020.
//
#include <ctime>
#include "Game.h"
#include "ConfigReader.h"
#include "FileWriter.h"

Game::Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Game::Run() {
    start = time(0);
    configReader = new ConfigReader();
    bg = A->createBackground(bgPath);
    levelManager = new LevelManager(configReader, this->A);
    while (A->pollEvents() && levelManager->getPlayerShip()->getLife() > 0 && levelManager->getAliens()->getAlienLength() > 0) {
        bg->Visualize();
        levelManager->getPlayerManager()->runPlayer();
        levelManager->getAliens()->Visualize();
        if(levelManager->getAliens()->checkCollision(levelManager->getPlayerShip())) {
            levelManager->getPlayerManager()->setLife();
        };
        levelManager->getBonusManager()->runBonusses();
        levelManager->getCanon()->runCannon();
        A->render();
    }
    updateStatistics();
    bg->close();
//    playerManager->getPlayerShip()->close();
//    alien->close();
    A->close();
}

void Game::Game::updateStatistics() {
    FileWriter *fileWriter = new FileWriter();
    fileWriter->setPoints(levelManager->getCanon()->getScore()->getPoints());
    fileWriter->setLifesLeft(levelManager->getPlayerShip()->getLife());
    fileWriter->setTimePlayed(difftime(time(0), start));
    fileWriter->setBulletsFired(levelManager->getCanon()->getBulletsFired());
    fileWriter->setBonussesCaught(levelManager->getBonusManager()->getBonussesCaught());
    fileWriter->setAliensKilled(levelManager->getAliens()->getAliensKilled());
    fileWriter->writeStats();
}
