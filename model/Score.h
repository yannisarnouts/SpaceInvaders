//
// Created by Gebruiker on 3/04/2020.
//

#ifndef PROJECT_SCORE_H
#define PROJECT_SCORE_H

#include "Entity.h"

namespace Game {
    class Score : public Entity {
    public:
        Score(int xCoord, int yCoord, int width, int height);
        virtual ~Score();
        int getPoints() const;
        void setPoints(int points);
        virtual void Visualize() = 0;
    private:
        int points = 0;
    };
}

#endif //PROJECT_SCORE_H
