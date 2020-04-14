//
// Created by Gebruiker on 30/03/2020.
//

#ifndef PROJECT_COLLISIONCONTROLLER_H
#define PROJECT_COLLISIONCONTROLLER_H


#include "../model/Bullet.h"
#include "../model/AlienBullet.h"
#include "../model/Bonus.h"
#include "../model/PlayerShip.h"
#include "../model/Alien.h"

namespace Game {
    class CollisionController {
    public:
        CollisionController();

        AlienType bulletPlayerShip(Bullet *bullet, Alien *alien);
        bool bulletAlien(AlienBullet *bullet, int xPos, int yPos);
        bool bonusPlayerShip(Bonus *bonus, PlayerShip *playerShip);
    };
}

#endif //PROJECT_COLLISIONCONTROLLER_H
