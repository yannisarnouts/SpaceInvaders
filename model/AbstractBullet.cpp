//
// Created by Gebruiker on 7/03/2020.
//

#include "AbstractBullet.h"

AbstractBullet::AbstractBullet() {}

AbstractBullet::AbstractBullet(int xCoord, int yCoord, int width, int height, int speed) : Entity(xCoord, yCoord, width,
                                                                                                  height),
                                                                                           speed(speed) {}

int AbstractBullet::getSpeed() const {
    return speed;
}

void AbstractBullet::setSpeed(int speed) {
    AbstractBullet::speed = speed;
}

void AbstractBullet::Visualize(AbstractBullet bullet) {

}
