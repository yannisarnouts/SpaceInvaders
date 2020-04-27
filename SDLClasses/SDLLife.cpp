//
// Created by Gebruiker on 6/04/2020.
//

#include "SDLLife.h"

SDL::SDLLife::SDLLife() {}

SDL::SDLLife::SDLLife(SDL_Renderer *renderer) : renderer(renderer) {
    this->renderer = renderer;
    TextTexture* textTexture = new TextTexture(renderer);
    this->texture = textTexture;
}

void SDL::SDLLife::Visualize() {
    std::string life = std::to_string(getLife());
    this->texture->loadTexture("Lifes: " + life);
    SDL_Rect renderQuad = {SCREEN_WIDTH, 0, 100, 100};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLLife::~SDLLife() {
    texture->free();
}
