//
// Created by Gebruiker on 30/03/2020.
//

#include <iostream>
#include "CollisionController.h"

CollisionController::CollisionController() {}

bool CollisionController::bulletObject(Bullet *bullet, int xPos, int yPos) {
    return bullet->getYCoord() == yPos && (bullet->getXCoord() >= xPos - 50 && bullet->getXCoord() <= xPos + 50);
}