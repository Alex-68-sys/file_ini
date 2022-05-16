//
// Created by Alessandro on 05/04/2022.
//

#ifndef FILE_INI_READFILEINI_H
#define FILE_INI_READFILEINI_H

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;


class ReadFileIni{

public:
    bool OpenFileIni(string& nameFileInput);
    void readFile();
    string readSection(const string &section_input);
    string readParameter(const string &param_input);
    void saveFile(string& nameFileOutput);
    void setSection(const string &sec, string &file);
    void setParameter(string &param);

private:
    fstream File_in_input;
    filebuf File_in_output;
    vector<string> line_Of_File;
    string section;
    string parameter;

};


#endif //FILE_INI_READFILEINI_H
