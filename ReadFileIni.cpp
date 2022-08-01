//
// Created by Alessandro on 05/04/2022.
//

#include "ReadFileIni.h"

using namespace std;

/*
 * ReadFileIni::OpenFileIni(string s)
 * apre il file specificato nel parametro nameOfFileinput
 */
bool ReadFileIni::OpenFileIni(string& nameFileInput) {
    string fileExt = nameFileInput.substr(nameFileInput.find_last_of(".") + 1);
    if (fileExt!= "ini") {
        cout << "Error extension file" << endl;
        return false;
    }
    File_in_input.open(nameFileInput);
    string buffer;
    while(getline(File_in_input, buffer))
        line_Of_File.push_back(buffer);
    return true;

}

void ReadFileIni::saveFile(string& nameFileOutput) {

    File_in_output.open (nameFileOutput, std::ios::out);
    ostream os(&File_in_output);
    for(auto & i : line_Of_File)
        os << i << "\n";
    cout <<"File Saved!"<<endl;
    File_in_output.close();
}

string ReadFileIni::readSection(const string &section_input) {
    string tmp;
    for(auto & i: line_Of_File) {
        if (i[0] == '#' || tmp.empty())
            continue;
        if (i == section_input) {
            cout << "Section found!" << endl;
            section = tmp;
        }else
            section="not found";
    }
    return section;
}

string ReadFileIni::readParameter(const string &param_input,string section) {
    string tmp;
    bool flag = false;
   for(auto & i :line_Of_File) {
       if(i==section) {
           if (i[0] == '#' || tmp[0] == '[')
               continue;
           if (i == param_input) {
               cout << "Parameter found!" << endl;
               parameter = tmp;
           } else
               parameter = "not found";
        }
       }
    return parameter;
}

void ReadFileIni::setSection(const string &sec, string &file) {
    File_in_output.open(file,std::ios::app);
    ostream os(&File_in_output);
    os << "\n" << sec;

}

void ReadFileIni::setParameter(string &param,string section) {
    ostream os(&File_in_output);


}
