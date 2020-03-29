//
// Created by Gebruiker on 12/03/2020.
//

#ifndef PROJECT_ALIEN_H
#define PROJECT_ALIEN_H


class Alien {
public:
    Alien();
    virtual void Visualize()=0;
    virtual void close()=0;
    virtual int getXPos()=0;
    virtual void setYCoord(int yCoord)=0;
    virtual void moveLeft()=0;
    virtual void moveRight()=0;
    virtual int getYPos()=0;
    virtual bool isGoDown()=0;
    virtual void setGoDown(bool goDown)=0;
    virtual int getAlienHeight()=0;
    virtual bool isTurnLeft()=0;
};


#endif //PROJECT_ALIEN_H
