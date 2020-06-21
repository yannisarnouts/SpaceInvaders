//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_LIFE_H
#define PROJECT_LIFE_H

#include "Entity.h"

namespace Game {
    class Life : public Entity {
    public:
        Life();

        Life(int xCoord, int yCoord, int width, int height);

        virtual ~Life();

        virtual void Visualize() = 0;

        int getLife() const;

        void setLife(int life);

    private:
        int life = 3;
    };
}

#endif //PROJECT_LIFE_H
