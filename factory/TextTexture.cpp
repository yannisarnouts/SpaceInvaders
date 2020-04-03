//
// Created by Gebruiker on 3/04/2020.
//

#include "TextTexture.h"
#include <SDL2/SDL_ttf.h>

TextTexture::TextTexture() {}

TextTexture::TextTexture(SDL_Renderer *renderer) : renderer(renderer) {
    this->renderer = renderer;
}

bool TextTexture::loadTexture(std::string text) {
    bool ret = false;
    SDL_Texture *newTexture = NULL;
    SDL_Surface* tmpSurface; // = TTF_RenderText_Solid(gFont, text.c_str(), { 0, 0, 0 });
    if (tmpSurface == NULL) {
        printf("Unable to load image from %s", text.c_str());
        ret = false;
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
        ret = true;
        if (newTexture == NULL) {
            ret = false;
            printf("could not create texture for %s", text.c_str());
        } else {
            ret = true;
            height = tmpSurface->h;
            width = tmpSurface->w;
        }
        SDL_FreeSurface(tmpSurface);
    }
    return false;
}

void TextTexture::free() {
    SDL_DestroyTexture(this->texture);
    texture = NULL;
    width = 0;
    height = 0;
}