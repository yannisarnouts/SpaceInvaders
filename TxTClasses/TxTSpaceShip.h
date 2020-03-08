//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_TXTSPACESHIP_H
#define PROJECT_TXTSPACESHIP_H


#include "../model/AbstractPlayerShip.h"

class TxTSpaceShip : public AbstractPlayerShip {
public:
    TxTSpaceShip();

    TxTSpaceShip(int xCoord, int yCoord, int width, int height);

    void Visualize(AbstractPlayerShip abstractPlayerShip) override;
};


#endif //PROJECT_TXTSPACESHIP_H
