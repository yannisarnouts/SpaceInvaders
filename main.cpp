#include <iostream>
#include "factory/AbstractFactory.h"
#include "factory/TxTFactory.h"
#include "MVC/Game.h"
#include "factory/sdlFactory.h"

int main(int argv, char** args) {
    AbstractFactory *A = new sdlFactory();
    Game *game = new Game(A);
    game->Run();
    return 0;
}
