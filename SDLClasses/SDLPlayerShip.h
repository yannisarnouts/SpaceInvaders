//
// Created by Gebruiker on 8/03/2020.
//

#ifndef PROJECT_SDLPLAYERSHIP_H
#define PROJECT_SDLPLAYERSHIP_H


#include "../model/PlayerShip.h"
#include "../factory/Texture.h"
#include "../controller/KeyHandler.h"

class SDLPlayerShip : public PlayerShip {
public:
    SDLPlayerShip();
    SDLPlayerShip(int shipWidth, int shipHeight, SDL_Renderer *gRenderer, const std::string &imgPath);
    void Visualize() override;
    void close() override;
    void moveShip() override;

private:
    SDL_Renderer* gRenderer;
    Texture* texture = NULL;
    std::string imgPath;
    int screenWidth;
    KeyHandler* keyHandler;
};


#endif //PROJECT_SDLPLAYERSHIP_H
