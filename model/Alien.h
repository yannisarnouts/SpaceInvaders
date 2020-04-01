//
// Created by Gebruiker on 12/03/2020.
//

#ifndef PROJECT_ALIEN_H
#define PROJECT_ALIEN_H


#include "AlienType.h"
#include "Entity.h"

class Alien : public Entity {
public:
    Alien();
    Alien(int xCoord, int yCoord, int width, int height, AlienType alienType);
    virtual bool hitBoundary()=0;
    virtual void Visualize()=0;
    virtual void close()=0;
    void move();
    int getMoveAlien() const;

    void setMoveAlien(int moveAlien);

private:
    bool turnLeft = true; bool goDown = false;
    AlienType alienType;
    int moveAlien;

public:
    bool isGoDown() const;
    void setGoDown(bool goDown);
    bool isTurnLeft() const;

    void setTurnLeft(bool turnLeft);

    void moveLeft();
};


#endif //PROJECT_ALIEN_H
