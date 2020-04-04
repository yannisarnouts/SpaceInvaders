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
#include "../model/Bullet.h"
#include "../model/Score.h"
#include "../model/AlienBullet.h"

namespace Game {
    class AbstractFactory {
    public:
        AbstractFactory();

        virtual PlayerShip *createPlayerShip(std::string path) = 0;

        virtual Alien *createAlien(AlienType alienType, std::string path, int xPos, int yPos) = 0;

        virtual Bullet *createBullet(std::string path, int xCoord, int yCoord) = 0;
        virtual AlienBullet* createAlienBullet(std::string path, int xCoord, int yCoord)=0;
        virtual Score *createScore() = 0;
        virtual Background *createBackground(std::string path) = 0;

        virtual bool pollEvents() = 0;

        virtual void init() = 0;

        virtual void render() = 0;

        virtual void close() = 0;
    };
}

#endif //PROJECT_ABSTRACTFACTORY_H
