//
// Created by Gebruiker on 8/03/2020.
//

#ifndef PROJECT_SDLPLAYERSHIP_H
#define PROJECT_SDLPLAYERSHIP_H


#include "../model/PlayerShip.h"
#include "../factory/Texture.h"
#include "../controller/KeyHandler.h"
#include "../controller/ConfigReader.h"

namespace SDL {
    class SDLPlayerShip : public Game::PlayerShip {
    public:
        SDLPlayerShip();
        SDLPlayerShip(int xCoord, int yCoord, int width, int height, SDL_Renderer *gRenderer);
        ~SDLPlayerShip();
        void Visualize() override;

    private:
        SDL_Renderer *gRenderer;
        Texture *texture = NULL;
        std::string shipPath = "../assets/spaceship.png";
    };
}

#endif //PROJECT_SDLPLAYERSHIP_H
