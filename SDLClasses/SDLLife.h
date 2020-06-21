//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_SDLLIFE_H
#define PROJECT_SDLLIFE_H

#include <SDL2/SDL_render.h>
#include "../factory/TextTexture.h"
#include "../model/Life.h"
#include "../controller/ConfigReader.h"

namespace SDL {
class SDLLife: public Game::Life {
    public:
    SDLLife();
    SDLLife(int xCoord, int yCoord, int width, int height, SDL_Renderer *renderer);
    ~SDLLife();
    void Visualize() override ;

    private:
        SDL_Renderer *renderer;
        TextTexture *texture = NULL;
};
}

#endif //PROJECT_SDLLIFE_H
