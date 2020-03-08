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
    SDL_Texture* createTexture(const char* path);
    void handleEvents();
    void update();
    void render();
    void clean();
private:
    SDL_Window* window = NULL;
    SDL_Texture* texture = NULL;
    SDL_Renderer* renderer;
    bool isRunning = false;
    int cnt = 0;
};


#endif //PROJECT_GAMEVIEW_H
