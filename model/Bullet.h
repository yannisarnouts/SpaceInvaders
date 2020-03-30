//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_BULLET_H
#define PROJECT_BULLET_H


class Bullet {
public:
    Bullet();
    Bullet(int width, int height, int xCoord, int yCoord);
    int getWidth() const;
    int getHeight() const;
    int getXCoord() const;
    void setXCoord(int xCoord);
    int getYCoord() const;
    virtual void Visualize()=0;
    virtual void close()=0;
    void shootBullet();

private:
    int width; int height;
    int xCoord; int yCoord;
};


#endif //PROJECT_BULLET_H
