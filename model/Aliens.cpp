//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "Aliens.h"

Aliens::Aliens(AbstractFactory *abstractFactory, Canon *canon) {
    this->abstractFactory = abstractFactory;
    this->canon = canon;
    createAliens(10, AlienType::clifford, "../assets/cliff.png", 100);
    createAliens(10, AlienType::ruben, "../assets/ruben.png", 200);
    createAliens(10, AlienType::thomas, "../assets/thomas.png", 300);
    createAliens(10, AlienType::michiel, "../assets/michiel.png", 400);
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
//TODO: fix after shot
void Aliens::Visualize(AlienType alienType) {
    if (this->aliens[0][0]->isTurnLeft()) {
        VisualizeLeft(alienType);
    } else if (!this->aliens[0][0]->isTurnLeft()) {
        VisualizeRight(alienType);
    }
}

void Aliens::moveAliens() {
    int rows = sizeof(this->aliens) / sizeof(this->aliens[0]);
    int length = sizeof(this->aliens[3]) / rows;
    if (this->aliens[0][0]->isGoDown()) {
        for (int i = 0; i < length; i++) {
            this->aliens[0][i]->setYCoord(this->aliens[0][i]->getYCoord() + 1);
        }
    }
}

void Aliens::VisualizeLeft(AlienType alienType) {
    int rows = sizeof(this->aliens) / sizeof(this->aliens[0]);
    int length = sizeof(this->aliens[0]) / rows;
    for (int i = 0; i < length; i++) {
        if (alienType == AlienType::michiel) {
            if (!canon->checkCollision(this->aliens[0][i]->getXCoord(), this->aliens[0][i]->getYCoord())) {
                this->aliens[0][i]->Visualize();
            } else {
                handleCollision(0, i, length);
            }
        } else if (alienType == AlienType::ruben) {
            this->aliens[1][i]->Visualize();
        } else if (alienType == AlienType::clifford) {
            this->aliens[2][i]->Visualize();
        } else if (alienType == AlienType::thomas) {
            this->aliens[3][i]->Visualize();
        }
    }
}

void Aliens::VisualizeRight(AlienType alienType) {
    int rows = sizeof(this->aliens) / sizeof(this->aliens[0]);
    int length = (sizeof(this->aliens[0]) / rows) - 1;
    for (int i = length; i >= 0; i--) {
        if (alienType == AlienType::michiel) {
            if (!canon->checkCollision(this->aliens[0][i]->getXCoord(), this->aliens[0][i]->getYCoord())) {
                this->aliens[0][i]->Visualize();
            } else {
                handleCollision(0, i, length);
            }
        } else if (alienType == AlienType::ruben) {
            this->aliens[1][i]->Visualize();
        } else if (alienType == AlienType::clifford) {
            this->aliens[2][i]->Visualize();
        } else if (alienType == AlienType::thomas) {
            this->aliens[3][i]->Visualize();
        }
    }
}

void Aliens::handleCollision(int i, int j, int length) {
    for (int k = j; k < length; ++k) {
        this->aliens[i][k-1] = this->aliens[i][k];
    }
}
