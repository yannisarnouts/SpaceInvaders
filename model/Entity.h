//
// Created by Gebruiker on 30/03/2020.
//

#ifndef PROJECT_ENTITY_H
#define PROJECT_ENTITY_H

namespace Game {
    class Entity {
    public:
        Entity();

        Entity(int xCoord, int yCoord, int width, int height);

        int getXCoord() const;

        void setXCoord(int xCoord);

        int getYCoord() const;

        void setYCoord(int yCoord);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

    private:
        int xCoord;
        int yCoord;
        int width;
        int height;
    };
}

#endif //PROJECT_ENTITY_H
