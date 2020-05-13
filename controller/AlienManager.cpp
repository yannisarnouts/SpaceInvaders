//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "AlienManager.h"

Game::AlienManager::AlienManager(AbstractFactory *abstractFactory, CanonManager *canon, ConfigReader *configReader, int level, int initAliensKilled, Timer *timer) {
    this->abstractFactory = abstractFactory;
    this->canon = canon;
    this->configReader = configReader;
    this->collisionController = new CollisionController();
    this->aliensKilled = initAliensKilled;
    this->level = level;
    this->timer = timer;
    initLevel();
    bullets.reserve(bulletLength);
    for (int i = 0; i <= bulletLength; ++i) {
        bullets.emplace_back(abstractFactory->createAlienBullet(this->aliens[8]->getXCoord(),
                                                                this->aliens[8]->getYCoord()));
    }
    this->currentBullet = bullets[0];
}

/*
 * create aliens and add them to the vector
 * aliens can be of a specific type
 * position determined by the screen width
 */
void Game::AlienManager::createAliens() {
    int xi = configReader->getScreenWidth()/12;
    for (int i = 0; i < alienLength; i++) {
        if (i < bossLength && alienTypes > 0) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::boss, i * xi, configReader->getScreenHeight()/12));
        } else if (i >= bossLength && i < bossLength + michielLength && alienTypes > 1) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::michiel, (i - bossLength) * xi, configReader->getScreenHeight()/6));
        } else if (i >= bossLength + michielLength && i < bossLength + michielLength + cliffLength && alienTypes > 2) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::clifford, (i - bossLength - michielLength) * xi, configReader->getScreenHeight()/4));
        } else if (i >= bossLength + michielLength + cliffLength && i < bossLength + michielLength + cliffLength + thomasLength && alienTypes > 3) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::thomas, (i - bossLength - michielLength - cliffLength) * xi, configReader->getScreenHeight()/3));
        } else if (i >= bossLength + michielLength + cliffLength + thomasLength && i < bossLength + michielLength + cliffLength + thomasLength + michielLength && alienTypes > 4) {
            this->aliens.emplace_back(abstractFactory->createAlien(AlienType::michiel, (i - bossLength - michielLength - cliffLength - thomasLength) * xi, configReader->getScreenHeight()/2.4));
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
        this->aliens[i]->move(timer->getDeltaTime());
        if (this->aliens[i]->hitBoundary(configReader->getScreenWidth())) {
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
    if (a == 36 && shoot) {
        shoot = false;
        alienShoot();
    }
    if (currentBullet->getYCoord() > this->configReader->getScreenHeight()) {
        shoot = true;
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
        this->aliens[i]->setYCoord(this->aliens[i]->getYCoord() + configReader->getAlienSpeed() * timer->getDeltaTime());
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
 * initialise depending on the level and screen width
 */
void Game::AlienManager::initLevel() {
    if (level == 1) {
        bossLength = 8; cliffLength = 8; michielLength = 8;
        alienTypes = 3;
        alienLength = bossLength + michielLength + cliffLength;
    } else if (level == 2) {
        if (configReader->getScreenWidth() <= 700) {
            bossLength = 8; cliffLength = 8; michielLength = 8; thomasLength = 8;
        } else {
            bossLength = 9; cliffLength = 9; michielLength = 9; thomasLength = 9;
        }
        alienTypes = 4;
        alienLength = bossLength + michielLength + cliffLength + thomasLength;
    } else if (level == 3) {
        if (configReader->getScreenWidth() <= 700) {
            bossLength = 8; cliffLength = 8; michielLength = 8; thomasLength = 8;
        } else {
            bossLength = 9; cliffLength = 9; michielLength = 9; thomasLength = 9;
        }
        alienTypes = 5;
        alienLength = bossLength + michielLength + cliffLength + thomasLength + michielLength;
    }
    aliens.reserve(alienLength);
    createAliens();
}

Game::AlienManager::~AlienManager() {
    for (auto &alien : aliens) {
        delete alien;
    }
}
