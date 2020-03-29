//
// Created by Gebruiker on 8/03/2020.
//

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H


#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include "AbstractFactory.h"
#include "../model/AlienType.h"
#include "../controller/KeyHandler.h"

class SDLFactory : public AbstractFactory {
public:
    SDLFactory();
    void init() override;
    PlayerShip *createPlayerShip(std::string path) override;
    Alien *createAlien(AlienType alienType, std::string path, int xPos, int yPos) override;
    Bullet *createBullet(std::string path, int xCoord, int yCoord) override;
    Background *createBackground(std::string path) override;
    bool pollEvents() override;
    void render() override;
    void close() override;

private:
    SDL_Window* gWindow = NULL;
    SDL_Renderer* gRenderer = NULL;
    int SCREEN_HEIGHT = 1280;
    int SCREEN_WIDTH = 950;
};


#endif //PROJECT_SDLFACTORY_H
