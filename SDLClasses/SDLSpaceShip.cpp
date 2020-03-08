//
// Created by Gebruiker on 8/03/2020.
//

#include "SDLSpaceShip.h"

SDLSpaceShip::SDLSpaceShip() {
    gameView = new GameView();
}

SDLSpaceShip::SDLSpaceShip(int xCoord, int yCoord, int width, int height) : AbstractPlayerShip(xCoord, yCoord, width,
                                                                                               height) {
}

void SDLSpaceShip::Visualize(AbstractPlayerShip abstractPlayerShip) {
    gameView->createTexture("../assets/spaceship.png");
}
