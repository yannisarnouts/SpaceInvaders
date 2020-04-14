//
// Created by Gebruiker on 14/04/2020.
//

#ifndef SPACEINVADERS_FILEWRITER_H
#define SPACEINVADERS_FILEWRITER_H


#include <string>

class FileWriter {
public:
    FileWriter();
    void writeStats();
    void del_line(const char *file_name, int n);
    int getPoints() const;
    void setPoints(int points);
    int getLifesLeft() const;
    void setLifesLeft(int lifesLeft);
    int getFileSize();

private:
    std::string file;
    int points;
    int lifesLeft;
    int fileSize = 0;
};


#endif //SPACEINVADERS_FILEWRITER_H
