//
// Created by Gebruiker on 7/04/2020.
//

#include <iostream>
#include "BonusManager.h"

Game::BonusManager::BonusManager() {}

Game::BonusManager::BonusManager(Game::AbstractFactory *abstractFactory) : abstractFactory(abstractFactory) {
    this->abstractFactory = abstractFactory;
    this->timer = abstractFactory->createTimer();
    createBonusses();
}


void Game::BonusManager::createBonusses() {
    bonusses.reserve(10);
    for (int i = 0; i < 10; ++i) {
        bonusses.emplace_back(abstractFactory->createBonus(rand() % SCREEN_WIDTH, -100, BonusType(rand() % 4)));
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
    int a = rand() % 300;
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
