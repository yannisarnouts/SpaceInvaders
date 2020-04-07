//
// Created by Gebruiker on 7/04/2020.
//

#ifndef PROJECT_SDLBONUS_H
#define PROJECT_SDLBONUS_H

#include <SDL2/SDL_render.h>
#include "../model/Bonus.h"
#include "../factory/Texture.h"

namespace SDL {
    class SDLBonus : public Game::Bonus {
    public:
        SDLBonus();

        SDLBonus(int xCoord, int yCoord, int width, int height, Game::BonusType bonusType, SDL_Renderer *renderer);

        void Visualize() override;

        void close() override;

    private:
        SDL_Renderer *renderer;
        Texture *texture = NULL;
        std::string imgPath = "../assets/bonus.jpg";
        int SCREEN_WIDTH = 950;
    };
}

#endif //PROJECT_SDLBONUS_H
