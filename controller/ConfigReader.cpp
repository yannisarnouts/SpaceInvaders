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
