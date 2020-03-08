//
// Created by Gebruiker on 3/03/2020.
//

#include <iostream>
#include "TxTAlien.h"

TxTAlien::TxTAlien() {}

void TxTAlien::Visualize(AbstractAlien alien) {
    //AbstractPlayerShip::Visualize();
    printf("Positie alien: X= %d Y=%d\n", alien.getXCoord(), alien.getYCoord());
}

TxTAlien::TxTAlien(int xCoord, int yCoord, int width, int height) : AbstractAlien(xCoord, yCoord, width, height) {}
