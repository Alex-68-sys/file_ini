//
// Created by Alessandro on 06/06/2021.
//

#ifndef FILE_INI_FILE_H
#define FILE_INI_FILE_H
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


class ReadFileIni{
public:
    ReadFileIni() {};
    ~ReadFileIni() { };
    bool OpenFileIni(string);
    void ReadOpenFile();
    int VideoVisualize();

private:
    fstream File_in_input;
    vector<string> line_Of_File;

};


#endif //FILE_INI_FILE_H
