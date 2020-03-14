//
// Created by Gebruiker on 14/03/2020.
//

#include <SDL2/SDL_events.h>
#include <iostream>
#include "KeyHandler.h"

KeyHandler::KeyHandler() {
}

KeyP KeyHandler::directions() {
    SDL_Event event;
    SDL_PollEvent(&event);
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] ){
        return KeyP::LEFT;
    } else if (currentKeyStates[ SDL_SCANCODE_RIGHT ]) {
        return KeyP::RIGHT;
    } else {
        return KeyP::NONE;
    }
}

