//
// Created by Gebruiker on 12/03/2020.
//

#ifndef PROJECT_SDLALIEN_H
#define PROJECT_SDLALIEN_H


#include <SDL2/SDL_render.h>
#include "../model/Alien.h"
#include "../factory/Texture.h"
#include "../model/AlienType.h"

class SDLAlien : public Alien {
public:
    SDLAlien();
    SDLAlien(int xCoord, int yCoord, int width, int height, AlienType alienType, SDL_Renderer *renderer,
             const std::string &imgPath);

    void Visualize() override;
    void moveRight();
    void close() override;


private:
    SDL_Renderer* renderer;
    Texture* texture = NULL;
    std::string imgPath;
    int SCREEN_WIDTH = 950;
};


#endif //PROJECT_SDLALIEN_H
