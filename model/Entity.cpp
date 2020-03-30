//
// Created by Gebruiker on 30/03/2020.
//

#include <iostream>
#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int xCoord, int yCoord, int width, int height) : xCoord(xCoord), yCoord(yCoord), width(width),
                                                                height(height) {
    this->yCoord = yCoord;
    this->xCoord = xCoord;
    this->width = width;
    this->height = height;
}

int Entity::getWidth() const {
    return width;
}

void Entity::setWidth(int width) {
    Entity::width = width;
}

int Entity::getHeight() const {
    return height;
}

void Entity::setHeight(int height) {
    Entity::height = height;
}


int Entity::getXCoord() const {
    return xCoord;
}

void Entity::setXCoord(int xCoord) {
    Entity::xCoord = xCoord;
}

int Entity::getYCoord() const {
    return yCoord;
}

void Entity::setYCoord(int yCoord) {
    Entity::yCoord = yCoord;
}

