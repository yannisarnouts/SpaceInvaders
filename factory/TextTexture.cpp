//
// Created by Gebruiker on 3/04/2020.
//

#include "TextTexture.h"
#include <SDL2/SDL_ttf.h>

TextTexture::TextTexture() {}

TextTexture::TextTexture(SDL_Renderer *renderer) : renderer(renderer) {
    this->renderer = renderer;
    gFont = TTF_OpenFont("../assets/Arial.ttf", 20);
}

bool TextTexture::loadTexture(std::string text) {
    bool ret;
    SDL_Texture *newTexture = NULL;
    if (gFont == NULL) {
        printf("failed to load font, error:  %s", gFont);
    }
    SDL_Color color = {255, 255, 255};
    SDL_Surface *tmpSurface = TTF_RenderText_Solid(gFont, text.c_str(), color);
    if (tmpSurface == NULL) {
        printf("Unable to load %s", text.c_str());
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
    texture = newTexture;
    return ret;
}

void TextTexture::free() {
    SDL_DestroyTexture(this->texture);
    texture = NULL;
    width = 0;
    height = 0;
}

SDL_Texture *TextTexture::getTexture() const {
    return texture;
}

int TextTexture::getHeight() const {
    return height;
}

int TextTexture::getWidth() const {
    return width;
}
