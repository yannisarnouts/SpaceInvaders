//
// Created by Gebruiker on 12/03/2020.
//

#ifndef PROJECT_ALIEN_H
#define PROJECT_ALIEN_H


#include "AlienType.h"

class Alien {
public:
    Alien();
    Alien(int width, int height, AlienType alienType, int xPos, int yPos);
    virtual void Visualize()=0;
    virtual void close()=0;
    virtual void moveRight()=0;

private:
    bool turnLeft = true; bool goDown = false;
    int xCoord; int yCoord;
    int alienWidth; int alienHeight;
    AlienType alienType;

public:
    int getAlienWidth() const;
    int getAlienHeight() const;
    int getXCoord() const;

    void setXCoord(int xCoord);

    int getYCoord() const;
    void setYCoord(int yCoord);
    bool isGoDown() const;
    void setGoDown(bool goDown);
    bool isTurnLeft() const;

    void setTurnLeft(bool turnLeft);

    void moveLeft();
};


#endif //PROJECT_ALIEN_H
