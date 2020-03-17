//
// Created by Gebruiker on 8/03/2020.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "SDLPlayerShip.h"
#include "../factory/Texture.h"

SDLPlayerShip::SDLPlayerShip() {
}

SDLPlayerShip::SDLPlayerShip(SDL_Renderer *gRenderer, int width, int height, std::string imgPath) {
    this->screenWidth = width;
    this->shipWidth = width / 7;
    this->shipHeight = height / 7;
    this->xCoord = width / 2 - 50;
    this->yCoord = height - (this->shipHeight + 10);
    this->gRenderer = gRenderer;
    this->imgPath = imgPath;
    Texture *ssTexture = new Texture(gRenderer);
    texture = ssTexture;
    texture->loadFromFile(imgPath);
}


void SDLPlayerShip::Visualize() {
    moveShip();
    SDL_Rect renderQuad = {xCoord, yCoord, shipWidth, shipHeight};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
}

int SDLPlayerShip::getXCoord() {
    return xCoord;
}

int SDLPlayerShip::getYCoord() {
    return yCoord;
}

int SDLPlayerShip::getWidth() {
    return shipWidth;
}

int SDLPlayerShip::getHeight() {
    return shipHeight;
}

void SDLPlayerShip::close() {

}
void SDLPlayerShip::moveShip() {
    int direction = keyHandler->directions();
    if(xCoord >= (this->screenWidth - this->shipWidth)) {
        if (direction == KeyP::LEFT) {
            xCoord = xCoord - 5;
        }
    } else if (xCoord <= 0) {
        if (direction == KeyP::RIGHT) {
            xCoord = xCoord + 5;
        }
    } else {
        if (direction == KeyP::LEFT) {
            xCoord = xCoord - 5;
        } else if (direction == KeyP::RIGHT) {
            xCoord = xCoord + 5;
        }
    }
}
