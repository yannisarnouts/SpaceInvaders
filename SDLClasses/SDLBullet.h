//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_SDLBULLET_H
#define PROJECT_SDLBULLET_H


#include <SDL2/SDL_render.h>
#include "../model/Bullet.h"
#include "../factory/Texture.h"

class SDLBullet : public Bullet {
public:
    SDLBullet();
    SDLBullet(SDL_Renderer *renderer, int width, int height, const std::string &imgPath, int xCoord, int yCoord);
    void close() override;
    int getXCoord() override;
    void setXCoord(int x) override;
    int getYCoord() override;
    void setYCoord(int yCoord) override;
    int getHeight() override;
    void setHeight(int height);
    void shootBullet() override ;
    void Visualize() override ;

private:
    SDL_Renderer* renderer;
    Texture *texture = NULL;
    int width; int height;
    int xCoord; int yCoord;
    std::string imgPath;
    int screenHeight;

};


#endif //PROJECT_SDLBULLET_H
