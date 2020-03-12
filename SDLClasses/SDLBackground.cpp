//
// Created by Gebruiker on 12/03/2020.
//

#include "SDLBackground.h"
#include "../factory/Texture.h"


SDLBackground::SDLBackground(SDL_Renderer *renderer, int screenW, int screenH,
                             const std::string &imgPath) {
    this->screenW = screenW;
    this->screenH = screenH;
    this->imgPath = imgPath;
    this->renderer = renderer;
    Texture* aTexture = new Texture(renderer);
    this->texture = aTexture;
    texture->loadFromFile(imgPath);
}

void SDLBackground::Visualize() {
    SDL_RenderClear(renderer);
    SDL_Rect renderQuad = {0, 0,screenW, screenH};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

void SDLBackground::close() {
    Background::close();
}
