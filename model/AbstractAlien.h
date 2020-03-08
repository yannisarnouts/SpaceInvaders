//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_ABSTRACTALIEN_H
#define PROJECT_ABSTRACTALIEN_H


#include "Entity.h"

class AbstractAlien : public Entity {
public:
    AbstractAlien();

    AbstractAlien(int xCoord, int yCoord, int width, int height);

    virtual void Visualize(AbstractAlien alien);
};


#endif //PROJECT_ABSTRACTALIEN_H
