//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_ABSTRACTFACTORY_H
#define PROJECT_ABSTRACTFACTORY_H


#include "../model/Entity.h"
#include "../model/AbstractPlayerShip.h"
#include "../model/AbstractAlien.h"
#include "../model/AbstractBullet.h"

class AbstractFactory {
public:
    AbstractFactory();
    virtual AbstractPlayerShip* createPlayerShip() = 0;
    virtual AbstractAlien* createAlien() = 0;
    virtual AbstractBullet* createBullet() = 0;
};


#endif //PROJECT_ABSTRACTFACTORY_H
