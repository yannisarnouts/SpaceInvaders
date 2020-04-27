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
    double getTimePlayed() const;
    void setTimePlayed(double timePlayed);
    int getBulletsFired() const;
    void setBulletsFired(int bulletsFired);
    int getBonussesCaught() const;
    void setBonussesCaught(int bonussesCaught);
    int getAliensKilled() const;
    void setAliensKilled(int aliensKilled);
    int getFileSize();

    int getLevel() const;

    void setLevel(int level);

private:
    std::string file;
    int level;
    int points;
    int lifesLeft;
    double timePlayed;
    int bulletsFired;
    int bonussesCaught;
    int fileSize = 0;
    int aliensKilled;
};


#endif //SPACEINVADERS_FILEWRITER_H
