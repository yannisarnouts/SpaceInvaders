//
// Created by Gebruiker on 8/03/2020.
//

#ifndef PROJECT_SDLSPACESHIP_H
#define PROJECT_SDLSPACESHIP_H


#include "../model/AbstractPlayerShip.h"
#include "../MVC/GameView.h"

class SDLSpaceShip : public AbstractPlayerShip {
public:
    SDLSpaceShip();
    SDLSpaceShip(int xCoord, int yCoord, int width, int height);

    void Visualize(AbstractPlayerShip abstractPlayerShip) override;

private:
    GameView* gameView;
};


#endif //PROJECT_SDLSPACESHIP_H
