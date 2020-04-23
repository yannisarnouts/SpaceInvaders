//
// Created by Gebruiker on 12/03/2020.
//

#ifndef PROJECT_ALIEN_H
#define PROJECT_ALIEN_H


#include "AlienType.h"
#include "Entity.h"

namespace Game {
    class Alien : public Entity {
    public:
        Alien();
        Alien(int xCoord, int yCoord, int width, int height, AlienType alienType);
        bool hitBoundary();
        virtual void Visualize() = 0;
        virtual void close() = 0;
        void move();
        int getMoveAlien() const;
        void setMoveDirection(int moveAlien);
        bool isAlive() const;
        void setAlive(bool alive);

        AlienType getAlienType() const;

    private:
        AlienType alienType;
        int moveAlien = 1;
        bool alive = true;
        int SCREEN_WIDTH = 950;
    };
}

#endif //PROJECT_ALIEN_H
