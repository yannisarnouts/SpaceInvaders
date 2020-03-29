//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "SDLBullet.h"

void SDLBullet::Visualize() {
    shootBullet();
    SDL_Rect renderQuad = {this->xCoord, this->yCoord, this->width, this->height};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
//    SDL_RenderClear(renderer);
}

void SDLBullet::close() {
    this->texture->free();
}

int SDLBullet::getXCoord() {
    return xCoord;
}

int SDLBullet::getYCoord() {
    return yCoord;
}

SDLBullet::SDLBullet() {}

SDLBullet::SDLBullet(SDL_Renderer *renderer, int width, int height, const std::string &imgPath, int xCoord,
                     int yCoord) {
    this->renderer = renderer;
    this->width = width / 30;
    this->height = height / 30;
    this->imgPath = imgPath;
    this->xCoord = xCoord;
    this->yCoord = yCoord;
    this->screenHeight = height;
    Texture *bTexture = new Texture(renderer);
    texture = bTexture;
    bTexture->loadFromFile(this->imgPath);
}

void SDLBullet::setYCoord(int yCoord) {
    SDLBullet::yCoord = yCoord;
}

void SDLBullet::setHeight(int height) {
    SDLBullet::height = height;
}

int SDLBullet::getHeight() {
    return height;
}

void SDLBullet::shootBullet() {
    this->yCoord = this->yCoord - 10;
}

void SDLBullet::setXCoord(int x) {
    SDLBullet::xCoord = x;
}
