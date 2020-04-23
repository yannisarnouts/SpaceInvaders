//
// Created by Gebruiker on 18/03/2020.
//

#include "CanonManager.h"
#include "KeyHandler.h"

Game::CanonManager::CanonManager() {}

Game::CanonManager::CanonManager(AbstractFactory *abstractFactory, PlayerShip *playerShip, ConfigReader *configReader, int level) {
    this->configReader = configReader;
    this->canonLength = configReader->getCanonLength();
    this->currentBullet = abstractFactory->createBullet(0, 0);
    this->score = abstractFactory->createScore();
    this->abstractFactory = abstractFactory;
    this->playerShip = playerShip;
    this->collisionController = new CollisionController();
    this->timer = abstractFactory->createTimer();
    this->level = level;
    this->loadCannon();
}

Game::Bullet *Game::CanonManager::createBullet(int shipX, int shipY) {
    Bullet *bullet = abstractFactory->createBullet(shipX, shipY);
    return bullet;
}

void Game::CanonManager::runCannon() {
    KeyHandler keyHandler;
    int direction = keyHandler.directions();
    timer->update();
    if (direction == KeyP::UP && !shoot) {
        canonLength--;
        this->bullets[canonLength]->setXCoord(this->playerShip->getXCoord());
        shoot = true;
    }
    if (shoot && canonLength > 0) {
        this->fireCannon(this->bullets[canonLength]);
    }
    score->Visualize();
}

void Game::CanonManager::fireCannon(Bullet *b) {
    this->currentBullet = b;
    this->currentBullet->setYCoord(this->currentBullet->getYCoord() - timer->getDeltaTime() * configReader->getBulletSpeed());
    if (b->getYCoord() <= 5) {
        shoot = false;
    }
    b->Visualize();
}

void Game::CanonManager::loadCannon() {
    switch (level) {
        case 1: canonLength = 500; break;
        case 2: canonLength = 100; break;
        case 3: canonLength = 50; break;
        default: canonLength = 500;
    }
    bullets.reserve(canonLength);
    for (int i = 0; i < canonLength; ++i) {
        bullets[i] = createBullet(this->playerShip->getXCoord(), this->playerShip->getYCoord());
    }
}

bool Game::CanonManager::checkCollision(Alien *alien) {
    AlienType resultType = collisionController->bulletPlayerShip(currentBullet, alien);
    if (resultType != AlienType(1000)) {
        shoot = false;
        this->currentBullet->setYCoord(0);
        if  (resultType == AlienType::thomas) {
            score->setPoints(score->getPoints() + 1);
        } else if (resultType == AlienType::clifford) {
            score->setPoints(score->getPoints() + 2);
        } else if (resultType == AlienType::michiel) {
            score->setPoints(score->getPoints() + 4);
        } else if (resultType == AlienType::boss) {
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
    return 200 - canonLength;
}

