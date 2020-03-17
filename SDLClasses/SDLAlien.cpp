//
// Created by Gebruiker on 12/03/2020.
//

#include <iostream>
#include "SDLAlien.h"

SDLAlien::SDLAlien() {}

SDLAlien::SDLAlien(SDL_Renderer *renderer, int width, int height, const std::string &imgPath, AlienType alienType) {
    this->renderer = renderer;
    this->alienWidth = width/15;
    this->alienHeight = height/15;
    this->imgPath = imgPath;
    this->alienType = alienType;
    Texture *aTexture = new Texture(renderer);
    texture = aTexture;
    aTexture->loadFromFile(imgPath);
}
void SDLAlien::Visualize(int xPos, int yPos) {
    SDL_Rect renderQuad = {xPos + 10, yPos, alienWidth, alienHeight};
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



