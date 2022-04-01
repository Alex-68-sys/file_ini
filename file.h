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
    bool OpenFileIni(string nameOfFileinput);
    void ReadOpenFile();
    int VideoVisualize();
    void SaveOpenFile(string name_of_file_output);

private:
    fstream File_in_input;
    filebuf File_in_output;
    vector<string> line_Of_File;

};


#endif //FILE_INI_FILE_H
