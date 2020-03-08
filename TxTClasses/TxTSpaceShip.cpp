//
// Created by Gebruiker on 3/03/2020.
//

#include <iostream>
#include "TxTSpaceShip.h"

TxTSpaceShip::TxTSpaceShip() {}

void TxTSpaceShip::Visualize(AbstractPlayerShip abstractPlayerShip) {
    printf("Positie schip: X=%d Y=%d\n", abstractPlayerShip.getXCoord(), abstractPlayerShip.getYCoord());
}

TxTSpaceShip::TxTSpaceShip(int xCoord, int yCoord, int width, int height) : AbstractPlayerShip(xCoord, yCoord, width,
                                                                                               height) {}
