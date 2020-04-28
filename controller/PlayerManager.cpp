//
// Created by Gebruiker on 6/04/2020.
//

#include "PlayerManager.h"

Game::PlayerManager::PlayerManager() {}

Game::PlayerManager::PlayerManager(Game::AbstractFactory *abstractFactory, ConfigReader *configReader, int initLife) : abstractFactory(abstractFactory) {
    this->abstractFactory = abstractFactory;
    this->configReader = configReader;
    this->playerShip = abstractFactory->createPlayerShip();
    this->life = abstractFactory->createLife();
    this->timer = abstractFactory->createTimer();
    life->setLife(initLife);
    playerShip->setLife(initLife);
    this->playerShip->setSpeed(configReader->getShipSpeed());
}

Game::PlayerShip *Game::PlayerManager::getPlayerShip() const {
    return playerShip;
}

/*
 * Method to run the player
 * Update timer
 * Visualize and move ship
 * Visualize life
 */
void Game::PlayerManager::runPlayer() {
    timer->update();
    moveShip();
    playerShip->Visualize();
    life->Visualize();
}

void Game::PlayerManager::setLife() {
    getPlayerShip()->setLife(getPlayerShip()->getLife()-1);
    life->setLife(getPlayerShip()->getLife());
}

/*
 * moveShip checks whether the ship is still between the boundaries and moves the player
 */
void Game::PlayerManager::moveShip() {
    int direction = keyHandler->directions();
    if (playerShip->getXCoord() >= (this->configReader->getScreenWidth() - playerShip->getWidth())) {
        if (direction == KeyP::LEFT) {
            playerShip->setXCoord(playerShip->getXCoord()- timer->getDeltaTime() * playerShip->getSpeed());
        }
    } else if (playerShip->getXCoord() <= 0) {
        if (direction == KeyP::RIGHT) {
            playerShip->setXCoord(playerShip->getXCoord() + timer->getDeltaTime() * playerShip->getSpeed());
        }
    } else {
        if (direction == KeyP::LEFT) {
            playerShip->setXCoord(playerShip->getXCoord()- timer->getDeltaTime() * playerShip->getSpeed());
        } else if (direction == KeyP::RIGHT) {
            playerShip->setXCoord(playerShip->getXCoord() + timer->getDeltaTime() * playerShip->getSpeed());
        }
    }
}

Game::PlayerManager::~PlayerManager() {
    delete life;
    delete playerShip;
}
