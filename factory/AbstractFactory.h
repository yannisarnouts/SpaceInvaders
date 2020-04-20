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
#include "../model/Life.h"
#include "../model/Timer.h"
#include "../model/Bonus.h"

namespace Game {
    class AbstractFactory {
    public:
        AbstractFactory();
        // playership
        virtual PlayerShip *createPlayerShip() = 0;
        virtual Life *createLife()=0;
        virtual Bullet *createBullet(int xCoord, int yCoord) = 0;
        virtual Score *createScore() = 0;

        //Alien
//        std::string path
        virtual Alien *createAlien(AlienType alienType, int xPos, int yPos) = 0;
        virtual AlienBullet* createAlienBullet(std::string path, int xCoord, int yCoord)=0;

        //extra
        virtual Bonus *createBonus(int xPos, int yPos, BonusType bonusType)=0;
        virtual Background *createBackground(std::string path) = 0;
        virtual Timer *createTimer()=0;
        virtual bool pollEvents() = 0;
        virtual void render() = 0;
        virtual void close() = 0;
    };
}

#endif //PROJECT_ABSTRACTFACTORY_H
