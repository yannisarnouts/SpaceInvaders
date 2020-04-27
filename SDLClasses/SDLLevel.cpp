//
// Created by Gebruiker on 27/04/2020.
//

#include "SDLLevel.h"

SDL::SDLLevel::SDLLevel() {}

SDL::SDLLevel::SDLLevel(SDL_Renderer *renderer) : renderer(renderer) {
    this->renderer = renderer;
    TextTexture *textTexture = new TextTexture(renderer);
    this->texture = textTexture;
}

SDL::SDLLevel::~SDLLevel() {
}

void SDL::SDLLevel::Visualize() {
    std::string level = std::to_string(getLevel());
    this->texture->loadTexture("Level: " + level);
    SDL_Rect renderQuad = {SCREEN_WIDTH/2, 0, 100, 100};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

