//
// Created by Gebruiker on 7/04/2020.
//

#include <iostream>
#include "BonusManager.h"

Game::BonusManager::BonusManager() {}

Game::BonusManager::BonusManager(Game::AbstractFactory *abstractFactory, Game::PlayerManager *playerManager,
                                 Game::CanonManager *canonManager, ConfigReader *configReader, Timer *timer) {
    this->abstractFactory = abstractFactory;
    this->collisionController = new CollisionController();
    this->playerShip = playerManager->getPlayerShip();
    this->canonManager = canonManager;
    this->configReader = configReader;
    this->timer = timer;
    createBonusses();
}

/*
 * creates 10 bonusses and places it in the vector
 */
void Game::BonusManager::createBonusses() {
    bonusses.reserve(10);
    for (int i = 0; i < 10; ++i) {
        bonusses.emplace_back(abstractFactory->createBonus(rand() % configReader->getScreenWidth(), -100, BonusType(rand() % 4)));
    }
}

void Game::BonusManager::Visualize() {
    for (int i = 0; i < bonusses.size(); ++i) {
        bonusses[i]->Visualize();
    }
}

/*
 * shoot a random bonus on a random time
 */
void Game::BonusManager::runBonusses() {
    timer->update();
    Visualize();
    int a = rand() % 100;
    if (a == 38 && !runBonus) {
        runBonus = true;
        i = rand() % 10;
    }
    if (runBonus) {
        fireBonusses();
        checkCollision();
        if (this->bonusses[i]->getYCoord() > configReader->getScreenHeight()) {
            runBonus = false;
        }
    }
}

void Game::BonusManager::fireBonusses() {
    this->bonusses[i]->setYCoord(this->bonusses[i]->getYCoord() + timer->getDeltaTime() * configReader->getBonusSpeed());
}

/*
 * checks for collision with the playership
 * if there is a collision there occurs an event
 */
bool Game::BonusManager::checkCollision() {
    if (collisionController->bonusPlayerShip(this->bonusses[i], this->playerShip)) {
        this->bonusses[i]->setYCoord(configReader->getScreenHeight());
        bonusType = bonusses[i]->getBonusType();
        bonussesCaught++;
        if (bonusType == BonusType::LIFES) {
            playerShip->setLife(5);
        } else if (bonusType == BonusType::POINTS) {
            canonManager->getScore()->setPoints(canonManager->getScore()->getPoints() + 5);
        } else if (bonusType == BonusType::SPEED) {
            playerShip->setSpeed( timer->getDeltaTime() * 15);
        } else if (bonusType == BonusType::BADLUCK) {
            playerShip->setSpeed( timer->getDeltaTime() * 5);
            canonManager->getScore()->setPoints(canonManager->getScore()->getPoints() - 10);
        }
        return true;
    }
    return false;
}

int Game::BonusManager::getBonussesCaught() const {
    return bonussesCaught;
}

Game::BonusManager::~BonusManager() {
    for (auto &bonus: bonusses) {
        delete bonus;
    }
}
