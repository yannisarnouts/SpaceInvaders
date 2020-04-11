//
// Created by Gebruiker on 6/04/2020.
//

#include "PlayerManager.h"

Game::PlayerManager::PlayerManager() {}

Game::PlayerManager::PlayerManager(Game::AbstractFactory *abstractFactory, ConfigReader *configReader) : abstractFactory(abstractFactory) {
    this->abstractFactory = abstractFactory;
    this->configReader = configReader;
    this->playerShip = abstractFactory->createPlayerShip();
    this->life = abstractFactory->createLife();
    initShip();
    this->timer = abstractFactory->createTimer();
}

Game::PlayerShip *Game::PlayerManager::getPlayerShip() const {
    return playerShip;
}

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

void Game::PlayerManager::moveShip() {
    int direction = keyHandler->directions();
    if (playerShip->getXCoord() >= (this->configReader->getScreenWidth() + playerShip->getWidth())) {
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

void Game::PlayerManager::initShip() {
    this->playerShip->setSpeed(configReader->getShipSpeed());
    this->playerShip->setLife(configReader->getShipLife());
    this->life->setLife(configReader->getShipLife());
}
