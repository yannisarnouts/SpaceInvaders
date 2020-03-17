//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_ALIENS_H
#define PROJECT_ALIENS_H


#include "../factory/AbstractFactory.h"

class Aliens {
public:
    Aliens(AbstractFactory *abstractFactory);
    void Visualize(int y);
    void Visualize2(int y);
    void Visualize3(int y);
    void Visualize4(int y);
    void createAliens(int yCoord,std::string imgPath);
    void createAliens2(int yCoord,std::string imgPath);
    void createAliens3(int yCoord,std::string imgPath);
    void createAliens4(int yCoord,std::string imgPath);

private:
    AbstractFactory* abstractFactory;
    Alien* aliens[11];
    Alien* aliens2[11];
    Alien* aliens3[11];
    Alien* aliens4[11];
    int yCoord;
};


#endif //PROJECT_ALIENS_H
