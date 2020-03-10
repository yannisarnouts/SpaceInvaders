//
// Created by Gebruiker on 8/03/2020.
//

#ifndef PROJECT_GAMEVIEW_H
#define PROJECT_GAMEVIEW_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

class GameView {
public:
    GameView();
    void init(const char* title, int width, int height, bool fullscreen);
    SDL_Texture* createTexture(const char* path, SDL_Rect *rect);
    void handleEvents();
    void update();
    void render();
    void clean();

    SDL_Renderer *getRenderer() const;

    SDL_Window *getWindow() const;

private:
    SDL_Window* window = NULL;
    SDL_Texture* texture = NULL;
    SDL_Renderer* renderer;
    SDL_Rect* playerR;
    bool isRunning = false;
    int cnt = 0;
};


#endif //PROJECT_GAMEVIEW_H
