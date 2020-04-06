//
// Created by Gebruiker on 6/04/2020.
//

#include "PlayerManager.h"

Game::PlayerManager::PlayerManager() {}

Game::PlayerManager::PlayerManager(Game::AbstractFactory *abstractFactory) : abstractFactory(abstractFactory) {
    this->abstractFactory = abstractFactory;
    this->playerShip = abstractFactory->createPlayerShip(shipPath);
    this->life = abstractFactory->createLife();
}

Game::PlayerShip *Game::PlayerManager::getPlayerShip() const {
    return playerShip;
}

void Game::PlayerManager::runPlayer() {
    playerShip->Visualize();
    life->Visualize();
}

void Game::PlayerManager::setLife() {
    getPlayerShip()->setLife(getPlayerShip()->getLife()-1);
    life->setLife(getPlayerShip()->getLife());
}
