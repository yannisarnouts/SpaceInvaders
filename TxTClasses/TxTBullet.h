//
// Created by Gebruiker on 7/03/2020.
//

#ifndef PROJECT_TXTBULLET_H
#define PROJECT_TXTBULLET_H


#include "../model/AbstractBullet.h"

class TxTBullet : public AbstractBullet {
public:
    TxTBullet();
    TxTBullet(int xCoord, int yCoord, int width, int height, int speed);

    void Visualize(AbstractBullet bullet) override;
};


#endif //PROJECT_TXTBULLET_H
