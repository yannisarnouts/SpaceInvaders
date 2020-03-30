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
    SDL_Rect renderQuad = {this->getXCoord() + 100, this->getYCoord(), getAlienWidth(), getAlienHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLAlien::close() {

}

// TODO: refactor to AbstractAlien
void SDLAlien::moveRight() {
    this->setGoDown(false);
    this->setXCoord(this->getXCoord() + 2);
    if (this->getXCoord() >= this->screenWidth) {
        this->setTurnLeft(true);
        this->setGoDown(true);
    }
}

SDLAlien::SDLAlien(int width, int height, AlienType alienType, int xPos, int yPos, SDL_Renderer *renderer,
                   const std::string &imgPath) : Alien(width, height, alienType, xPos, yPos), renderer(renderer),
                                                 imgPath(imgPath) {
    this->renderer = renderer;
    this->imgPath = imgPath;
    this->screenHeight = height;
    this->screenWidth = width;
    Texture *aTexture = new Texture(renderer);
    texture = aTexture;
    aTexture->loadFromFile(imgPath);
}



