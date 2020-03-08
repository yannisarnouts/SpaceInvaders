//
// Created by Gebruiker on 7/03/2020.
//

#ifndef PROJECT_ABSTRACTBULLET_H
#define PROJECT_ABSTRACTBULLET_H


#include "Entity.h"

class AbstractBullet : public Entity {
public:
    AbstractBullet();
    AbstractBullet(int xCoord, int yCoord, int width, int height, int speed);
    virtual void Visualize(AbstractBullet bullet);
    int getSpeed() const;
    void setSpeed(int speed);

private:
    int speed;
};


#endif //PROJECT_ABSTRACTBULLET_H
