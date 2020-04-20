//
// Created by Gebruiker on 11/04/2020.
//

#include "ConfigReader.h"

ConfigReader::ConfigReader() {
    std::string file = configFile;
    std::ifstream input;
    input.open(file);
    if (!input.is_open()) {
        printf("can't open");
    }
    while (input) {
        getline(input, line, '=');
        input >> value;
        input.get();
        setValue(line, value);
    }
    input.close();
}

void ConfigReader::setValue(std::string line, int value) {
    if (line == "SCREENHEIGHT") {
        setScreenWidth(value);
    } else if (line == "SCREENWIDTH") {
        setScreenHeight(value);
    } else if (line == "SHIPSPEED") {
        setShipSpeed(value);
    } else if (line == "LIFE") {
        setShipLife(value);
    } else if (line == "BONUSSPEED") {
        setBonusSpeed(value);
    } else if (line == "BULLETSPEED") {
        setBulletSpeed(value);
    } else if (line == "CANONLENGTH") {
        setCanonLength(value);
    } else if (line == "ALIENSPEED") {
        setAlienSpeed(value);
    } else if (line == "ALIENTYPES") {
        setAlienTypes(value);
    }
}

int ConfigReader::getScreenWidth() const {
    return screen_width;
}

void ConfigReader::setScreenWidth(int screenWidth) {
    screen_width = screenWidth;
}

int ConfigReader::getScreenHeight() const {
    return screen_height;
}

void ConfigReader::setScreenHeight(int screenHeight) {
    screen_height = screenHeight;
}

int ConfigReader::getShipSpeed() const {
    return shipSpeed;
}

void ConfigReader::setShipSpeed(int shipSpeed) {
    ConfigReader::shipSpeed = shipSpeed;
}

int ConfigReader::getShipLife() const {
    return shipLife;
}

void ConfigReader::setShipLife(int shipLife) {
    ConfigReader::shipLife = shipLife;
}

int ConfigReader::getBulletSpeed() const {
    return bulletSpeed;
}

void ConfigReader::setBulletSpeed(int bulletSpeed) {
    ConfigReader::bulletSpeed = bulletSpeed;
}

int ConfigReader::getBonusSpeed() const {
    return bonusSpeed;
}

void ConfigReader::setBonusSpeed(int bonusSpeed) {
    ConfigReader::bonusSpeed = bonusSpeed;
}

int ConfigReader::getCanonLength() const {
    return canonLength;
}

void ConfigReader::setCanonLength(int canonLength) {
    ConfigReader::canonLength = canonLength;
}

int ConfigReader::getAlienSpeed() const {
    return alienSpeed;
}

void ConfigReader::setAlienSpeed(int alienSpeed) {
    ConfigReader::alienSpeed = alienSpeed;
}

int ConfigReader::getAlienTypes() const {
    return alienTypes;
}

void ConfigReader::setAlienTypes(int alienTypes) {
    ConfigReader::alienTypes = alienTypes;
}
