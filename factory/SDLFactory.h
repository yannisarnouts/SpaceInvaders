//
// Created by Gebruiker on 8/03/2020.
//

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H


#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include "AbstractFactory.h"
#include "../model/AlienType.h"
#include "../controller/KeyHandler.h"
#include "../SDLClasses/SDLAlienBullet.h"
#include "../SDLClasses/SDLLife.h"
#include "../controller/ConfigReader.h"

namespace SDL {
    class SDLFactory : public Game::AbstractFactory {
    public:
        SDLFactory();
        virtual ~SDLFactory();
        // playership classes
        Game::PlayerShip *createPlayerShip() override;
        Game::Bullet *createBullet(int xCoord, int yCoord) override;
        Game::Score *createScore() override;
        Game::Life *createLife() override;

        // alien classes
        Game::Alien *createAlien(AlienType alienType, int xPos, int yPos) override;
        Game::AlienBullet *createAlienBullet(int xCoord, int yCoord) override;

        // other game classes
        Game::Bonus *createBonus(int xPos, int yPos, Game::BonusType bonusType) override;
        Background *createBackground(std::string path) override;
        Game::Timer *createTimer() override;

        // config
        void setScreenHeight(int screenHeight);

        void setScreenWidth(int screenWidth);

        bool pollEvents() override;

        void render() override;

        void close() override;

    private:
        SDL_Window *gWindow = NULL;
        SDL_Renderer *gRenderer = NULL;
        int SCREEN_HEIGHT;
        int SCREEN_WIDTH;
        ConfigReader *configReader;
    };
}

#endif //PROJECT_SDLFACTORY_H
