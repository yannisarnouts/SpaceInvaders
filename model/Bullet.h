//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_BULLET_H
#define PROJECT_BULLET_H


class Bullet {
public:
    Bullet();
    virtual void Visualize()=0;
    virtual void close()=0;
    virtual void shootBullet()=0;
    virtual int getXCoord()=0;
    virtual void setXCoord(int x)=0;
    virtual int getYCoord()=0;
    virtual void setYCoord(int yCoord)=0;
    virtual int getHeight()=0;
};


#endif //PROJECT_BULLET_H
