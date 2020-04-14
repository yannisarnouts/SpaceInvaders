//
// Created by Gebruiker on 14/04/2020.
//

#ifndef SPACEINVADERS_FILEWRITER_H
#define SPACEINVADERS_FILEWRITER_H


#include <string>

class FileWriter {
public:
    FileWriter();
    void writeFile(std::string text);

private:
    std::string file;
};


#endif //SPACEINVADERS_FILEWRITER_H
