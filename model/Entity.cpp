//
// Created by Gebruiker on 30/03/2020.
//

#include "Entity.h"

Game::Entity::Entity() {}

Game::Entity::Entity(int xCoord, int yCoord, int width, int height) : xCoord(xCoord), yCoord(yCoord), width(width),
                                                                height(height) {
    this->yCoord = yCoord;
    this->xCoord = xCoord;
    this->width = width;
    this->height = height;
}

int Game::Entity::getWidth() const {
    return width;
}

void Game::Entity::setWidth(int width) {
    Entity::width = width;
}

int Game::Entity::getHeight() const {
    return height;
}

void Game::Entity::setHeight(int height) {
    Entity::height = height;
}


int Game::Entity::getXCoord() const {
    return xCoord;
}

void Game::Entity::setXCoord(int xCoord) {
    Entity::xCoord = xCoord;
}

int Game::Entity::getYCoord() const {
    return yCoord;
}

void Game::Entity::setYCoord(int yCoord) {
    Entity::yCoord = yCoord;
}

int Game::Entity::getSpeed() const {
    return speed;
}

void Game::Entity::setSpeed(int speed) {
    Entity::speed = speed;
}

