//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_SDLLIFE_H
#define PROJECT_SDLLIFE_H

#include <SDL2/SDL_render.h>
#include "../factory/TextTexture.h"
#include "../model/Life.h"

namespace SDL {
class SDLLife: public Game::Life {
    public:
        SDLLife();
        SDLLife(SDL_Renderer *renderer);
    virtual ~SDLLife();
    void Visualize() override ;

    private:
        SDL_Renderer *renderer;
        TextTexture *texture = NULL;
        int SCREEN_WIDTH = 950;
};
}

#endif //PROJECT_SDLLIFE_H
