//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_LIFE_H
#define PROJECT_LIFE_H

namespace Game {
    class Life {
    public:
        Life();
        virtual ~Life();
        virtual void Visualize()=0;
        int getLife() const;
        void setLife(int life);

    private:
        int life = 3;
    };
}

#endif //PROJECT_LIFE_H
