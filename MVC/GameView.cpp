//
// Created by Gebruiker on 8/03/2020.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "GameView.h"

SDL_Rect srcR, destR;
void GameView::init(const char *title, int width, int height, bool fullscreen) {
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }
}

GameView::GameView() {
    init("SpaceInvaders", 800, 600, false);
    createTexture("../assets/bg.jpg");
    createTexture("../assets/spaceship.png");
    while (isRunning) {
        handleEvents();
        update();
        render();
    }
    clean();
}

void GameView::update() {
    cnt++;
    destR.w = 50;
    destR.h = 50;
    //std::cout << cnt << std::endl;
}

void GameView::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT :
            isRunning = false;
            break;
        default:
            break;
    }
}

void GameView::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void GameView::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

SDL_Texture* GameView::createTexture(const char* path) {
    printf("createtext");
    SDL_Surface* tmpSurface = IMG_Load(path);
    texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return texture;
}
