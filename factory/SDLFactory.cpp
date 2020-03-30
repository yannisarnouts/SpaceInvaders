//
// Created by Gebruiker on 8/03/2020.
//

#include "SDLFactory.h"
#include "../SDLClasses/SDLPlayerShip.h"
#include "../SDLClasses/SDLBackground.h"
#include "../SDLClasses/SDLAlien.h"
#include "../SDLClasses/SDLBullet.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

SDLFactory::SDLFactory() {}

void SDLFactory::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    } else {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);
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

void SDLFactory::render() {
    //update the screen
    SDL_RenderPresent(gRenderer);
}

PlayerShip *SDLFactory::createPlayerShip(std::string path) {
    return new SDLPlayerShip(SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, path);
}

void SDLFactory::close() {
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    IMG_Quit();
    SDL_Quit();
}

Background *SDLFactory::createBackground(std::string path) {
    return new SDLBackground(gRenderer, SCREEN_HEIGHT, SCREEN_WIDTH, path);
}

Alien *SDLFactory::createAlien(AlienType alienType, std::string path, int xPos, int yPos) {
    return new SDLAlien(SCREEN_WIDTH, SCREEN_HEIGHT, alienType ,xPos, yPos, gRenderer, path);
}

bool SDLFactory::pollEvents() {
    SDL_Event ev;
    bool play = true;
    while (SDL_PollEvent(&ev) != 0) {
        if (ev.type == SDL_QUIT) {
            play = false;
        }
    }
    return play;
}

Bullet *SDLFactory::createBullet(std::string path, int xCoord, int yCoord) {
    return new SDLBullet(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, path, xCoord, yCoord);
}
