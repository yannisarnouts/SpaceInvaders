//
// Created by Gebruiker on 3/04/2020.
//

#include "SDLScore.h"
#include "../factory/TextTexture.h"

void SDL::SDLScore::Visualize() {
    std::string score = std::to_string(getPoints());
    this->texture->loadTexture("Score: " + score);
    SDL_Rect renderQuad = {0, 0, this->getWidth(), this->getHeight()};
    SDL_RenderCopy(renderer, texture->getTexture(), NULL, &renderQuad);
}

SDL::SDLScore::~SDLScore() {
    texture->free();
}

SDL::SDLScore::SDLScore(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer) : Score(xCoord, yCoord,
                                                                                                       width, height),
                                                                                                 renderer(renderer) {
    this->renderer = renderer;
    TextTexture* textTexture = new TextTexture(renderer);
    this->texture = textTexture;
}
