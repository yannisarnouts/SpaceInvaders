//
// Created by Gebruiker on 12/03/2020.
//

#ifndef PROJECT_SDLBACKGROUND_H
#define PROJECT_SDLBACKGROUND_H


#include <SDL2/SDL_render.h>
#include <string>
#include "../model/Background.h"
#include "../factory/Texture.h"

class SDLBackground : public Background{
public:
    SDLBackground(SDL_Renderer *renderer, int screenW, int screenH, const std::string &imgPath);

    void Visualize() override;

    void close() override;

private:
    SDL_Renderer* renderer;
    Texture* texture = NULL;
    int screenW;
    int screenH;
    std::string imgPath;
};


#endif //PROJECT_SDLBACKGROUND_H
