//
// Created by Gebruiker on 12/03/2020.
//

#include <iostream>
#include "SDLAlien.h"

SDLAlien::SDLAlien() {}

SDLAlien::SDLAlien(SDL_Renderer *renderer, int width, int height, const std::string &imgPath, AlienType alienType,
                   int xPos, int yPos) {
    this->renderer = renderer;
    this->alienWidth = width / 15;
    this->alienHeight = height / 20;
    this->imgPath = imgPath;
    this->alienType = alienType;
    this->yCoord = yPos;
    this->xCoord = xPos;
    this->screenHeight = height;
    this->screenWidth = width;
    Texture *aTexture = new Texture(renderer);
    texture = aTexture;
    aTexture->loadFromFile(imgPath);
}

void SDLAlien::Visualize() {
    if (this->isTurnLeft()) {
        moveLeft();
    } else {
        moveRight();
    }
    SDL_Rect renderQuad = {this->xCoord + 100, this->yCoord, alienWidth, alienHeight};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLAlien::close() {

}

int SDLAlien::getXPos() {
    return xCoord;
}

int SDLAlien::getYPos() {
    return yCoord;
}

bool SDLAlien::isGoDown() {
    return goDown;
}

void SDLAlien::setGoDown(bool goDown) {
    SDLAlien::goDown = goDown;
}

void SDLAlien::setYCoord(int yCoord) {
    SDLAlien::yCoord = yCoord;
}

int SDLAlien::getAlienHeight() {
    return alienHeight;
}

bool SDLAlien::isTurnLeft() {
    return turnLeft;
}

void SDLAlien::moveLeft() {
    this->goDown = false;
    if (this->turnLeft) {
        this->xCoord -= 2;
    }
    if (this->getXPos() <= 0 - this->alienWidth) {
        this->turnLeft = false;
        this->goDown = true;
    }
}

void SDLAlien::moveRight() {
    this->goDown = false;
    this->xCoord += 2;
    if (this->getXPos() >= this->screenWidth) {
        this->turnLeft = true;
        this->goDown = true;
    }
}



