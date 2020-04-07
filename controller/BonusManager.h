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
        void fireBonusses(int i);

    private:
        AbstractFactory *abstractFactory;
        Bonus *currentBonus;
        std::vector<Bonus*> bonusses;
        Timer *timer;
        int SCREEN_WIDTH = 950;
        bool runBonus = false;
    };
}

#endif //PROJECT_BONUSMANAGER_H
