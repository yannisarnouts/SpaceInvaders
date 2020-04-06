//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_PLAYERMANAGER_H
#define PROJECT_PLAYERMANAGER_H

#include "../factory/AbstractFactory.h"

namespace Game {
    class PlayerManager {
    public:
        PlayerManager();
        PlayerManager(AbstractFactory *abstractFactory);
        PlayerShip *getPlayerShip() const;
        void runPlayer();
        void setLife();

    private:
        AbstractFactory *abstractFactory;
        PlayerShip *playerShip;
        Life *life;
        std::string shipPath = "../assets/spaceship.png";
    };
}

#endif //PROJECT_PLAYERMANAGER_H
