//
// Created by Gebruiker on 3/03/2020.
//

#include <zconf.h>
#include "Game.h"
#include "../SDLClasses/SDLPlayerShip.h"
#include "../model/Background.h"
#include "../model/Alien.h"

Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Run() {
    A->init(640, 480);
    Background *bg = A->createBackground(bgPath);
    PlayerShip *playerShip = A->createPlayerShip(shipPath);
    Alien *alien = A->createAlien(AlienType::thomas, thomasAlien);
    bool a = true;
    while (a) {
        bg->Visualize();
        playerShip->Visualize();
        //alien->Visualize();
        A->render();
    }
    bg->close();
    playerShip->close();
    alien->close();
    A->close();
}
