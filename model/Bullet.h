//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_BULLET_H
#define PROJECT_BULLET_H


class Bullet {
public:
    Bullet();
    virtual void Visualize(int xCoord, int yCoord)=0;
    virtual void close()=0;
    virtual int getXCoord()=0;
    virtual int getYCoord()=0;
};


#endif //PROJECT_BULLET_H
