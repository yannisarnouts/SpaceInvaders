//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_ALIENS_H
#define PROJECT_ALIENS_H


#include <vector>
#include "../factory/AbstractFactory.h"
#include "Canon.h"
#include "../controller/CollisionController.h"

class Aliens {
public:
    Aliens(AbstractFactory *abstractFactory, Canon* canon);
    void Visualize(AlienType alienType);
    void VisualizeLeft(AlienType alienType);
    void VisualizeRight(AlienType alienType);
    void createAliens(int number, AlienType alienType, std::string imgPath, int y);
    void moveAliens();
    void handleCollision(int i, int j, int length);

private:
    AbstractFactory* abstractFactory;
    Alien* aliens[4][10];
    int yCoord;
    Canon* canon;
};


#endif //PROJECT_ALIENS_H
