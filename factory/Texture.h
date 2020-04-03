//
// Created by Gebruiker on 10/03/2020.
//

#ifndef PROJECT_TEXTURE_H
#define PROJECT_TEXTURE_H


#include <SDL2/SDL_render.h>
#include <string>

class Texture {
public:
    Texture(SDL_Renderer* renderer);
    Texture();
    void free();
    SDL_Texture *getTexture() const;
    bool loadFromFile(std::string path);

private:
    SDL_Texture* texture = NULL;
    SDL_Renderer* renderer;
    int height;
    int width;
};


#endif //PROJECT_TEXTURE_H
