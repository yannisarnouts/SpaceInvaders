//
// Created by Gebruiker on 3/04/2020.
//

#include <SDL2/SDL_rect.h>
#include "SDLScore.h"
#include "../factory/TextTexture.h"

SDL::SDLScore::SDLScore() {}

SDL::SDLScore::SDLScore(SDL_Renderer *renderer) : renderer(renderer) {
    this->renderer = renderer;
    TextTexture* textTexture = new TextTexture(renderer);
    this->texture = textTexture;
}

void SDL::SDLScore::Visualize() {
    this->texture->loadTexture("Score: " + std::to_string(getPoints()));
    SDL_Rect renderQuad = {0, 0, 100, 100};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLScore::~SDLScore() {
    texture->free();
}
