//
// Created by Gebruiker on 4/04/2020.
//

#include "SDLAlienBullet.h"

SDL::SDLAlienBullet::SDLAlienBullet() {}

SDL::SDLAlienBullet::SDLAlienBullet(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->imgPath = imgPath;
    Texture *bTexture = new Texture(renderer);
    texture = bTexture;
    setWidth(width);
    setHeight(height);
    bTexture->loadFromFile(this->imgPath);
}

void SDL::SDLAlienBullet::Visualize() {
    SDL_Rect renderQuad = {getXCoord(), getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLAlienBullet::~SDLAlienBullet() {
    texture->free();
}
