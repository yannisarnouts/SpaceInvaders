//
// Created by Gebruiker on 17/03/2020.
//

#include "SDLBullet.h"

void SDLBullet::Visualize(int xCoord, int yCoord) {
    SDL_Rect renderQuad = {xCoord, yCoord, this->width, this->height};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLBullet::close() {

}

int SDLBullet::getXCoord() {
    return 0;
}

int SDLBullet::getYCoord() {
    return 0;
}

SDLBullet::SDLBullet() {}

SDLBullet::SDLBullet(SDL_Renderer *renderer, int width, int height,const std::string &imgPath, int xCoord, int yCoord) {
    this->renderer = renderer;
    this->width = width/30;
    this->height = height/30;
    this->imgPath = imgPath;
    this->xCoord = xCoord; this->yCoord = yCoord;
    Texture *bTexture = new Texture(renderer);
    texture = bTexture;
    bTexture->loadFromFile(this->imgPath);
}
