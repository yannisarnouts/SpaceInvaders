#include <iostream>
#include "factory/AbstractFactory.h"
#include "factory/TxTFactory.h"
#include "MVC/Game.h"

int main() {
    AbstractFactory *A = new TxTFactory();
    Game *game = new Game(A);
    game->Run();
    return 0;
}
