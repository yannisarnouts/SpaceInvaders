//
// Created by Gebruiker on 7/04/2020.
//

#include <iostream>
#include "BonusManager.h"

Game::BonusManager::BonusManager() {}

Game::BonusManager::BonusManager(Game::AbstractFactory *abstractFactory, Game::PlayerManager *playerManager, Game::CanonManager *canonManager) {
    this->abstractFactory = abstractFactory;
    this->collisionController = new CollisionController();
    this->timer = abstractFactory->createTimer();
    this->playerShip = playerManager->getPlayerShip();
    this->canonManager = canonManager;
    createBonusses();
}

void Game::BonusManager::createBonusses() {
    bonusses.reserve(10);
    for (int i = 0; i < 10; ++i) {
        bonusses.emplace_back(abstractFactory->createBonus(rand() % SCREEN_WIDTH, -100, BonusType(rand() % 4 )));
    }
}

void Game::BonusManager::Visualize() {
    for (int i = 0; i < bonusses.size(); ++i) {
        bonusses[i]->Visualize();
    }
}

void Game::BonusManager::runBonusses() {
    timer->update();
    Visualize();
    checkCollision();
    int a = rand() % 100;
    if (a == 38 && !runBonus) {
        runBonus = true;
        i = rand() % 10;
    }
    if (runBonus) {
        fireBonusses();
    }
    if (this->bonusses[i]->getYCoord() > SCREEN_HEIGHT) {
        runBonus = false;
    }
}

void Game::BonusManager::fireBonusses() {
    this->bonusses[i]->setYCoord(this->bonusses[i]->getYCoord() + timer->getDeltaTime() * 5);
}

bool Game::BonusManager::checkCollision() {
    if (collisionController->bonusPlayerShip(this->bonusses[i], this->playerShip)) {
        this->bonusses[i]->setYCoord(SCREEN_HEIGHT);
        bonusType = bonusses[i]->getBonusType();
        if (bonusType == BonusType::LIFES) {
            playerShip->setLife(playerShip->getLife() * 2);
        } else if (bonusType == BonusType::POINTS) {
            canonManager->getScore()->setPoints(canonManager->getScore()->getPoints() + 5);
        } else if (bonusType == BonusType::SPEED) {
            playerShip->setSpeed( timer->getDeltaTime() * 15);
        } else if (bonusType == BonusType::BADLUCK) {
            playerShip->setSpeed( timer->getDeltaTime() * 15);
            canonManager->getScore()->setPoints(canonManager->getScore()->getPoints() - 10);
        }
        return true;
    }
    return false;
}
