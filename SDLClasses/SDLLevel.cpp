//
// Created by Gebruiker on 27/04/2020.
//

#include "SDLLevel.h"

SDL::SDLLevel::SDLLevel() {}

SDL::SDLLevel::SDLLevel(SDL_Renderer *renderer) : renderer(renderer) {
    this->renderer = renderer;
    TextTexture *textTexture = new TextTexture(renderer);
    this->texture = textTexture;
    configReader = new ConfigReader();
}

SDL::SDLLevel::~SDLLevel() {
}

void SDL::SDLLevel::Visualize() {
    this->texture->loadTexture("Level: " + std::to_string(getLevel()));
    SDL_Rect renderQuad = {configReader->getScreenWidth()/2, 0, configReader->getScreenWidth()/10, configReader->getScreenHeight()/10};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

