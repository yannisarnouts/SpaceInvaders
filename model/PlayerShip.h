//
// Created by Gebruiker on 3/03/2020.
//

#ifndef PROJECT_PLAYERSHIP_H
#define PROJECT_PLAYERSHIP_H


class PlayerShip {
public:
    PlayerShip();

    PlayerShip(int shipWidth, int shipHeight);

    virtual void Visualize()=0;
    virtual void close()=0;
    virtual void moveShip()=0;
    int getXCoord() const;
    void setXCoord(int xCoord);
    int getYCoord() const;
    int getShipWidth() const;
    int getShipHeight() const;

private:
    int xCoord; int yCoord;
    int shipWidth; int shipHeight;

};


#endif //PROJECT_PLAYERSHIP_H
