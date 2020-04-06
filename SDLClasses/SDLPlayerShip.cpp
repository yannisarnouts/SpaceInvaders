//
// Created by Gebruiker on 8/03/2020.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "SDLPlayerShip.h"
#include "../factory/Texture.h"

SDL::SDLPlayerShip::SDLPlayerShip() {
}
SDL::SDLPlayerShip::SDLPlayerShip(int xCoord, int yCoord, int width, int height, SDL_Renderer *gRenderer,
                             const std::string &imgPath) : PlayerShip(xCoord, yCoord, width, height),
                                                           gRenderer(gRenderer), imgPath(imgPath) {
    this->gRenderer = gRenderer;
    this->imgPath = imgPath;
    Texture *ssTexture = new Texture(gRenderer);
    texture = ssTexture;
    texture->loadFromFile(imgPath);
}

void SDL::SDLPlayerShip::Visualize() {
    SDL_Rect renderQuad = {getXCoord(), getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
}

void SDL::SDLPlayerShip::close() {

}