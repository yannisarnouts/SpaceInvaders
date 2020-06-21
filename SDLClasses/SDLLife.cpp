//
// Created by Gebruiker on 6/04/2020.
//

#include "SDLLife.h"

SDL::SDLLife::SDLLife() {}

void SDL::SDLLife::Visualize() {
    this->texture->loadTexture("Lifes: " + std::to_string(getLife()));
    SDL_Rect renderQuad = {this->getXCoord() - this->texture->getWidth()*2, 0, this->getWidth(), this->getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLLife::~SDLLife() {
    texture->free();
}

SDL::SDLLife::SDLLife(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer) : Life(xCoord, yCoord,
                                                                                                    width, height),
                                                                                               renderer(renderer) {
    this->renderer = renderer;
    TextTexture* textTexture = new TextTexture(renderer);
    this->texture = textTexture;
}
