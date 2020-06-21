//
// Created by Gebruiker on 18/03/2020.
//

#include "CanonManager.h"
#include "KeyHandler.h"

Game::CanonManager::CanonManager() {}

Game::CanonManager::CanonManager(AbstractFactory *abstractFactory, PlayerShip *playerShip, ConfigReader *configReader, int level, int initScore, int initBulletsFired, Timer *timer) {
    this->configReader = configReader;
    this->canonLength = configReader->getCanonLength();
    this->bulletsFired = initBulletsFired;
    this->currentBullet = abstractFactory->createBullet(0, 0);
    this->score = abstractFactory->createScore();
    this->abstractFactory = abstractFactory;
    this->playerShip = playerShip;
    this->collisionController = new CollisionController();
    this->timer = timer;
    this->level = level;
    this->score->setPoints(initScore);
    this->loadCannon();
}

Game::Bullet *Game::CanonManager::createBullet(int shipX, int shipY) {
    Bullet *bullet = abstractFactory->createBullet(shipX, shipY);
    return bullet;
}

/*
 * check if the shoot key is pressed
 * set shoot the bullet if the key is pressed and there is no other bullet in the field
 * check if you still have bullets and fire the canon
 */
void Game::CanonManager::runCannon() {
    KeyHandler keyHandler;
    int direction = keyHandler.directions();
    timer->update();
    if (direction == KeyP::UP && !shoot) {
        canonLength--; bulletsFired++;
        this->bullets[canonLength]->setXCoord(this->playerShip->getXCoord());
        shoot = true;
    }
    if (shoot && canonLength > 0) {
        this->fireCannon(this->bullets[canonLength]);
    }
    score->Visualize();
}

/*
 * move the bullet based on it's speed
 */
void Game::CanonManager::fireCannon(Bullet *b) {
    this->currentBullet = b;
    this->currentBullet->setYCoord(this->currentBullet->getYCoord() - timer->getDeltaTime() * configReader->getBulletSpeed());
    if (b->getYCoord() <= 5) {
        shoot = false;
    }
    b->Visualize();
}

/*
 * load canon based on the level
 */
void Game::CanonManager::loadCannon() {
    switch (level) {
        case 1: canonLength = 500; break;
        case 2: canonLength = 100; break;
        case 3: canonLength = 60; break;
        default: canonLength = 500;
    }
    bullets.reserve(canonLength);
    for (int i = 0; i < canonLength; ++i) {
        bullets[i] = createBullet(this->playerShip->getXCoord(), this->playerShip->getYCoord());
    }
}

/*
 * check colission with the aliens
 * different alien types gives different points
 */
bool Game::CanonManager::checkCollision(Alien *alien) {
    if (collisionController->bulletPlayerShip(currentBullet, alien)) {
        shoot = false;
        this->currentBullet->setYCoord(0);
        if  (alien->getAlienType() == AlienType::thomas) {
            score->setPoints(score->getPoints() + 1);
        } else if (alien->getAlienType() == AlienType::clifford) {
            score->setPoints(score->getPoints() + 2);
        } else if (alien->getAlienType() == AlienType::michiel) {
            score->setPoints(score->getPoints() + 4);
        } else if (alien->getAlienType() == AlienType::boss) {
            score->setPoints(score->getPoints() + 5);
        }
        return true;
    } else {
        return false;
    }
}

Game::Score *Game::CanonManager::getScore() const {
    return score;
}

int Game::CanonManager::getBulletsFired() {
    return bulletsFired;
}

Game::CanonManager::~CanonManager() {
    for (auto &bullet : bullets) {
        delete bullet;
    }
}

