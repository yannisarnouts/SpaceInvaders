//
// Created by Gebruiker on 3/03/2020.
//

#include "AbstractFactory.h"
#include "../model/AbstractPlayerShip.h"

AbstractFactory::AbstractFactory() {}
AbstractPlayerShip *AbstractFactory::createPlayerShip(){}
AbstractAlien *AbstractFactory::createAlien(){}
AbstractBullet* createBullet() {}
