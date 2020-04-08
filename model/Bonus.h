//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_BONUS_H
#define PROJECT_BONUS_H

#include "Entity.h"
#include "BonusType.h"

namespace Game {
    class Bonus : public Entity {
    public:
        Bonus();
        Bonus(int xCoord, int yCoord, int width, int height);
        Bonus(int xCoord, int yCoord, int width, int height, BonusType bonusType);
        virtual void Visualize() = 0;
        virtual void close() = 0;

        BonusType getBonusType() const;

        void setBonusType(BonusType bonusType);

    private:
        BonusType bonusType;
    };
}

#endif //PROJECT_BONUS_H
