//
// Created by Gebruiker on 14/04/2020.
//

#ifndef SPACEINVADERS_FILEWRITER_H
#define SPACEINVADERS_FILEWRITER_H


#include <string>

class FileWriter {
public:
    FileWriter();
    FileWriter(const std::string &file);

private:
    std::string file;
};


#endif //SPACEINVADERS_FILEWRITER_H
