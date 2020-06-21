//
// Created by Gebruiker on 3/03/2020.
//
#include "Game.h"
#include "ConfigReader.h"

Game::Game::Game(AbstractFactory *_A) {
    A = _A;
    this->timer = A->createTimer();
    bg = A->createBackground();
    configReader = new ConfigReader();
    levelManager = new LevelManager(configReader, this->A, timer);
}

void Game::Game::Run() {
    for (int i = 1; i <= 3; i++) {
        if (levelManager->isHasWon() || i == 1) {
            levelManager->getLevel()->setLevel(i);
            levelManager->createLevel();
        } else {
            break;
        }
        while (A->pollEvents() && levelManager->getPlayerShip()->getLife() > 0 &&
               levelManager->getAliens()->getAlienLength() > 0) {
            bg->Visualize();
            levelManager->runLevel();
            A->render();
            timer->update();
        }
        won = levelManager->getAliens()->getAlienLength() == 0;
        levelManager->setScore(levelManager->getCanon()->getScore()->getPoints());
        levelManager->setBonusses(levelManager->getBonusses() + levelManager->getBonusManager()->getBonussesCaught());
        levelManager->setShipLife(levelManager->getPlayerShip()->getLife());
        levelManager->setAliensKilled(levelManager->getAliens()->getAliensKilled());
        levelManager->setBulletsFired(levelManager->getCanon()->getBulletsFired());
        levelManager->cleanLevel();
    }
    updateStatistics();
}

void Game::Game::updateStatistics() {
    fileWriter = new FileWriter();
    fileWriter->setLevel(levelManager->getLevel()->getLevel());
    fileWriter->setPoints(levelManager->getCanon()->getScore()->getPoints());
    fileWriter->setLifesLeft(levelManager->getPlayerShip()->getLife());
    fileWriter->setBulletsFired(levelManager->getBulletsFired());
    fileWriter->setBonussesCaught(levelManager->getBonusses());
    fileWriter->setAliensKilled(levelManager->getAliensKilled());
    fileWriter->setWon(won);
    fileWriter->writeStats();
}

Game::Game::~Game() {
    delete levelManager;
    delete configReader;
    delete fileWriter;
    delete timer;
}