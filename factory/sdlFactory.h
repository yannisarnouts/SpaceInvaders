//
// Created by Gebruiker on 8/03/2020.
//

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H


#include "AbstractFactory.h"
#include "../MVC/GameView.h"

class sdlFactory : public AbstractFactory {
public:
    sdlFactory();
    AbstractPlayerShip *createPlayerShip() override;
    AbstractAlien *createAlien() override;
    AbstractBullet *createBullet() override;

    void init(int wh, int ww);
    void render();

private:
    SDL_Window* gWindow = NULL;
    SDL_Renderer* gRenderer = NULL;
};


#endif //PROJECT_SDLFACTORY_H
