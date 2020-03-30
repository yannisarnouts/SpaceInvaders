//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_BULLET_H
#define PROJECT_BULLET_H


#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet();
    Bullet(int xCoord, int yCoord, int width, int height);
    virtual void Visualize()=0;
    virtual void close()=0;
    void shootBullet();
};


#endif //PROJECT_BULLET_H
