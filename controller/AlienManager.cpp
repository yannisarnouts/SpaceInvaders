//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "AlienManager.h"

Game::AlienManager::AlienManager(AbstractFactory *abstractFactory, CanonManager *canon, ConfigReader *configReader) {
    this->abstractFactory = abstractFactory;
    this->canon = canon;
    this->configReader = configReader;
    this->collisionController = new CollisionController();
    this->currentBullet = abstractFactory->createAlienBullet("", -20, -20);
    aliens.reserve(4);
    createAliens(bossLength, AlienType::boss, "../assets/boss.png", 100, 0);
    createAliens(michielLength, AlienType::michiel, "../assets/michiel.png", 200, 1);
    createAliens(cliffordLength, AlienType::clifford, "../assets/cliff.png", 300, 2);
    createAliens(thomasLength, AlienType::thomas, "../assets/thomas.png", 400, 3);
    this->alienLength = bossLength + michielLength + cliffordLength + thomasLength;
    bullets.reserve(bulletLength);
    for (int i = 0; i <= bulletLength; ++i) {
        bullets.emplace_back(abstractFactory->createAlienBullet("../assets/bullet.png", this->aliens[1][1]->getXCoord(),
                                                                this->aliens[1][1]->getYCoord()));
    }
}

void Game::AlienManager::createAliens(int number, AlienType alienType, std::string imgPath, int y, int a) {
    aliens[a].reserve(number);
    for (int i = 0; i < number; i++) {
        Alien *alien;
        alien = abstractFactory->createAlien(alienType, imgPath, i * 100, y);
        this->aliens[a].emplace_back(alien);
    }
}

void Game::AlienManager::Visualize(AlienType alienType) {
    if (alienType == AlienType::michiel) {
        VisualizeType(alienType, 0, michielLength);
    } else if (alienType == AlienType::boss) {
        VisualizeType(alienType, 1, bossLength);
    } else if (alienType == AlienType::clifford) {
        VisualizeType(alienType, 2, cliffordLength);
    } else if (alienType == AlienType::thomas) {
        VisualizeType(alienType, 3, thomasLength);
    }
    this->bullets[bulletLength]->Visualize();
    int a = rand() % 250;
    if (a == 136) {
        alienShoot();
    }
}

void Game::AlienManager::moveAndCheck(int a, int length) {
    int move = 0;
    for (int i = 0; i < length; i++) {
        if (this->aliens[a][i]->getMoveAlien() > 0) {
            move = -1;
        } else {
            move = 1;
        }
        this->aliens[a][i]->setMoveAlien(move);
        this->aliens[a][i]->setYCoord(this->aliens[a][i]->getYCoord() + configReader->getAlienSpeed());
    }
}

void Game::AlienManager::VisualizeType(AlienType alienType, int a, int length) {
    int len = 0;
    for (int i = 0; i < length; ++i) {
        if (alienType == AlienType::michiel) {
            len = michielLength;
        } else if (alienType == AlienType::boss) {
            len = bossLength;
        } else if (alienType == AlienType::clifford) {
            len = cliffordLength;
        } else if (alienType == AlienType::thomas) {
            len = thomasLength;
        }
        if (this->aliens[a][i]->hitBoundary()) {
            moveAndCheck(a, len);
        }
        if (canon->checkCollision(this->aliens[a][i])) {
            this->aliens[a][i]->setAlive(false);
            handleCollision(a, i, length, alienType);
        } else {
            this->aliens[a][i]->Visualize();
        }
    }
}

void Game::AlienManager::handleCollision(int i, int j, int length, AlienType alienType) {
    for (int k = j; k < length; ++k) {
        this->aliens[i][k - 1] = this->aliens[i][k];
    }
    if (alienType == AlienType::michiel) {
        michielLength--;
    } else if (alienType == AlienType::boss) {
        bossLength--;
    } else if (alienType == AlienType::clifford) {
        cliffordLength--;
    } else if (alienType == AlienType::thomas) {
        thomasLength--;
    }
    alienLength--;
    aliensKilled++;
}

void Game::AlienManager::alienShoot() {
    int i = rand() % 4;
    int j = rand() % 10;
    if (this->aliens[i][j]->isAlive()) {
        bulletLength--;
        this->bullets[bulletLength]->setXCoord(this->aliens[i][j]->getXCoord());
        this->bullets[bulletLength]->setYCoord(this->aliens[i][j]->getYCoord());
        this->currentBullet = this->bullets[bulletLength];
    }
}

bool Game::AlienManager::checkCollision(int xPos, int yPos) {
    if (collisionController->bulletAlien(currentBullet, xPos, yPos)) {
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
