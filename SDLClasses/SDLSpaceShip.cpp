//
// Created by Gebruiker on 8/03/2020.
//

#include "SDLSpaceShip.h"
#include "../factory/Texture.h"

SDLSpaceShip::SDLSpaceShip() {
}

SDLSpaceShip::SDLSpaceShip(SDL_Renderer *gRenderer, int width, int height, std::string imgPath) {
    this->gRenderer = gRenderer;
    this->imgPath = imgPath;
    Texture *ssTexture = new Texture(gRenderer);
    texture = ssTexture;
}
void SDLSpaceShip::Visualize(AbstractPlayerShip abstractPlayerShip) {
    SDL_Rect renderQuad = {getXCoord(), getXCoord(), getWidth(), getHeight()};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
    //renderQuad = {0, scrollingOffset - (getHeight()), getWidth(), getHeight()};
    SDL_RenderCopy(gRenderer, texture->getTexture(), NULL, &renderQuad);
    texture->loadFromFile(imgPath);
}
