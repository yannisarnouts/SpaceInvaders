//
// Created by Gebruiker on 8/03/2020.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "SDLPlayerShip.h"
#include "../factory/Texture.h"

SDL_Event ev;
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
    moveCar();
    SDL_Rect renderQuad = {xCoord, yCoord, shipWidth, shipHeight};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
    //renderQuad = {0, scrollingOffset - (getHeight()), getWidth(), getHeight()};
    //SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
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

void SDLPlayerShip::moveCar() {
    while (SDL_PollEvent(&ev) != 0) {
        if (ev.type == SDL_KEYDOWN) {
            std::cout << "key down";
        }
    }
}
