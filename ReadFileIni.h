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
    vector<string> readSection(string& section_input);
    vector<string> readParameter(string& param);
    void saveFile(string& nameFileOutput);
    void setSection(string& sec);
    void setParameter(string& param);

private:
    fstream File_in_input;
    filebuf File_in_output;
    vector<string> line_Of_File;
    vector<string>section;
    vector<string>parameter;

};


#endif //FILE_INI_READFILEINI_H
