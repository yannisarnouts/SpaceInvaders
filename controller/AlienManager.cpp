//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "AlienManager.h"

Game::AlienManager::AlienManager(AbstractFactory *abstractFactory, CanonManager *canon, ConfigReader *configReader, int level) {
    this->abstractFactory = abstractFactory;
    this->canon = canon;
    this->configReader = configReader;
    this->collisionController = new CollisionController();
    this->currentBullet = abstractFactory->createAlienBullet(-20, configReader->getScreenHeight() + 100);
    this->level = level;
    initLevel();
    bullets.reserve(bulletLength);
    for (int i = 0; i <= bulletLength; ++i) {
        bullets.emplace_back(abstractFactory->createAlienBullet(this->aliens[8]->getXCoord(),
                                                                this->aliens[8]->getYCoord()));
    }
}

void Game::AlienManager::createAliens() {
    for (int i = 0; i < alienLength; i++) {
        if (i < alienLength/alienTypes) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::boss, i * 100, 100));
        } else if (i >= alienLength/alienTypes && i < alienLength/2) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::michiel, (i - alienLength/alienTypes) * 100, 200));
        } else if (i >= alienLength/2 && i < alienLength - alienLength/4) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::clifford, (i - alienLength/2) * 100, 300));
        } else if (i >= (alienLength - alienLength/4) && i < alienLength) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::thomas, (i - (alienLength - alienLength/4)) * 100, 400));
        }
    }
}

void Game::AlienManager::Visualize() {
    for (int i = 0; i < alienLength; i++) {
        this->aliens[i]->Visualize();
        this->aliens[i]->move();
        if (this->aliens[i]->hitBoundary()) {
            moveAndCheck(alienLength);
        }
        if (canon->checkCollision(this->aliens[i])) {
            this->aliens[i]->setAlive(false);
            handleCollision(i, alienLength);
        } else {
            this->aliens[i]->Visualize();
        }
    }
    this->bullets[bulletLength]->Visualize();
    this->bullets[bulletLength]->shootBullet();
    int a = rand() % 200;
    if (a == 36) {
        alienShoot();
    }
}

void Game::AlienManager::moveAndCheck(int length) {
    for (int i = 0; i < length; i++) {
        int move = aliens[i]->getMoveAlien();
        if (this->aliens[i]->getMoveAlien() > 0) {
            move = -1;
        } else {
            move = 1;
        }
        this->aliens[i]->setMoveDirection(move);
        this->aliens[i]->setYCoord(this->aliens[i]->getYCoord() + configReader->getAlienSpeed());
    }
}

void Game::AlienManager::handleCollision(int i, int length) {
    this->aliens.erase(aliens.begin() + i);
    alienLength--;
    aliensKilled++;
}

void Game::AlienManager::alienShoot() {
    int i = rand() % alienLength;
    if (this->aliens[i]->isAlive()) {
        bulletLength--;
        this->bullets[bulletLength]->setXCoord(this->aliens[i]->getXCoord());
        this->bullets[bulletLength]->setYCoord(this->aliens[i]->getYCoord());
        this->currentBullet = this->bullets[bulletLength];
    }
}

bool Game::AlienManager::checkCollision(PlayerShip *playership) {
    if (collisionController->bulletAlien(currentBullet, playership)) {
        this->currentBullet->setYCoord(0);
        return true;
    } else {
        return false;
    }
}

int Game::AlienManager::getAlienLength() const {
    return alienLength;
}

int Game::AlienManager::getAliensKilled() const {
    return aliensKilled;
}

void Game::AlienManager::initLevel() {
    if (level == 1) {
        alienLength = 32;
    } else if (level == 2) {
        alienLength = 36;
    } else if (level == 3) {
        alienLength = 40;
    }
    aliens.reserve(alienLength);
    alienTypes = 4;
    createAliens();
}
