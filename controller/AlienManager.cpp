//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "AlienManager.h"

Game::AlienManager::AlienManager(AbstractFactory *abstractFactory, CanonManager *canon) {
    this->abstractFactory = abstractFactory;
    this->canon = canon;
    this->collisionController = new CollisionController();
    this->currentBullet = abstractFactory->createAlienBullet("", -20, -20);
    aliens.reserve(4);
    createAliens(michielLength, AlienType::michiel, "../assets/michiel.png", 100, 0);
    createAliens(rubenLength, AlienType::ruben, "../assets/ruben.png", 200, 1);
    createAliens(cliffordLength, AlienType::clifford, "../assets/cliff.png", 300, 2);
    createAliens(thomasLength, AlienType::thomas, "../assets/thomas.png", 400, 3);
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
    } else if (alienType == AlienType::ruben) {
        VisualizeType(alienType, 1, rubenLength);
    } else if (alienType == AlienType::clifford) {
        VisualizeType(alienType, 2, cliffordLength);
    } else if (alienType == AlienType::thomas) {
        VisualizeType(alienType, 3, thomasLength);
    }
    this->bullets[bulletLength]->Visualize();
    int a = rand() % 200;
    if (a == 36) {
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
        this->aliens[a][i]->setXCoord(this->aliens[a][i]->getXCoord());
        this->aliens[a][i]->setYCoord(this->aliens[a][i]->getYCoord() + 4);
    }
}

void Game::AlienManager::VisualizeType(AlienType alienType, int a, int length) {
    for (int i = 0; i < length; ++i) {
        if (alienType == AlienType::michiel) {
            if (this->aliens[a][i]->hitBoundary()) {
                moveAndCheck(a, michielLength);
            }
        } else if (alienType == AlienType::ruben) {
            if (this->aliens[a][i]->hitBoundary()) {
                moveAndCheck(a, rubenLength);
            }
        } else if (alienType == AlienType::clifford) {
            if (this->aliens[a][i]->hitBoundary()) {
                moveAndCheck(a, cliffordLength);
            }
        } else if (alienType == AlienType::thomas) {
            if (this->aliens[a][i]->hitBoundary()) {
                moveAndCheck(a, thomasLength);
            }
        }
        if (canon->checkCollision(this->aliens[a][i]->getXCoord(), this->aliens[a][i]->getYCoord())) {
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
    } else if (alienType == AlienType::ruben) {
        rubenLength--;
    } else if (alienType == AlienType::clifford) {
        cliffordLength--;
    } else if (alienType == AlienType::thomas) {
        thomasLength--;
    }
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
