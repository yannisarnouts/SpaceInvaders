//
// Created by Gebruiker on 14/03/2020.
//

#include <SDL2/SDL_events.h>
#include <iostream>
#include "KeyHandler.h"

Game::KeyHandler::KeyHandler() {
}

KeyP Game::KeyHandler::directions() {
    // get snapshot of current state keyboard: https://wiki.libsdl.org/SDL_GetKeyboardState
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] ){
        return KeyP::LEFT;
    } else if (currentKeyStates[ SDL_SCANCODE_RIGHT ]) {
        return KeyP::RIGHT;
    } else if (currentKeyStates [ SDL_SCANCODE_UP ]) {
        return KeyP::UP;
    } else {
        return KeyP::NONE;
    }
}

