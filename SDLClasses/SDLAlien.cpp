//
// Created by Gebruiker on 12/03/2020.
//

#include "SDLAlien.h"

SDLAlien::SDLAlien() {}

SDLAlien::SDLAlien(SDL_Renderer *renderer, int width, int height, const std::string &imgPath, AlienType alienType) {
    this->renderer = renderer;
    this->alienWidth = width/5;
    this->alienHeight = height/5;
    this->imgPath = imgPath;
    this->alienType = alienType;
    Texture *aTexture = new Texture(renderer);
    aTexture->loadFromFile(imgPath);
}
void SDLAlien::Visualize() {
    SDL_Rect renderQuad = {0, 0, alienWidth, alienHeight};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLAlien::close() {

}

int SDLAlien::getXPos() {
    return 0;
}

int SDLAlien::getYPos() {
    return 0;
}



