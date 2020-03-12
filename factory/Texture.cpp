//
// Created by Gebruiker on 10/03/2020.
//

#include <SDL2/SDL_image.h>
#include <cstdio>
#include <iostream>
#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

SDL_Texture *Texture::getTexture() const {
    return texture;
}

bool Texture::loadFromFile(std::string path) {
    bool ret = false;
    SDL_Texture* newTexture = NULL;
    SDL_Surface* tmpSurface = IMG_Load(path.c_str());
    if ( tmpSurface == NULL ){
        printf("Unable to load image from %s", path.c_str());
        ret = false;
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
        ret = true;
        if (newTexture == NULL) {
            ret = false;
            printf("could not create texture for %s", path.c_str());
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

