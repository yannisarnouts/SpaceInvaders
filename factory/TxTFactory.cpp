//
// Created by Gebruiker on 3/03/2020.
//

#include "TxTFactory.h"
#include "../TxTClasses/TxTSpaceShip.h"
#include "../TxTClasses/TxTAlien.h"
#include "../TxTClasses/TxTBullet.h"

TxTFactory::TxTFactory() {}

AbstractPlayerShip *TxTFactory::createPlayerShip() {
    return new TxTSpaceShip(8,9,5,5);
}

AbstractAlien *TxTFactory::createAlien() {
    return new TxTAlien(4,6,5,5);
}

AbstractBullet *TxTFactory::createBullet() {
    return new TxTBullet(4, 6, 2, 2, 8);
}
