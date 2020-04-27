//
// Created by Gebruiker on 14/04/2020.
//

#include <fstream>
#include <ctime>
#include "FileWriter.h"

FileWriter::FileWriter() {}

void FileWriter::writeStats() {
    std::ofstream statsFile;
    int fSize = getFileSize();
    time_t now = time(0);
    del_line("..\\stats.html", fSize);
    del_line("..\\stats.html", fSize-1);
    del_line("..\\stats.html", fSize-2);
    statsFile.open("..\\stats.html", std::ios_base::app);
    statsFile << "\t\t\t<tr>\n";
    statsFile << "\t\t\t\t<td>" << ctime(&now) << "</td>\n";
    statsFile << "\t\t\t\t<td>" << std::to_string(getLevel()) << "</td>\n";
    statsFile << "\t\t\t\t<td>" << std::to_string(getPoints()) << "</td>\n";
    statsFile << "\t\t\t\t<td>" << std::to_string(getAliensKilled()) << "</td>\n";
    statsFile << "\t\t\t\t<td>" << std::to_string(getLifesLeft()) << "</td>\n";
    statsFile << "\t\t\t\t<td>" << std::to_string(getBulletsFired()) << "</td>\n";
    statsFile << "\t\t\t\t<td>" << std::to_string(getBonussesCaught()) << "</td>\n";
    statsFile << "\t\t\t</tr>\n";
    statsFile << "\t\t</table>\n";
    statsFile << "\t</body>\n";
    statsFile << "</html>\n";
    statsFile.close();
}
void FileWriter::del_line(const char *file_name, int n) {
    std::ifstream fin(file_name);
    std::ofstream fout;
    fout.open("temp.txt", std::ios::out);

    char ch;
    int line = 1;
    while (fin.get(ch)) {
        if (ch == '\n')
            line++;

        if (line != n)      // content not to be deleted
            fout << ch;
    }
    fout.close();
    fin.close();
    remove(file_name);
    rename("temp.txt", file_name);
}


int FileWriter::getPoints() const {
    return points;
}

void FileWriter::setPoints(int points) {
    FileWriter::points = points;
}

int FileWriter::getLifesLeft() const {
    return lifesLeft;
}

void FileWriter::setLifesLeft(int lifesLeft) {
    FileWriter::lifesLeft = lifesLeft;
}

int FileWriter::getFileSize() {
    std::string line;
    std::ifstream myfile("..\\stats.html");
    while (std::getline(myfile, line)) {
        fileSize++;
    }
    return fileSize;
}

int FileWriter::getBulletsFired() const {
    return bulletsFired;
}

void FileWriter::setBulletsFired(int bulletsFired) {
    FileWriter::bulletsFired = bulletsFired;
}

int FileWriter::getBonussesCaught() const {
    return bonussesCaught;
}

void FileWriter::setBonussesCaught(int bonussesCaught) {
    FileWriter::bonussesCaught = bonussesCaught;
}

int FileWriter::getAliensKilled() const {
    return aliensKilled;
}

void FileWriter::setAliensKilled(int aliensKilled) {
    FileWriter::aliensKilled = aliensKilled;
}

int FileWriter::getLevel() const {
    return level;
}

void FileWriter::setLevel(int level) {
    FileWriter::level = level;
}
