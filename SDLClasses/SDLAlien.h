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
    SDLAlien(SDL_Renderer *renderer, int width, int height, const std::string &imgPath, AlienType alienType, int xPos, int yPos);
    void Visualize() override;
    void moveLeft() override;
    void moveRight() override;
    void close() override;
    int getXPos() override;
    int getYPos() override;
    void setYCoord(int yCoord) override ;
    int getAlienHeight() override ;
    bool isGoDown() override;
    void setGoDown(bool goDown) override ;
    bool isTurnLeft() override ;


private:
    SDL_Renderer* renderer;
    Texture* texture = NULL;
    int alienWidth; int alienHeight;
    int xCoord; int yCoord;
    std::string imgPath;
    AlienType alienType;
    int screenWidth; int screenHeight;
    bool turnLeft = true; bool goDown = false;
};


#endif //PROJECT_SDLALIEN_H
