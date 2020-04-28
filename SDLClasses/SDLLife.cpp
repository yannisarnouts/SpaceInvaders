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
    configReader = new ConfigReader();
    this->texture->loadTexture("Lifes: " + std::to_string(getLife()));
    SDL_Rect renderQuad = {configReader->getScreenWidth() - 100, 0, 100, 100};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLLife::~SDLLife() {
    delete configReader;
    texture->free();
}
