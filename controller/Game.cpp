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
    for (int i = 1; i <= 3; i++) {
        if (levelManager->isHasWon() || i == 1) {
            levelManager->setLevel(i);
            levelManager->createLevel();
        } else {
            break;
        }
        while (A->pollEvents() && levelManager->getPlayerShip()->getLife() > 0 &&
               levelManager->getAliens()->getAlienLength() > 0) {
            bg->Visualize();
            levelManager->getPlayerManager()->runPlayer();
            levelManager->getAliens()->Visualize();
            if (levelManager->getAliens()->checkCollision(levelManager->getPlayerShip())) {
                levelManager->getPlayerManager()->setLife();
            };
            levelManager->getBonusManager()->runBonusses();
            levelManager->getCanon()->runCannon();
            A->render();
            if (levelManager->getAliens()->getAlienLength() == 0) {
                levelManager->setHasWon(true);
            } else if (levelManager->getPlayerShip()->getLife() > 0 || !(A->pollEvents())) {
                levelManager->setHasWon(false);
            }
        }
        levelManager->setScore(levelManager->getCanon()->getScore()->getPoints());
        levelManager->setBonusses(levelManager->getBonusses() + levelManager->getBonusManager()->getBonussesCaught());
        levelManager->setShipLife(levelManager->getPlayerShip()->getLife());
        levelManager->setAliensKilled(levelManager->getAliensKilled() + levelManager->getAliens()->getAliensKilled());
        levelManager->setBulletsFired(levelManager->getBulletsFired() + levelManager->getCanon()->getBulletsFired());
    }
    updateStatistics();
    A->close();
}

void Game::Game::updateStatistics() {
    FileWriter *fileWriter = new FileWriter();
    fileWriter->setLevel(levelManager->getLevel());
    fileWriter->setPoints(levelManager->getCanon()->getScore()->getPoints());
    fileWriter->setLifesLeft(levelManager->getPlayerShip()->getLife());
    fileWriter->setTimePlayed(difftime(time(0), start));
    fileWriter->setBulletsFired(levelManager->getBulletsFired());
    fileWriter->setBonussesCaught(levelManager->getBonusses());
    fileWriter->setAliensKilled(levelManager->getAliensKilled());
    fileWriter->writeStats();
}

Game::Game::~Game() {

}
