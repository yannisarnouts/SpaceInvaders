//
// Created by Gebruiker on 3/04/2020.
//

#ifndef PROJECT_SDLSCORE_H
#define PROJECT_SDLSCORE_H

#include <SDL2/SDL_render.h>
#include "../model/Score.h"
#include "../factory/Texture.h"

namespace SDL {
//    : public Game::Score
    class SDLScore {
    public:
        SDLScore();

        SDLScore(SDL_Renderer *renderer);

        void Visualize();
        void close();

    private:
        SDL_Renderer *renderer;
        Texture *texture = NULL;
    };
}

#endif //PROJECT_SDLSCORE_H
