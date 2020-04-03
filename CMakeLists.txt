cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Project main.cpp factory/AbstractFactory.cpp factory/AbstractFactory.h model/PlayerShip.cpp model/PlayerShip.h controller/Game.cpp controller/Game.h factory/SDLFactory.cpp factory/SDLFactory.h SDLClasses/SDLPlayerShip.cpp SDLClasses/SDLPlayerShip.h factory/Texture.cpp factory/Texture.h SDLClasses/SDLBackground.cpp SDLClasses/SDLBackground.h model/Background.cpp model/Background.h model/Alien.cpp model/Alien.h SDLClasses/SDLAlien.cpp SDLClasses/SDLAlien.h model/AlienType.h controller/KeyHandler.cpp controller/KeyHandler.h controller/KeyP.h model/Bullet.cpp model/Bullet.h SDLClasses/SDLBullet.cpp SDLClasses/SDLBullet.h controller/AlienManager.cpp controller/AlienManager.h model/Canon.cpp model/Canon.h model/Entity.cpp model/Entity.h controller/CollisionController.cpp controller/CollisionController.h model/AlienCanon.cpp model/AlienCanon.h model/Score.cpp model/Score.h)
target_link_libraries(Project ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)