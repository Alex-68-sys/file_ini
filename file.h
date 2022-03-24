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


class Read_File_INI{
public:
    Read_File_INI() {};
    ~Read_File_INI() { };
    bool Open_File(string);
    void Read_Open_File();
    int Video_Visualize();

private:
    fstream File_in_input;
    vector<string> line_Of_File;

};


#endif //FILE_INI_FILE_H
