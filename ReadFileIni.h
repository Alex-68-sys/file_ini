//
// Created by Alessandro on 05/04/2022.
//

#ifndef FILE_INI_READFILEINI_H
#define FILE_INI_READFILEINI_H

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


class ReadFileIni{

public:
    bool OpenFileIni(string nameFileInput);
    void ReadOpenFile();
    int VideoVisualize();
    void SaveOpenFile(string nameFileOutput);

private:
    fstream File_in_input;
    filebuf File_in_output;
    vector<string> line_Of_File;

};


#endif //FILE_INI_READFILEINI_H
