//
// Created by Gebruiker on 17/03/2020.
//

#include "Bullet.h"

Bullet::Bullet() {}

Bullet::Bullet(int width, int height, int xCoord, int yCoord) : width(width), height(height), xCoord(xCoord),
                                                                yCoord(yCoord) {
    this->width = width / 30;
    this->height = height / 30;
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

int Bullet::getWidth() const {
    return width;
}

int Bullet::getHeight() const {
    return height;
}

int Bullet::getXCoord() const {
    return xCoord;
}

int Bullet::getYCoord() const {
    return yCoord;
}
void Bullet::shootBullet() {
    this->yCoord = this->yCoord - 10;
}

void Bullet::setXCoord(int xCoord) {
    Bullet::xCoord = xCoord;
}
