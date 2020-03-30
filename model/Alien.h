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

//    Alien(int width, int height, AlienType alienType, int xPos, int yPos);
    virtual void Visualize()=0;
    virtual void close()=0;
    virtual void moveRight()=0;

private:
    bool turnLeft = true; bool goDown = false;
    AlienType alienType;

public:
    int getAlienWidth() const;
    int getAlienHeight() const;
    bool isGoDown() const;
    void setGoDown(bool goDown);
    bool isTurnLeft() const;

    void setTurnLeft(bool turnLeft);

    void moveLeft();
};


#endif //PROJECT_ALIEN_H
