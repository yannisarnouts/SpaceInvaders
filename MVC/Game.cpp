//
// Created by Gebruiker on 3/03/2020.
//

#include "Game.h"
#include "GameView.h"
#include "../SDLClasses/SDLSpaceShip.h"

Game::Game(AbstractFactory *_A) {
    A = _A;
}

void Game::Run() {
    //GameView();
    AbstractPlayerShip *playerShip = A->createPlayerShip();
    playerShip->Visualize(*playerShip);
}
