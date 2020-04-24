//
// Created by Gebruiker on 22/04/2020.
//

#include "LevelManager.h"

Game::LevelManager::LevelManager() {}

Game::LevelManager::LevelManager(ConfigReader *configReader, AbstractFactory *abstractFactory) : configReader(configReader) {
    this->A = abstractFactory;
    this->configReader = new ConfigReader();
    this->level = configReader->getLevel();
    playerManager = new PlayerManager(this->A, configReader);
    playerShip = playerManager->getPlayerShip();
    canon = new CanonManager(this->A, playerShip, configReader, level);
    aliens = new AlienManager(this->A, canon, configReader, level);
    bonusManager = new BonusManager(this->A, playerManager, canon, configReader);
}

int Game::LevelManager::getLevel() const {
    return level;
}

void Game::LevelManager::setLevel(int level) {
    LevelManager::level = level;
}

Game::PlayerManager *Game::LevelManager::getPlayerManager() const {
    return playerManager;
}

Game::PlayerShip *Game::LevelManager::getPlayerShip() const {
    return playerShip;
}

Game::CanonManager *Game::LevelManager::getCanon() const {
    return canon;
}

Game::AlienManager *Game::LevelManager::getAliens() const {
    return aliens;
}

Game::BonusManager *Game::LevelManager::getBonusManager() const {
    return bonusManager;
}

Game::LevelManager::~LevelManager() {

}

