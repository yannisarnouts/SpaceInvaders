#include <iostream>
#include "factory/AbstractFactory.h"
#include "controller/Game.h"
#include "factory/SDLFactory.h"

int main(int argv, char** args) {
    AbstractFactory *A = new SDLFactory();
    Game *game = new Game(A);
    game->Run();
    return 0;
}
