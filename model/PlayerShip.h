//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_PLAYERSHIP_H
#define PROJECT_PLAYERSHIP_H


class PlayerShip {
public:
    PlayerShip();
    virtual void Visualize()=0;
    virtual void close()=0;
    virtual int getXCoord()=0;
    virtual int getYCoord()=0;
    virtual int getWidth()=0;
    virtual int getHeight()=0;
};


#endif //PROJECT_PLAYERSHIP_H
