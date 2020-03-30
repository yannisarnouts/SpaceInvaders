//
// Created by Gebruiker on 8/03/2020.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "SDLPlayerShip.h"
#include "../factory/Texture.h"

SDLPlayerShip::SDLPlayerShip() {
}

SDLPlayerShip::SDLPlayerShip(int shipWidth, int shipHeight, SDL_Renderer *gRenderer, const std::string &imgPath)
        : PlayerShip(shipWidth, shipHeight), gRenderer(gRenderer), imgPath(imgPath) {
    this->screenWidth = shipWidth;
    this->gRenderer = gRenderer;
    this->imgPath = imgPath;
    std::cout << this->getShipHeight();
    Texture *ssTexture = new Texture(gRenderer);
    texture = ssTexture;
    texture->loadFromFile(imgPath);
}

void SDLPlayerShip::Visualize() {
    moveShip();
    SDL_Rect renderQuad = {getXCoord(), getYCoord(), getShipWidth(), getShipHeight()};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLPlayerShip::close() {

}

void SDLPlayerShip::moveShip() {
    int direction = keyHandler->directions();
    if (getXCoord() >= (this->screenWidth + this->getShipWidth())) {
        if (direction == KeyP::LEFT) {
            setXCoord(getXCoord()- 5);
        }
    } else if (getXCoord() <= 0) {
        if (direction == KeyP::RIGHT) {
            setXCoord(getXCoord() + 5);
        }
    } else {
        if (direction == KeyP::LEFT) {
            setXCoord(getXCoord()- 5);
        } else if (direction == KeyP::RIGHT) {
            setXCoord(getXCoord() + 5);
        }
    }
}
