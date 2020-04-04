//
// Created by Gebruiker on 3/04/2020.
//

#ifndef PROJECT_TEXTTEXTURE_H
#define PROJECT_TEXTTEXTURE_H


#include <SDL2/SDL_render.h>
#include <string>
#include <SDL2/SDL_ttf.h>

class TextTexture {
public:
    TextTexture();
    TextTexture(SDL_Renderer *renderer);
    bool loadTexture(std::string text);

    SDL_Texture *getTexture() const;

    void free();

private:
    SDL_Texture* texture = NULL;
    SDL_Renderer* renderer;
    TTF_Font *gFont = NULL;
    int height;
    int width;
};


#endif //PROJECT_TEXTTEXTURE_H
