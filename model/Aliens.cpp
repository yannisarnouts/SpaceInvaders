//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "Aliens.h"

Aliens::Aliens(AbstractFactory *abstractFactory) {
    this->abstractFactory = abstractFactory;
    createAliens(3, AlienType::clifford, "../assets/cliff.png", 100);
    createAliens(3, AlienType::ruben, "../assets/ruben.png", 200);
    createAliens(3, AlienType::thomas, "../assets/thomas.png", 300);
    createAliens(3, AlienType::michiel, "../assets/michiel.png", 400);
}

void Aliens::createAliens(int number, AlienType alienType, std::string imgPath, int y) {
    for (int i = 0; i < number; i++) {
        Alien *alien;
        if (alienType == AlienType::michiel) {
            alien = abstractFactory->createAlien(alienType, imgPath, i * 100, y);
            this->aliens[0][i] = alien;
        } else if (alienType == AlienType::ruben) {
            alien = abstractFactory->createAlien(alienType, imgPath, i * 100, y);
            this->aliens[1][i] = alien;
        } else if (alienType == AlienType::clifford) {
            alien = abstractFactory->createAlien(alienType, imgPath, i * 100, y);
            this->aliens[2][i] = alien;
        } else if (alienType == AlienType::thomas) {
            alien = abstractFactory->createAlien(alienType, imgPath, i * 100, y);
            this->aliens[3][i] = alien;
        }
    }
}

void Aliens::Visualize(int y, AlienType alienType) {
    int rows = sizeof(this->aliens) / sizeof(this->aliens[0]);
    int length = sizeof(this->aliens[0]) / rows;
    if (this->aliens[0][length]->isTurnLeft()) {
        VisualizeLeft(y, alienType);
    } else {
        VisualizeRight(y, alienType);
    }
}

void Aliens::moveAliens() {
    int rows = sizeof(this->aliens) / sizeof(this->aliens[0]);
    int length = sizeof(this->aliens[3]) / rows;
    if (this->aliens[0][0]->isGoDown()) {
        for (int i = 0; i < length; i++) {
            this->aliens[0][i]->setYCoord(this->aliens[0][i]->getYPos() + 1);
        }
    }
}

void Aliens::VisualizeLeft(int y, AlienType alienType) {
    int rows = sizeof(this->aliens) / sizeof(this->aliens[0]);
    int length = sizeof(this->aliens[0]) / rows;
    for (int i = length; i > 0; i--) {
        if (alienType == AlienType::michiel) {
            this->aliens[0][i]->Visualize();
//            moveAliens();
        }
    }
}

void Aliens::VisualizeRight(int y, AlienType alienType) {
    int rows = sizeof(this->aliens) / sizeof(this->aliens[0]);
    int length = sizeof(this->aliens[0]) / rows;
    for (int i = length; i > 0; i--) {
        if (alienType == AlienType::michiel) {
            this->aliens[0][i]->Visualize();
//            moveAliens();
        }
    }
}

