//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_ABSTRACTFACTORY_H
#define PROJECT_ABSTRACTFACTORY_H


#include <string>
#include "../model/PlayerShip.h"
#include "../model/Background.h"
#include "../model/Alien.h"
#include "../model/AlienType.h"

class AbstractFactory {
public:
    AbstractFactory();

    virtual PlayerShip* createPlayerShip(std::string path) = 0;
    virtual Alien* createAlien(AlienType alienType, std::string path)=0;
    virtual Background* createBackground(std::string path) = 0;
    virtual bool pollEvents()=0;
    virtual void init(int wh,int ww)=0;
    virtual void render()=0;
    virtual void close()=0;
};


#endif //PROJECT_ABSTRACTFACTORY_H
