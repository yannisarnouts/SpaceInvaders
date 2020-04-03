//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_SDLBULLET_H
#define PROJECT_SDLBULLET_H


#include <SDL2/SDL_render.h>
#include "../model/Bullet.h"
#include "../factory/Texture.h"

namespace SDL {
    class SDLBullet : public Game::Bullet {
    public:
        SDLBullet();

        SDLBullet(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer, const std::string &imgPath);

        void close() override;

        void Visualize() override;

    private:
        SDL_Renderer *renderer;
        Texture *texture = NULL;
        std::string imgPath;
        int screenHeight;

    };
}

#endif //PROJECT_SDLBULLET_H
