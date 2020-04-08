//
// Created by Gebruiker on 18/03/2020.
//

#include "CanonManager.h"
#include "KeyHandler.h"

Game::CanonManager::CanonManager() {}

Game::CanonManager::CanonManager(AbstractFactory *abstractFactory, PlayerShip *playerShip) {
    this->currentBullet = abstractFactory->createBullet(0, 0);
    this->score = abstractFactory->createScore();
    this->abstractFactory = abstractFactory;
    this->playerShip = playerShip;
    this->collisionController = new CollisionController();
    this->timer = abstractFactory->createTimer();
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
    if (canonLength < 1) {
        this->loadCannon();
    }
    if (shoot) {
        this->fireCannon(this->bullets[canonLength]);
    }
    score->Visualize();
}

void Game::CanonManager::fireCannon(Bullet *b) {
    this->currentBullet = b;
    this->currentBullet->setYCoord(this->currentBullet->getYCoord() - timer->getDeltaTime() * 10);
    if (b->getYCoord() <= 5) {
        shoot = false;
    }
    b->Visualize();
}

void Game::CanonManager::loadCannon() {
    for (int i = 0; i < 200; ++i) {
        bullets[i] = createBullet(this->playerShip->getXCoord(), this->playerShip->getYCoord());
    }
}

bool Game::CanonManager::checkCollision(int xPos, int yPos) {
    if (collisionController->bulletPlayerShip(currentBullet, xPos, yPos)) {
        shoot = false;
        this->currentBullet->setYCoord(0);
        score->setPoints(score->getPoints() + 1);
        return true;
    } else {
        return false;
    }
}

Game::Score *Game::CanonManager::getScore() const {
    return score;
}

