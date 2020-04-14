//
// Created by Gebruiker on 14/04/2020.
//

#include <fstream>
#include "FileWriter.h"
FileWriter::FileWriter() {}

void FileWriter::writeFile(std::string text) {
    std::ofstream MyFile("..\\stats.txt");
    MyFile << text;
    MyFile.close();
}
