//
// Created by Gebruiker on 27/04/2020.
//

#ifndef SPACEINVADERS_SDLLEVEL_H
#define SPACEINVADERS_SDLLEVEL_H

#include <SDL2/SDL_render.h>
#include "../model/Level.h"
#include "../factory/TextTexture.h"

namespace SDL {
class SDLLevel: public Game::Level {
public:
    SDLLevel();
    SDLLevel(SDL_Renderer *renderer);
    ~SDLLevel();
    void Visualize() override;

private:
    SDL_Renderer *renderer;
    TextTexture *texture = NULL;
    int SCREEN_WIDTH = 950;
};
}

#endif //SPACEINVADERS_SDLLEVEL_H