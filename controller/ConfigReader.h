//
// Created by Gebruiker on 11/04/2020.
//

#ifndef SPACEINVADERS_CONFIGREADER_H
#define SPACEINVADERS_CONFIGREADER_H

#include "xmllite.h"
#include "iostream"
#include "fstream"

class ConfigReader {
public:
    ConfigReader();
    void setValue(std::string line, int value);
    int getScreenWidth() const;
    void setScreenWidth(int screenWidth);
    int getScreenHeight() const;
    void setScreenHeight(int screenHeight);
    int getShipSpeed() const;
    void setShipSpeed(int shipSpeed);

    int getShipLife() const;

    void setShipLife(int shipLife);

private:
    // read config file
    std::ifstream input;
    std::string configFile = "..\\config.txt";
    std::string line;
    int value;
    // config settings
    int screen_width;
    int screen_height;
    int shipSpeed;
    int shipLife;
};


#endif //SPACEINVADERS_CONFIGREADER_H
