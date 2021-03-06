//
// Created by Gebruiker on 12/03/2020.
//

#include "SDLBackground.h"
#include "../factory/Texture.h"


SDL::SDLBackground::SDLBackground(SDL_Renderer *renderer, int screenW, int screenH) {
    this->screenW = screenW;
    this->screenH = screenH;
    this->renderer = renderer;
    Texture* aTexture = new Texture(renderer);
    this->texture = aTexture;
    texture->loadFromFile(this->bgPath);
}

void SDL::SDLBackground::Visualize() {
    SDL_RenderClear(renderer);
    SDL_Rect renderQuad = {0, 0,screenW, screenH};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLBackground::~SDLBackground() {
    texture->free();
}
