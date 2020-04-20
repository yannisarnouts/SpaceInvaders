//
// Created by Gebruiker on 12/03/2020.
//

#include <iostream>
#include "SDLAlien.h"

SDL::SDLAlien::SDLAlien() {}

void SDL::SDLAlien::Visualize() {
    SDL_Rect renderQuad = {this->getXCoord() + 100, this->getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDL::SDLAlien::close() {

}

SDL::SDLAlien::SDLAlien(int xCoord, int yCoord, int width, int height, AlienType alienType, SDL_Renderer *renderer,
                   const std::string &imgPath) : Alien(xCoord, yCoord, width, height, alienType), renderer(renderer),
                                                 imgPath(imgPath) {
    this->renderer = renderer;
    this->imgPath = imgPath;
    Texture *aTexture = new Texture(renderer);
    texture = aTexture;
    aTexture->loadFromFile(imgPath);
}



