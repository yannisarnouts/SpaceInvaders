//
// Created by Gebruiker on 7/04/2020.
//

#include "SDLBonus.h"

SDL::SDLBonus::SDLBonus() {}

void SDL::SDLBonus::Visualize() {
    printf("%d ", getXCoord());
    SDL_Rect renderQuad = {getXCoord(), getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDL::SDLBonus::close() {
}

SDL::SDLBonus::SDLBonus(int xCoord, int yCoord, int width, int height, Game::BonusType bonusType,
                        SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->imgPath = imgPath;
    this->setXCoord(xCoord);
    this->setYCoord(yCoord);
    this->setWidth(width); this->setHeight(height);
    Texture *aTexture = new Texture(renderer);
    texture = aTexture;
    aTexture->loadFromFile(imgPath);
}
