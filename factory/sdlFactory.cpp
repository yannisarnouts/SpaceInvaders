//
// Created by Gebruiker on 8/03/2020.
//

#include "sdlFactory.h"
#include "../SDLClasses/SDLPlayerShip.h"
#include "../SDLClasses/SDLBackground.h"
#include "../SDLClasses/SDLAlien.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

sdlFactory::sdlFactory() {}

void sdlFactory::init(int wh, int ww) {
    SCREEN_WIDTH = ww;
    SCREEN_HEIGHT = wh;
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

void sdlFactory::render() {
    //update the screen
    SDL_RenderPresent(gRenderer);
}

PlayerShip *sdlFactory::createPlayerShip(std::string path) {
    return new SDLPlayerShip(gRenderer, SCREEN_HEIGHT, SCREEN_WIDTH, path);
}

void sdlFactory::close() {
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    IMG_Quit();
    SDL_Quit();
}

Background *sdlFactory::createBackground(std::string path) {
    return new SDLBackground(gRenderer, SCREEN_HEIGHT, SCREEN_WIDTH, path);
}

Alien *sdlFactory::createAlien(AlienType alienType, std::string path) {
    return new SDLAlien(gRenderer, SCREEN_HEIGHT, SCREEN_WIDTH, path, alienType);
}

bool sdlFactory::pollEvents() {
    SDL_Event ev;
    while (SDL_PollEvent(&ev) != 0) {
        if (ev.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}
