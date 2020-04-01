//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "Aliens.h"

Aliens::Aliens(AbstractFactory *abstractFactory, Canon *canon) {
    this->abstractFactory = abstractFactory;
    this->canon = canon;
    createAliens(9, AlienType::michiel, "../assets/michiel.png", 100);
    createAliens(9, AlienType::ruben, "../assets/ruben.png", 200);
    createAliens(9, AlienType::clifford, "../assets/cliff.png", 300);
    createAliens(9, AlienType::thomas, "../assets/thomas.png", 400);
    int rows = sizeof(this->aliens) / sizeof(this->aliens[0]);
    this->michielLength = sizeof(this->aliens[0]) / rows;;
    this->rubenLength = sizeof(this->aliens[1]) / rows;;
    this->cliffordLength = sizeof(this->aliens[2]) / rows;;
    this->thomasLength = sizeof(this->aliens[3]) / rows;;
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
    if (alienType == AlienType::michiel) {
        VisualizeType(alienType, michielLength);
    } else if (alienType == AlienType::ruben) {
        VisualizeType(alienType, rubenLength);
    } else if (alienType == AlienType::clifford) {
        VisualizeType(alienType, cliffordLength);
    } else if (alienType == AlienType::thomas) {
        VisualizeType(alienType, thomasLength);
    }
}

void Aliens::moveAliens(int a, int length) {
    for (int i = 0; i < length; ++i) {
        int move = 0;
        if (this->aliens[a][i]->getMoveAlien() > 0) {
            move = -1;
        } else {
            move = 1;
        }
        this->aliens[a][i]->setMoveAlien(move);
//        this->aliens[a][i]->setYCoord(this->aliens[a][i]->getYCoord() + 1);
        this->aliens[a][i]->setXCoord(this->aliens[a][i]->getXCoord());
    }
}

void Aliens::VisualizeType(AlienType alienType, int length) {
    for (int i = 0; i < length; i++) {
        if (alienType == AlienType::michiel) {
            if (!canon->checkCollision(this->aliens[0][i]->getXCoord(), this->aliens[0][i]->getYCoord())) {
                if (this->aliens[0][i]->hitBoundary()) {
                    moveAliens(0, michielLength);
                }
                this->aliens[0][i]->Visualize();
            } else {
                handleCollision(0, i, length, alienType);
            }
        } else if (alienType == AlienType::ruben) {
            if (!canon->checkCollision(this->aliens[1][i]->getXCoord(), this->aliens[1][i]->getYCoord())) {
                if (this->aliens[1][i]->hitBoundary()) {
                    moveAliens(1, rubenLength);
                }
                this->aliens[1][i]->Visualize();
            } else {
                handleCollision(1, i, length, alienType);
            }
        } else if (alienType == AlienType::clifford) {
            if (!canon->checkCollision(this->aliens[2][i]->getXCoord(), this->aliens[2][i]->getYCoord())) {
                if (this->aliens[2][i]->hitBoundary()) {
                    moveAliens(2, cliffordLength);
                }
                this->aliens[2][i]->Visualize();
            } else {
                handleCollision(2, i, length, alienType);
            }
        } else if (alienType == AlienType::thomas) {
            if (!canon->checkCollision(this->aliens[3][i]->getXCoord(), this->aliens[3][i]->getYCoord())) {
                if (this->aliens[3][i]->hitBoundary()) {
                    moveAliens(3, thomasLength);
                }
                this->aliens[3][i]->Visualize();
            } else {
                handleCollision(3, i, length, alienType);
            }
        }
    }
}

void Aliens::handleCollision(int i, int j, int length, AlienType alienType) {
    for (int k = j; k < length; ++k) {
        this->aliens[i][k - 1] = this->aliens[i][k];
    }
    if (alienType == AlienType::michiel) {
        michielLength--;
    } else if (alienType == AlienType::ruben) {
        rubenLength--;
    } else if (alienType == AlienType::clifford) {
        cliffordLength--;
    } else if (alienType == AlienType::thomas) {
        thomasLength--;
    }
}
