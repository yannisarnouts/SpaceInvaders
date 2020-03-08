//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_ABSTRACTPLAYERSHIP_H
#define PROJECT_ABSTRACTPLAYERSHIP_H


#include "Entity.h"

class AbstractPlayerShip : public Entity {
public:
    AbstractPlayerShip();

    AbstractPlayerShip(int xCoord, int yCoord, int width, int height);

    virtual void Visualize(AbstractPlayerShip abstractPlayerShip);
};


#endif //PROJECT_ABSTRACTPLAYERSHIP_H
