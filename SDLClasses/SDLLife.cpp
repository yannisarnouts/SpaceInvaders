//
// Created by Gebruiker on 6/04/2020.
//

#include "SDLLife.h"

SDL::SDLLife::SDLLife() {}

SDL::SDLLife::SDLLife(SDL_Renderer *renderer) : renderer(renderer) {
    this->renderer = renderer;
    TextTexture* textTexture = new TextTexture(renderer);
    this->texture = textTexture;
    configReader = new ConfigReader();
}

void SDL::SDLLife::Visualize() {
    this->texture->loadTexture("Lifes: " + std::to_string(getLife()));
    SDL_Rect renderQuad = {configReader->getScreenWidth() - this->texture->getWidth()*2, 0, configReader->getScreenWidth()/10, configReader->getScreenHeight()/10};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLLife::~SDLLife() {
    delete configReader;
    texture->free();
}
