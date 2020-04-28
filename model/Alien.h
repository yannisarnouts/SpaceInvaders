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
        virtual ~Alien();
        bool hitBoundary(int field_width);
        virtual void Visualize() = 0;
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
    };
}

#endif //PROJECT_ALIEN_H
