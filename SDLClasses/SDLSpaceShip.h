//
// Created by Gebruiker on 8/03/2020.
//

#ifndef PROJECT_SDLSPACESHIP_H
#define PROJECT_SDLSPACESHIP_H


#include "../model/AbstractPlayerShip.h"
#include "../MVC/GameView.h"
#include "../factory/Texture.h"

class SDLSpaceShip : public AbstractPlayerShip {
public:
    SDLSpaceShip();

    SDLSpaceShip(SDL_Renderer *gRenderer, int width, int height, std::string imgPath);

    void Visualize(AbstractPlayerShip abstractPlayerShip) override;

private:
    SDL_Renderer* gRenderer;
    Texture* texture = NULL;
    std::string imgPath;
};


#endif //PROJECT_SDLSPACESHIP_H
