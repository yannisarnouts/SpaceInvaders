//
// Created by Gebruiker on 27/04/2020.
//

#include "SDLLevel.h"

SDL::SDLLevel::SDLLevel() {}

SDL::SDLLevel::~SDLLevel() {
}

void SDL::SDLLevel::Visualize() {
    this->texture->loadTexture("Level: " + std::to_string(getLevel()));
    SDL_Rect renderQuad = {this->getXCoord(), 0, this->getWidth(), this->getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLLevel::SDLLevel(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer) : Level(xCoord, yCoord,
                                                                                                       width, height),
                                                                                                 renderer(renderer) {
    this->renderer = renderer;
    TextTexture *textTexture = new TextTexture(renderer);
    this->texture = textTexture;
}

