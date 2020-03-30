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
    SDLAlien(int width, int height, AlienType alienType, int xPos, int yPos, SDL_Renderer *renderer,
             const std::string &imgPath);
    void Visualize() override;
    void moveRight() override;
    void close() override;


private:
    SDL_Renderer* renderer;
    Texture* texture = NULL;
    std::string imgPath;
    int screenWidth; int screenHeight;
};


#endif //PROJECT_SDLALIEN_H
