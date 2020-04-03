//
// Created by Gebruiker on 3/04/2020.
//

#ifndef PROJECT_SCORE_H
#define PROJECT_SCORE_H


class Score {
public:
    Score();

    int getPoints() const;

    void setPoints(int points);

private:
    int points;
};


#endif //PROJECT_SCORE_H
