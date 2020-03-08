//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_TXTFACTORY_H
#define PROJECT_TXTFACTORY_H


#include "AbstractFactory.h"

class TxTFactory : public AbstractFactory {
public:
    TxTFactory();
    AbstractPlayerShip *createPlayerShip() override;
    AbstractAlien *createAlien() override;

    AbstractBullet *createBullet() override;
};


#endif //PROJECT_TXTFACTORY_H
