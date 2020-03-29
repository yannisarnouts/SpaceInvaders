//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_ALIENS_H
#define PROJECT_ALIENS_H


#include "../factory/AbstractFactory.h"

class Aliens {
public:
    Aliens(AbstractFactory *abstractFactory);
    void Visualize(int y, AlienType alienType);
    void VisualizeLeft(int y, AlienType alienType);
    void VisualizeRight(int y, AlienType alienType);
    void createAliens(int number, AlienType alienType, std::string imgPath, int y);
    void moveAliens();

private:
    AbstractFactory* abstractFactory;
    Alien* aliens[4][3];
    int yCoord;
};


#endif //PROJECT_ALIENS_H
