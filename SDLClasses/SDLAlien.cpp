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

SDL::SDLAlien::SDLAlien(int xCoord, int yCoord, int width, int height, AlienType alienType, SDL_Renderer *renderer) : Alien(xCoord, yCoord, width, height, alienType), renderer(renderer) {
    this->renderer = renderer;
    Texture *aTexture = new Texture(renderer);
    texture = aTexture;
    std::string imgPath;
    if (alienType == AlienType::boss) {
        imgPath = bossPath;
    } else if (alienType == AlienType::michiel) {
        imgPath = michielPath;
    } else if (alienType == AlienType::clifford) {
        imgPath = cliffPath;
    } else if (alienType == AlienType::thomas) {
        imgPath = thomasPath;
    }
    aTexture->loadFromFile(imgPath);
}

SDL::SDLAlien::~SDLAlien() {
    texture->free();
}



