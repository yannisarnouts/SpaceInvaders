//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "AlienManager.h"

Game::AlienManager::AlienManager(AbstractFactory *abstractFactory, CanonManager *canon, ConfigReader *configReader, int level, int initAliensKilled) {
    this->abstractFactory = abstractFactory;
    this->canon = canon;
    this->configReader = configReader;
    this->collisionController = new CollisionController();
    this->currentBullet = abstractFactory->createAlienBullet(-20, configReader->getScreenHeight() + 100);
    this->aliensKilled = initAliensKilled;
    this->level = level;
    initLevel();
    bullets.reserve(bulletLength);
    for (int i = 0; i <= bulletLength; ++i) {
        bullets.emplace_back(abstractFactory->createAlienBullet(this->aliens[8]->getXCoord(),
                                                                this->aliens[8]->getYCoord()));
    }
}

/*
 * create aliens and add them to the vector
 * aliens can be of a specific type
 */
void Game::AlienManager::createAliens() {
    for (int i = 0; i < alienLength; i++) {
        if (i < bossLength && alienTypes > 0) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::boss, i * 100, 100));
        } else if (i >= bossLength && i < bossLength + michielLength && alienTypes > 1) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::michiel, (i - bossLength) * 100, 200));
        } else if (i >= bossLength + michielLength && i < bossLength + michielLength + cliffLength && alienTypes > 2) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::clifford, (i - bossLength - michielLength) * 100, 300));
        } else if (i >= bossLength + michielLength + cliffLength && i < bossLength + michielLength + cliffLength + thomasLength && alienTypes > 3) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::thomas, (i - bossLength - michielLength - cliffLength) * 100, 400));
        } else if (i >= bossLength + michielLength + cliffLength + thomasLength && i < bossLength + michielLength + cliffLength + thomasLength + michielLength && alienTypes > 4) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::michiel, (i - bossLength - michielLength - cliffLength - thomasLength) * 100, 500));
        }
    }
}

/*
 * The visualize function
 * Calls the move, boundary check and collisions handler methods
 * Shoots and visualize bullets
 */
void Game::AlienManager::Visualize() {
    for (int i = 0; i < alienLength; i++) {
        this->aliens[i]->Visualize();
        this->aliens[i]->move();
        if (this->aliens[i]->hitBoundary()) {
            moveAndCheck(alienLength);
        }
        if (canon->checkCollision(this->aliens[i])) {
            this->aliens[i]->setAlive(false);
            handleCollision(i);
        } else {
            this->aliens[i]->Visualize();
        }
    }
    this->bullets[bulletLength]->Visualize();
    this->bullets[bulletLength]->shootBullet();
    int a = rand() % 200 / level;
    if (a == 36) {
        alienShoot();
    }
}

/*
 * Alien can move left or right
 * Positive/negative value defines the direction
 * Alien moves in y-direction
 */
void Game::AlienManager::moveAndCheck(int length) {
    for (int i = 0; i < length; i++) {
        int move;
        if (this->aliens[i]->getMoveAlien() > 0) {
            move = -1;
        } else {
            move = 1;
        }
        this->aliens[i]->setMoveDirection(move);
        this->aliens[i]->setYCoord(this->aliens[i]->getYCoord() + configReader->getAlienSpeed());
    }
}

/*
 * remove alien on bullet hit
 */
void Game::AlienManager::handleCollision(int i) {
    this->aliens.erase(aliens.begin() + i);
    alienLength--;
    aliensKilled++;
}

/*
 * method for a random and living alien to shoot a bullet
 */
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

/*
 * initialise depending on the level
 */
void Game::AlienManager::initLevel() {
    if (level == 1) {
        bossLength = 8; cliffLength = 8; michielLength = 8;
        alienTypes = 3;
        alienLength = bossLength + michielLength + cliffLength;
    } else if (level == 2) {
        bossLength = 9; cliffLength = 9; michielLength = 9; thomasLength = 9;
        alienTypes = 4;
        alienLength = bossLength + michielLength + cliffLength + thomasLength;
    } else if (level == 3) {
        bossLength = 10; cliffLength = 10; michielLength = 10; thomasLength = 10;
        alienTypes = 5;
        alienLength = bossLength + michielLength + cliffLength + thomasLength + michielLength;
    }
    aliens.reserve(alienLength);
    createAliens();
}

Game::AlienManager::~AlienManager() {

}
