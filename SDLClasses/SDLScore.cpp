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
    this->configReader = new ConfigReader;
}

void SDL::SDLScore::Visualize() {
    std::string score = std::to_string(getPoints());
    this->texture->loadTexture("Score: " + score);
    SDL_Rect renderQuad = {0, 0, configReader->getScreenWidth()/10, configReader->getScreenHeight()/10};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLScore::~SDLScore() {
    texture->free();
}
