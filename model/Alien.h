//
// Created by Gebruiker on 12/03/2020.
//

#ifndef PROJECT_ALIEN_H
#define PROJECT_ALIEN_H


#include "AlienType.h"
#include "Entity.h"
#include "AlienCanon.h"

namespace Game {
    class Alien : public Entity {
    public:
        Alien();
        Alien(int xCoord, int yCoord, int width, int height, AlienType alienType);
        virtual bool hitBoundary() = 0;
        virtual void Visualize() = 0;
        virtual void close() = 0;
        void move();
        int getMoveAlien() const;
        void setMoveAlien(int moveAlien);

        bool isAlive() const;

        void setAlive(bool alive);

    private:
        AlienType alienType;
        int moveAlien = 1;
        AlienCanon* alienCanon;
        bool alive = true;
    };
}

#endif //PROJECT_ALIEN_H
