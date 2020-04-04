//
// Created by Gebruiker on 4/04/2020.
//

#ifndef PROJECT_SDLALIENBULLET_H
#define PROJECT_SDLALIENBULLET_H

#include <SDL2/SDL_render.h>
#include "../factory/Texture.h"
#include "../model/AlienBullet.h"

namespace SDL {
class SDLAlienBullet : public Game::AlienBullet {
public:
    SDLAlienBullet();
    SDLAlienBullet(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer, const std::string &imgPath);

    void Visualize() override;

    void close() override;

private:
    SDL_Renderer *renderer;
    Texture *texture = NULL;
    std::string imgPath;
};
}

#endif //PROJECT_SDLALIENBULLET_H