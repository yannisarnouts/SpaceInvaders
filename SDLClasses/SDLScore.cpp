//
// Created by Gebruiker on 3/04/2020.
//

#include "SDLScore.h"
#include "../factory/TextTexture.h"

SDL::SDLScore::SDLScore() {}

SDL::SDLScore::SDLScore(SDL_Renderer *renderer) : renderer(renderer) {
    this->renderer = renderer;
    TextTexture* textTexture = new TextTexture(renderer);
    this->texture = textTexture;
}

void SDL::SDLScore::Visualize() {
    std::string score = std::to_string(getPoints());
    this->texture->loadTexture("Score: " + score);
    SDL_Rect renderQuad = {0, 0, 100, 100};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLScore::~SDLScore() {
    texture->free();
}
