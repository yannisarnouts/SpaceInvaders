//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_PLAYERSHIP_H
#define PROJECT_PLAYERSHIP_H


#include "Entity.h"

namespace Game {
    class PlayerShip : public Entity {
    public:
        PlayerShip();

        PlayerShip(int xCoord, int yCoord, int width, int height);

        virtual void Visualize() = 0;

        virtual void close() = 0;

        virtual void moveShip() = 0;
    };
}

#endif //PROJECT_PLAYERSHIP_H
