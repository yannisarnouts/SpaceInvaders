cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Project main.cpp factory/AbstractFactory.cpp factory/AbstractFactory.h model/PlayerShip.cpp model/PlayerShip.h MVC/Game.cpp MVC/Game.h factory/sdlFactory.cpp factory/sdlFactory.h SDLClasses/SDLPlayerShip.cpp SDLClasses/SDLPlayerShip.h factory/Texture.cpp factory/Texture.h SDLClasses/SDLBackground.cpp SDLClasses/SDLBackground.h model/Background.cpp model/Background.h model/Alien.cpp model/Alien.h SDLClasses/SDLAlien.cpp SDLClasses/SDLAlien.h model/AlienType.h)
target_link_libraries(Project ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)