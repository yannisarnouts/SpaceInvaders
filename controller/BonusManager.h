//
// Created by Gebruiker on 7/04/2020.
//

#ifndef PROJECT_BONUSMANAGER_H
#define PROJECT_BONUSMANAGER_H

#include <vector>
#include "../factory/AbstractFactory.h"
#include "../model/Bonus.h"
#include "PlayerManager.h"
#include "CollisionController.h"
#include "CanonManager.h"

namespace Game {
    class BonusManager {
    public:
        BonusManager();
        BonusManager(AbstractFactory *abstractFactory, PlayerManager *playerManager, CanonManager *canonManager);
        void createBonusses();
        void Visualize();
        void runBonusses();
        void fireBonusses();
        bool checkCollision();

    private:
        AbstractFactory *abstractFactory;
        std::vector<Bonus*> bonusses;
        Timer *timer;
        CollisionController *collisionController;
        PlayerShip *playerShip;
        CanonManager *canonManager;
        PlayerManager *playerManager;
        BonusType bonusType;
        int SCREEN_WIDTH = 950;
        int SCREEN_HEIGHT = 1280;
        bool runBonus = false;
        int i = -1;
    };
}

#endif //PROJECT_BONUSMANAGER_H
