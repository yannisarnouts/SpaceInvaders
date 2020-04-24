//
// Created by Gebruiker on 6/04/2020.
//

#include <SDL2/SDL_timer.h>
#include "SDLTimer.h"

SDL::SDLTimer::SDLTimer() {
    reset();
}

double SDL::SDLTimer::getDeltaTime() {
    return deltaTime;
}

void SDL::SDLTimer::update() {
    // time between reset and current time
    elapsedTicks = SDL_GetTicks() - startTicks;
    // get time in seconds
    deltaTime = elapsedTicks/1000;
    if (deltaTime > getTargetDeltatime()) {
        deltaTime = getTargetDeltatime();
    }
}

void SDL::SDLTimer::reset() {
    startTicks = SDL_GetTicks();
    deltaTime = 0;
    elapsedTicks = 0;
}

SDL::SDLTimer::~SDLTimer() {

}
