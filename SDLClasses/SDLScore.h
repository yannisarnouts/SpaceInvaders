//
// Created by Gebruiker on 3/04/2020.
//

#ifndef PROJECT_SDLSCORE_H
#define PROJECT_SDLSCORE_H

#include <SDL2/SDL_render.h>
#include "../model/Score.h"
#include "../factory/TextTexture.h"
#include "../controller/ConfigReader.h"

namespace SDL {
    class SDLScore: public Game::Score {
    public:
        SDLScore(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer);
        ~SDLScore();
        void Visualize() override ;

    private:
        SDL_Renderer *renderer;
        TextTexture *texture = NULL;
    };
}

#endif //PROJECT_SDLSCORE_H
