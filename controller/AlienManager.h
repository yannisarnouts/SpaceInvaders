//
// Created by Gebruiker on 17/03/2020.
//

#ifndef PROJECT_ALIENS_H
#define PROJECT_ALIENMANAGER_H


#include <vector>
#include "../factory/AbstractFactory.h"
#include "CollisionController.h"
#include "../model/Timer.h"
#include "CanonManager.h"

namespace Game {
    class AlienManager {
    public:
        AlienManager(AbstractFactory *abstractFactory, CanonManager *canon);
        void Visualize(AlienType alienType);
        void VisualizeType(AlienType alienType, int length);
        void createAliens(int number, AlienType alienType, std::string imgPath, int y, int a);
        void moveAndCheck(int a, int length);
        void handleCollision(int i, int j, int length, AlienType alienType);
        bool checkCollision(int xPos, int yPos);
        void alienShoot();

    private:
        AbstractFactory *abstractFactory;
        std::vector<std::vector<Alien * >> aliens;
        std::vector<AlienBullet*> bullets;
        int bulletLength = 500;
        CanonManager *canon; AlienBullet *currentBullet;
        CollisionController *collisionController;
        int michielLength = 10, thomasLength = 10, rubenLength = 10, cliffordLength = 10;
    };
}

#endif //PROJECT_ALIENS_H
