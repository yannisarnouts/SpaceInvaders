//
// Created by Gebruiker on 8/03/2020.
//

#include "SDLFactory.h"
#include "../SDLClasses/SDLPlayerShip.h"
#include "../SDLClasses/SDLBackground.h"
#include "../SDLClasses/SDLAlien.h"
#include "../SDLClasses/SDLBullet.h"
#include "../SDLClasses/SDLScore.h"
#include "../SDLClasses/SDLAlienBullet.h"
#include "../SDLClasses/SDLTimer.h"
#include "../SDLClasses/SDLBonus.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

SDL::SDLFactory::SDLFactory() {}

void SDL::SDLFactory::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    } else if (TTF_Init() < 0) {
        printf("TTF_Init: %s\n", TTF_GetError());
    } else {
        //Create window
        gWindow = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT,
                                   SCREEN_WIDTH, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        } else {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                }
            }
        }
    }
}

void SDL::SDLFactory::render() {
    //update the screen
    SDL_RenderPresent(gRenderer);
}

Game::PlayerShip *SDL::SDLFactory::createPlayerShip(std::string path) {
    int sh = SCREEN_HEIGHT / 7;
    int sw = SCREEN_WIDTH / 7;
    int xc = SCREEN_WIDTH / 2;
    int yc = SCREEN_HEIGHT - 550;
    return new SDLPlayerShip(xc, yc, sw, sh, gRenderer, path);
}

void SDL::SDLFactory::close() {
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

Background *SDL::SDLFactory::createBackground(std::string path) {
    return new SDLBackground(gRenderer, SCREEN_HEIGHT, SCREEN_WIDTH, path);
}

Game::Alien *SDL::SDLFactory::createAlien(AlienType alienType, std::string path, int xPos, int yPos) {
    int alienWidth = SCREEN_WIDTH / 15;
    int alienHeight = SCREEN_HEIGHT / 20;
    return new SDLAlien(xPos, yPos, alienWidth, alienHeight, alienType, gRenderer, path);
}

bool SDL::SDLFactory::pollEvents() {
    SDL_Event ev;
    bool play = true;
    while (SDL_PollEvent(&ev) != 0) {
        if (ev.type == SDL_QUIT) {
            play = false;
        }
    }
    return play;
}

Game::Bullet *SDL::SDLFactory::createBullet(std::string path, int xCoord, int yCoord) {
    int bw = SCREEN_WIDTH / 30;
    int bh = SCREEN_HEIGHT / 30;
    return new SDLBullet(xCoord, yCoord, bw, bh, gRenderer, path);
}

Game::Score *SDL::SDLFactory::createScore() {
    return new SDLScore(gRenderer);
}

Game::AlienBullet *SDL::SDLFactory::createAlienBullet(std::string path, int xCoord, int yCoord) {
    int bw = SCREEN_WIDTH / 30;
    int bh = SCREEN_HEIGHT / 30;
    return new SDLAlienBullet(xCoord, yCoord, bw, bh, gRenderer, path);
}

Game::Life *SDL::SDLFactory::createLife() {
    return new SDLLife(gRenderer);
}

Game::Timer *SDL::SDLFactory::createTimer() {
    return new SDLTimer();
}

Game::Bonus *SDL::SDLFactory::createBonus(int xPos, int yPos, Game::BonusType bonusType) {
    int gw = SCREEN_WIDTH / 30;
    int gh = SCREEN_HEIGHT / 30;
    return new SDLBonus(xPos, yPos, gw, gh, bonusType, gRenderer);
}
