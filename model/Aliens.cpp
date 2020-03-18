//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "Aliens.h"

Aliens::Aliens(AbstractFactory *abstractFactory) {
    this->abstractFactory = abstractFactory;
    createAliens(11, AlienType::clifford, "../assets/cliff.png");
    createAliens(11, AlienType::ruben, "../assets/ruben.png");
    createAliens(11, AlienType::thomas, "../assets/thomas.png");
    createAliens(11, AlienType::michiel, "../assets/michiel.png");
}

void Aliens::createAliens(int number, AlienType alienType, std::string imgPath) {
    for (int i = 0; i < number; i++) {
        Alien *alien = abstractFactory->createAlien(alienType, imgPath);
        if (alienType == AlienType::michiel) {
            this->aliens[i] = alien;
        } else if (alienType == AlienType::ruben) {
            this->aliens2[i] = alien;
        } else if (alienType == AlienType::clifford) {
            this->aliens3[i] = alien;
        } else if (alienType == AlienType::thomas) {
            this->aliens4[i] = alien;
        }
    }
}
void Aliens::Visualize(int y, AlienType alienType) {
    int length = sizeof(this->aliens)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        if (alienType == AlienType::michiel) {
            this->aliens[i]->Visualize(i*100, y);
        } else if (alienType == AlienType::ruben) {
            this->aliens2[i]->Visualize(i*100, y);
        } else if (alienType == AlienType::clifford) {
            this->aliens3[i]->Visualize(i*100, y);
        } else if (alienType == AlienType::thomas) {
            this->aliens4[i]->Visualize(i*100, y);
        }
    }
}
