//
// Created by Gebruiker on 12/03/2020.
//

#include <iostream>
#include "SDLAlien.h"

SDLAlien::SDLAlien() {}

void SDLAlien::Visualize() {
    if (this->isTurnLeft()) {
        moveLeft();
    } else {
        moveRight();
    }
    SDL_Rect renderQuad = {this->getXCoord() + 100, this->getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLAlien::close() {

}

// TODO: refactor to AbstractAlien
void SDLAlien::moveRight() {
    this->setGoDown(false);
    this->setXCoord(this->getXCoord() + 2);
    if (this->getXCoord() >= this->SCREEN_WIDTH) {
        this->setTurnLeft(true);
        this->setGoDown(true);
    }
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



