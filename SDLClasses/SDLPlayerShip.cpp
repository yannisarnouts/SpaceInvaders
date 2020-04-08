//
// Created by Gebruiker on 8/03/2020.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "SDLPlayerShip.h"
#include "../factory/Texture.h"

SDL::SDLPlayerShip::SDLPlayerShip() {
}
SDL::SDLPlayerShip::SDLPlayerShip(int xCoord, int yCoord, int width, int height, SDL_Renderer *gRenderer) : PlayerShip(xCoord, yCoord, width, height),
                                                           gRenderer(gRenderer) {
    this->gRenderer = gRenderer;
    Texture *ssTexture = new Texture(gRenderer);
    texture = ssTexture;
    texture->loadFromFile(shipPath);
}

void SDL::SDLPlayerShip::Visualize() {
    SDL_Rect renderQuad = {getXCoord(), getYCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
}

void SDL::SDLPlayerShip::close() {

}