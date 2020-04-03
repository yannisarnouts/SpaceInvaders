//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_ALIENS_H
#define PROJECT_ALIENMANAGER_H


#include <vector>
#include "../factory/AbstractFactory.h"
#include "../model/Canon.h"
#include "CollisionController.h"
#include "../model/AlienCanon.h"

namespace Game {
    class AlienManager {
    public:
        AlienManager(AbstractFactory *abstractFactory, Canon *canon);
        void Visualize(AlienType alienType);
        void VisualizeType(AlienType alienType, int length);
        void createAliens(int number, AlienType alienType, std::string imgPath, int y);
        void moveAndCheck(int a, int length);
        void handleCollision(int i, int j, int length, AlienType alienType);
        void alienShoot(int i, int j);

    private:
        AbstractFactory *abstractFactory;
//    Alien* aliens[4][10];
        std::vector<std::vector<Alien * >> aliens;
        int yCoord;
        AlienCanon *alienCanon;
        Canon *canon;
        int michielLength = 10, thomasLength = 10, rubenLength = 10, cliffordLength = 10;
        int cani = 100;
        int canj = 100;
    };
}

#endif //PROJECT_ALIENS_H
