//
// Created by Gebruiker on 4/04/2020.
//

#ifndef PROJECT_ALIENBULLET_H
#define PROJECT_ALIENBULLET_H

#include "Entity.h"

namespace Game {
    class AlienBullet : public Entity {
    public:
        AlienBullet();

        AlienBullet(int xCoord, int yCoord, int width, int height);
        void shootBullet();
        virtual void Visualize() = 0;

        virtual void close() = 0;
    };
}

#endif //PROJECT_ALIENBULLET_H
