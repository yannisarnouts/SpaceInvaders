//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_ALIENS_H
#define PROJECT_ALIENS_H


#include "../factory/AbstractFactory.h"

class Aliens {
public:
    Aliens(AbstractFactory *abstractFactory);
    void Visualize(AlienType alienType);
    void VisualizeLeft(AlienType alienType);
    void VisualizeRight(AlienType alienType);
    void createAliens(int number, AlienType alienType, std::string imgPath, int y);
    void moveAliens();

private:
    AbstractFactory* abstractFactory;
    Alien* aliens[4][10];
    int yCoord;
};


#endif //PROJECT_ALIENS_H
