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
    SDLPlayerShip(SDL_Renderer *gRenderer, int shipWidth, int shipHeight, std::string imgPath);
    void Visualize() override;
    void close() override;
    int getXCoord() override;
    int getYCoord() override;
    int getWidth() override;
    int getHeight() override;
    void moveShip();

private:
    SDL_Renderer* gRenderer;
    Texture* texture = NULL;
    std::string imgPath;
    int shipWidth; int shipHeight;
    int screenWidth;
    int xCoord; int yCoord;
    KeyHandler* keyHandler;
};


#endif //PROJECT_SDLPLAYERSHIP_H
