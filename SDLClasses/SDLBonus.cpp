//
// Created by Gebruiker on 7/04/2020.
//

#include "SDLBonus.h"

SDL::SDLBonus::SDLBonus() {}

void SDL::SDLBonus::Visualize() {
    SDL_Rect renderQuad = {getXCoord(), getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLBonus::SDLBonus(int xCoord, int yCoord, int width, int height, Game::BonusType bonusType,
                        SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->setXCoord(xCoord);
    this->setYCoord(yCoord);
    this->setWidth(width); this->setHeight(height);
    this->setBonusType(bonusType);
    Texture *aTexture = new Texture(renderer);
    texture = aTexture;
    aTexture->loadFromFile(imgPath);
}

SDL::SDLBonus::~SDLBonus() {
    texture->free();
}
