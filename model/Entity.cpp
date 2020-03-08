//
// Created by Gebruiker on 3/03/2020.
//

#include <iostream>
#include "Entity.h"

Entity::Entity() {}

int Entity::getXCoord() const {
    return xCoord;
}

int Entity::getYCoord() const {
    return yCoord;
}

void Entity::setXCoord(int xCoord) {
    Entity::xCoord = xCoord;
}

void Entity::setYCoord(int yCoord) {
    Entity::yCoord = yCoord;
}

Entity::Entity(int xCoord, int yCoord, int width, int height) : xCoord(xCoord), yCoord(yCoord), width(width),
                                                                height(height) {}
