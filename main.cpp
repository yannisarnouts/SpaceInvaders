#include "factory/AbstractFactory.h"
#include "controller/Game.h"
#include "factory/SDLFactory.h"

int main(int argv, char** args) {
    Game::AbstractFactory *A = new SDL::SDLFactory();
    Game::Game *game = new Game::Game(A);
    game->Run();
    return 0;
}
