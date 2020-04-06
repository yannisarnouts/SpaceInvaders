//
// Created by Gebruiker on 30/03/2020.
//

#ifndef PROJECT_COLLISIONCONTROLLER_H
#define PROJECT_COLLISIONCONTROLLER_H


#include "../model/Bullet.h"
#include "../model/AlienBullet.h"

namespace Game {
    class CollisionController {
    public:
        CollisionController();

        bool bulletObject(Bullet *bullet, int xPos, int yPos);
        bool bulletAlien(AlienBullet *bullet, int xPos, int yPos);
    };
}

#endif //PROJECT_COLLISIONCONTROLLER_H
