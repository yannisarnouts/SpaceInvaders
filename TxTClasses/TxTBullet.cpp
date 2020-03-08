//
// Created by Gebruiker on 7/03/2020.
//

#include "TxTBullet.h"
#include <iostream>

TxTBullet::TxTBullet() {}

TxTBullet::TxTBullet(int xCoord, int yCoord, int width, int height, int speed) : AbstractBullet(xCoord, yCoord, width,
                                                                                                height, speed) {}

void TxTBullet::Visualize(AbstractBullet bullet) {
    printf("Positie bullet: X=%d Y=%d", bullet.getXCoord(), bullet.getYCoord());
}
