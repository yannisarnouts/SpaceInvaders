//
// Created by Gebruiker on 12/03/2020.
//

#include <iostream>
#include "SDLAlien.h"

SDLAlien::SDLAlien() {}

void SDLAlien::Visualize() {
    move();
    SDL_Rect renderQuad = {this->getXCoord() + 100, this->getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLAlien::close() {

}

SDLAlien::SDLAlien(int xCoord, int yCoord, int width, int height, AlienType alienType, SDL_Renderer *renderer,
                   const std::string &imgPath) : Alien(xCoord, yCoord, width, height, alienType), renderer(renderer),
                                                 imgPath(imgPath) {
    this->renderer = renderer;
    this->imgPath = imgPath;
    Texture *aTexture = new Texture(renderer);
    texture = aTexture;
    aTexture->loadFromFile(imgPath);
}

bool SDLAlien::hitBoundary() {
    if (getXCoord() <= 0) {
        setXCoord(0);
        return true;
    } else if (getXCoord() >= SCREEN_WIDTH) {
        setXCoord(SCREEN_WIDTH);
        return true;
    } else {
        return false;
    }
}



