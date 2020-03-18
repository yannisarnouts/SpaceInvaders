//
// Created by Gebruiker on 18/03/2020.
//

#ifndef PROJECT_CANON_H
#define PROJECT_CANON_H


#include "../factory/AbstractFactory.h"

class Canon {
public:
    Canon(AbstractFactory *abstractFactory);
    void createBullet(std::string imgPath);
    void Visualize(int shipX, int shipY);
    void shoot();
private:
    AbstractFactory* abstractFactory;
    std::string imgPath;
    int shipX; int shipY;
    Bullet* bullet;
};


#endif //PROJECT_CANON_H
