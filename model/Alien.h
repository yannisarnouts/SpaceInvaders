//
// Created by Gebruiker on 12/03/2020.
//

#ifndef PROJECT_ALIEN_H
#define PROJECT_ALIEN_H


class Alien {
public:
    Alien();
    virtual void Visualize(int xPos, int yPos)=0;
    virtual void close()=0;
    virtual int getXPos()=0;
    virtual int getYPos()=0;
};


#endif //PROJECT_ALIEN_H
