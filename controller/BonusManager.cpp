//
// Created by Gebruiker on 7/04/2020.
//

#include <iostream>
#include "BonusManager.h"

Game::BonusManager::BonusManager() {}

Game::BonusManager::BonusManager(Game::AbstractFactory *abstractFactory) : abstractFactory(abstractFactory) {
    this->abstractFactory = abstractFactory;
    this->currentBonus = abstractFactory->createBonus(100, 100, BonusType::LIFES);
    this->timer = abstractFactory->createTimer();
    createBonusses();
}


void Game::BonusManager::createBonusses() {
    bonusses.reserve(10);
    for (int i = 0; i < 10; ++i) {
        bonusses.emplace_back(abstractFactory->createBonus(rand() % SCREEN_WIDTH, 0, BonusType(rand() % 4)));
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
    int a = rand() % 10;
    if (a == 1) {
        runBonus = true;
    }
    while (runBonus) {
        int i = rand() % 10;
        fireBonusses(i);
    }
}

void Game::BonusManager::fireBonusses(int i) {
    this->bonusses[i]->setYCoord(this->bonusses[i]->getYCoord() + 10);
}
