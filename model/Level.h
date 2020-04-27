//
// Created by Gebruiker on 27/04/2020.
//

#ifndef SPACEINVADERS_LEVEL_H
#define SPACEINVADERS_LEVEL_H

namespace Game {
    class Level {
    public:
        Level();
        virtual ~Level();
        int getLevel() const;
        void setLevel(int level);
        virtual void Visualize() = 0;

    private:
        int level = 1;
    };
}

#endif //SPACEINVADERS_LEVEL_H
