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
#include <cctype>
#include <map>
#include <rpcndr.h>

using namespace std;


class ReadFileIni{

public:
    bool OpenFileIni(const string& nameFileInput);
    string readSection(const string &section_input);
    string readParameter(const string &param_input, string section);
    int saveFile(const string& nameFileOutput);
    boolean setSection(const string &sec);
    boolean setParameter(const string &param, string section);

private:
    fstream File_in_input;
    filebuf File_in_output;
    vector<string> line_Of_File;
    string section;
    string parameter;

};


#endif //FILE_INI_READFILEINI_H
