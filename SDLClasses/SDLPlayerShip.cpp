//
// Created by Gebruiker on 8/03/2020.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "SDLPlayerShip.h"
#include "../factory/Texture.h"

SDLPlayerShip::SDLPlayerShip() {
}
SDLPlayerShip::SDLPlayerShip(int xCoord, int yCoord, int width, int height, SDL_Renderer *gRenderer,
                             const std::string &imgPath) : PlayerShip(xCoord, yCoord, width, height),
                                                           gRenderer(gRenderer), imgPath(imgPath) {
    this->gRenderer = gRenderer;
    this->imgPath = imgPath;
    Texture *ssTexture = new Texture(gRenderer);
    texture = ssTexture;
    texture->loadFromFile(imgPath);
}

void SDLPlayerShip::Visualize() {
    moveShip();
    SDL_Rect renderQuad = {getXCoord(), getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLPlayerShip::close() {

}

void SDLPlayerShip::moveShip() {
    int direction = keyHandler->directions();
    if (getXCoord() >= (this->SCREEN_WIDTH + this->getWidth())) {
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