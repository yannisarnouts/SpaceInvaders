//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "Aliens.h"

Aliens::Aliens(AbstractFactory *abstractFactory) {
    this->abstractFactory = abstractFactory;
    createAliens(yCoord, "../assets/cliff.png");
    createAliens2(yCoord, "../assets/ruben.png");
    createAliens3(yCoord, "../assets/thomas.png");
    createAliens4(yCoord, "../assets/michiel.png");
}

void Aliens::Visualize(int y) {
    int length = sizeof(this->aliens)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        this->aliens[i]->Visualize(i*55, y);
    }
}
void Aliens::Visualize2(int y) {
    int length = sizeof(this->aliens)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        this->aliens2[i]->Visualize(i*55, y);
    }
}
void Aliens::Visualize3(int y) {
    int length = sizeof(this->aliens)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        this->aliens3[i]->Visualize(i*55, y);
    }
}
void Aliens::Visualize4(int y) {
    int length = sizeof(this->aliens)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        this->aliens4[i]->Visualize(i*55, y);
    }
}
void Aliens::createAliens(int yCoord, std::string imgPath) {
    int length = sizeof(this->aliens)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        Alien *alien = abstractFactory->createAlien(AlienType::michiel, imgPath);
        this->aliens[i] = alien;
        this->aliens[i]->Visualize(i*55, this->yCoord);
    }
}
void Aliens::createAliens2(int yCoord, std::string imgPath) {
    int length = sizeof(this->aliens2)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        Alien *alien = abstractFactory->createAlien(AlienType::michiel, imgPath);
        this->aliens2[i] = alien;
    }
}
void Aliens::createAliens3(int yCoord, std::string imgPath) {
    int length = sizeof(this->aliens2)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        Alien *alien = abstractFactory->createAlien(AlienType::michiel, imgPath);
        this->aliens3[i] = alien;
    }
}
void Aliens::createAliens4(int yCoord, std::string imgPath) {
    int length = sizeof(this->aliens2)/ sizeof(this->aliens[0]);
    for (int i = 0; i < length; i++) {
        Alien *alien = abstractFactory->createAlien(AlienType::michiel, imgPath);
        this->aliens4[i] = alien;
    }
}