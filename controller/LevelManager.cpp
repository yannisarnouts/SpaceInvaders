//
// Created by Gebruiker on 22/04/2020.
//

#include "LevelManager.h"

Game::LevelManager::LevelManager() {}

Game::LevelManager::LevelManager(ConfigReader *configReader, AbstractFactory *abstractFactory) : configReader(configReader) {
    this->A = abstractFactory;
    this->configReader = new ConfigReader();
    this->setShipLife(configReader->getShipLife());
    this->level = abstractFactory->createLevel();
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
    delete level;
    delete bonusManager;
    delete aliens;
    delete bonusManager;
    delete canon;
}

void Game::LevelManager::createLevel() {
    playerManager = new PlayerManager(this->A, configReader, shipLife);
    playerShip = playerManager->getPlayerShip();
    canon = new CanonManager(this->A, playerShip, configReader, level->getLevel(), score, bulletsFired);
    aliens = new AlienManager(this->A, canon, configReader, level->getLevel(), aliensKilled);
    bonusManager = new BonusManager(this->A, playerManager, canon, configReader);
}

bool Game::LevelManager::isHasWon() const {
    return hasWon;
}

void Game::LevelManager::setHasWon(bool hasWon) {
    LevelManager::hasWon = hasWon;
}

int Game::LevelManager::getScore() const {
    return score;
}

void Game::LevelManager::setScore(int score) {
    LevelManager::score = score;
}

int Game::LevelManager::getBonusses() const {
    return bonusses;
}

void Game::LevelManager::setBonusses(int bonusses) {
    LevelManager::bonusses = bonusses;
}

int Game::LevelManager::getShipLife() const {
    return shipLife;
}

void Game::LevelManager::setShipLife(int shipLife) {
    LevelManager::shipLife = shipLife;
}

int Game::LevelManager::getAliensKilled() const {
    return aliensKilled;
}

void Game::LevelManager::setAliensKilled(int aliensKilled) {
    LevelManager::aliensKilled = aliensKilled;
}

int Game::LevelManager::getBulletsFired() const {
    return bulletsFired;
}

void Game::LevelManager::setBulletsFired(int bulletsFired) {
    LevelManager::bulletsFired = bulletsFired;
}

Game::Level *Game::LevelManager::getLevel() const {
    return level;
}

void Game::LevelManager::setLevel(Game::Level *level) {
    LevelManager::level = level;
}

void Game::LevelManager::runLevel() {
    getPlayerManager()->runPlayer();
    getAliens()->Visualize();
    if (getAliens()->checkCollision(getPlayerShip())) {
        getPlayerManager()->setLife();
    }
    getBonusManager()->runBonusses();
    getCanon()->runCannon();
    getLevel()->Visualize();
    if (getAliens()->getAlienLength() == 0) {
        setHasWon(true);
    } else if (getPlayerShip()->getLife() > 0 || !(A->pollEvents())) {
        setHasWon(false);
    }
}

void Game::LevelManager::cleanLevel() {
    delete bonusManager;
    delete aliens;
    delete bonusManager;
    delete canon;
}
