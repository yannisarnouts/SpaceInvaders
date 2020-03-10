//
// Created by Gebruiker on 8/03/2020.
//

#include "sdlFactory.h"
#include "../MVC/GameView.h"
#include "../SDLClasses/SDLSpaceShip.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
sdlFactory::sdlFactory() {}

void sdlFactory::init(int wh, int ww) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    } else {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wh, ww, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        } else {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL ){
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            }
            else{
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) ){
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                }
            }
        }
    }
}
AbstractPlayerShip *sdlFactory::createPlayerShip() {
    return new SDLSpaceShip(8,9,5,5, gRenderer);
}

AbstractAlien *sdlFactory::createAlien() {
    return nullptr;
}

AbstractBullet *sdlFactory::createBullet() {
    return nullptr;
}

void sdlFactory::render() {
    SDL_RenderPresent(gRenderer);
}
