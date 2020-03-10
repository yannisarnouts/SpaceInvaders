cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Project main.cpp factory/AbstractFactory.cpp factory/AbstractFactory.h model/Entity.cpp model/Entity.h factory/TxTFactory.cpp factory/TxTFactory.h TxTClasses/TxTSpaceShip.cpp TxTClasses/TxTSpaceShip.h model/AbstractPlayerShip.cpp model/AbstractPlayerShip.h model/AbstractAlien.cpp model/AbstractAlien.h MVC/Game.cpp MVC/Game.h TxTClasses/TxTAlien.cpp TxTClasses/TxTAlien.h model/AbstractAlien.cpp model/AbstractBullet.cpp model/AbstractBullet.h TxTClasses/TxTBullet.cpp TxTClasses/TxTBullet.h MVC/GameView.cpp MVC/GameView.h factory/sdlFactory.cpp factory/sdlFactory.h SDLClasses/SDLSpaceShip.cpp SDLClasses/SDLSpaceShip.h factory/Texture.cpp factory/Texture.h)
target_link_libraries(Project ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)