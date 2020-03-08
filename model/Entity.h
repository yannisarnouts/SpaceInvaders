//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_ENTITY_H
#define PROJECT_ENTITY_H


class Entity {
public:
    Entity();
    Entity(int xCoord, int yCoord, int width, int height);
    int getXCoord() const;
    int getYCoord() const;
    void setXCoord(int xCoord);
    void setYCoord(int yCoord);
private:
    int xCoord;
    int yCoord;
    int width;
    int height;
};


#endif //PROJECT_ENTITY_H
