//
// Created by Gebruiker on 7/04/2020.
//

#ifndef PROJECT_BONUSMANAGER_H
#define PROJECT_BONUSMANAGER_H

#include <vector>
#include "../factory/AbstractFactory.h"
#include "../model/Bonus.h"

namespace Game {
    class BonusManager {
    public:
        BonusManager();
        BonusManager(AbstractFactory *abstractFactory);
        void createBonusses();
        void Visualize();
        void runBonusses();
        void fireBonusses();

    private:
        AbstractFactory *abstractFactory;
        std::vector<Bonus*> bonusses;
        Timer *timer;
        int SCREEN_WIDTH = 950;
        int SCREEN_HEIGHT = 1280;
        bool runBonus = false;
        int i = -1;
    };
}

#endif //PROJECT_BONUSMANAGER_H
