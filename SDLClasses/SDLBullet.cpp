//
// Created by Gebruiker on 17/03/2020.
//

#include <iostream>
#include "SDLBullet.h"

SDLBullet::SDLBullet() {}

SDLBullet::SDLBullet(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer, const std::string &imgPath)
        : Bullet(xCoord, yCoord, width, height), renderer(renderer), imgPath(imgPath) {
    this->renderer = renderer;
    this->imgPath = imgPath;
    this->screenHeight = height;
    Texture *bTexture = new Texture(renderer);
    texture = bTexture;
    bTexture->loadFromFile(this->imgPath);
}

void SDLBullet::Visualize() {
    shootBullet();
    SDL_Rect renderQuad = {getXCoord(), getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
//    SDL_RenderClear(renderer);
}

void SDLBullet::close() {
    this->texture->free();
}
