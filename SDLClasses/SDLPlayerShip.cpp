//
// Created by Gebruiker on 8/03/2020.
//

#include <iostream>
#include "SDLPlayerShip.h"
#include "../factory/Texture.h"

SDLPlayerShip::SDLPlayerShip() {
}

SDLPlayerShip::SDLPlayerShip(SDL_Renderer *gRenderer, int width, int height, std::string imgPath) {
    this->shipWidth = width / 5;
    this->shipHeight = height / 5;
    this->xCoord = width/2 - 50;
    this->yCoord = height - (this->shipHeight + 10);
    this->gRenderer = gRenderer;
    this->imgPath = imgPath;
    Texture *ssTexture = new Texture(gRenderer);
    texture = ssTexture;
    texture->loadFromFile(imgPath);
}


void SDLPlayerShip::Visualize() {
    SDL_Rect renderQuad = {xCoord, yCoord, shipWidth, shipHeight};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
    //renderQuad = {0, scrollingOffset - (getHeight()), getWidth(), getHeight()};
    //SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
}

int SDLPlayerShip::getXCoord() {
    return 0;
}

int SDLPlayerShip::getYCoord() {
    return 0;
}

int SDLPlayerShip::getWidth() {
    return 0;
}

int SDLPlayerShip::getHeight() {
    return 0;
}

void SDLPlayerShip::close() {

}
