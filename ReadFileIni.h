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
    string readSection(string& section_input);
    string readParameter(string& param_input);
    void saveFile(string& nameFileOutput);
    void setSection(string& sec,string& Fileinoutput);
    void setParameter(string& param);

private:
    fstream File_in_input;
    filebuf File_in_output;
    vector<string> line_Of_File;
    string section;
    string parameter;

};


#endif //FILE_INI_READFILEINI_H
