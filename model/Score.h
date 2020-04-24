//
// Created by Gebruiker on 3/04/2020.
//

#ifndef PROJECT_SCORE_H
#define PROJECT_SCORE_H

namespace Game {
    class Score {
    public:
        Score();

        virtual ~Score();

        int getPoints() const;
        void setPoints(int points);
        virtual void Visualize() = 0;
    private:
        int points = 0;
    };
}

#endif //PROJECT_SCORE_H
