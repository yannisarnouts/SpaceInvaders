//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_TXTALIEN_H
#define PROJECT_TXTALIEN_H


#include "../model/AbstractPlayerShip.h"
#include "../model/AbstractAlien.h"

class TxTAlien : public AbstractAlien {
public:
    TxTAlien();

    TxTAlien(int xCoord, int yCoord, int width, int height);

    void Visualize(AbstractAlien alien) override;
};


#endif //PROJECT_TXTALIEN_H
