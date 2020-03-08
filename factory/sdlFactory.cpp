//
// Created by Gebruiker on 8/03/2020.
//

#include "sdlFactory.h"
#include "../MVC/GameView.h"
#include "../SDLClasses/SDLSpaceShip.h"

sdlFactory::sdlFactory() {}

AbstractPlayerShip *sdlFactory::createPlayerShip() {
    return new SDLSpaceShip(8,9,5,5);
}

AbstractAlien *sdlFactory::createAlien() {
    return nullptr;
}

AbstractBullet *sdlFactory::createBullet() {
    return nullptr;
}
