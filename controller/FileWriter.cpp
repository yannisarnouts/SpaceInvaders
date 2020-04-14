//
// Created by Gebruiker on 14/04/2020.
//

#include <fstream>
#include "FileWriter.h"
FileWriter::FileWriter() {}

FileWriter::FileWriter(const std::string &file) : file(file) {
    std::ofstream MyFile("..\\stats.txt");
    MyFile << "file written";
    MyFile.close();
}