//
// Created by Gebruiker on 27/04/2020.
//

#ifndef SPACEINVADERS_LEVEL_H
#define SPACEINVADERS_LEVEL_H

#include "Entity.h"

namespace Game {
    class Level : public Entity {
    public:
        Level();

        Level(int xCoord, int yCoord, int width, int height);

        virtual ~Level();
        int getLevel() const;
        void setLevel(int level);
        virtual void Visualize() = 0;

    private:
        int level = 1;
    };
}

#endif //SPACEINVADERS_LEVEL_H
