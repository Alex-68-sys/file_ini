//
// Created by Alessandro on 05/04/2022.
//

#include "ReadFileIni.h"

using namespace std;

/*
 * ReadFileIni::OpenFileIni(string s)
 * apre il file specificato nel parametro nameOfFileinput
 */
bool ReadFileIni::OpenFileIni(const string& nameFileInput) {
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

void ReadFileIni::saveFile(const string& nameFileOutput) {

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
        if (i[0] == '#' || i.empty())
            continue;
        if (i == section_input) {
            //cout << "Section found!" << endl;
            section = i;
            break;
        }else
            section="not found";
    }
    return section;
}

string ReadFileIni::readParameter(const string &param_input,string section) {
   for(auto & i :line_Of_File) {
       if (i == section) {
           for (auto &i: line_Of_File){
               if (i == param_input) {
                   cout << "Parameter found!" << endl;
                   parameter = i;
                   break;
               } else
                   parameter = "not found";
       }
   }
       }
    return parameter;
}

void ReadFileIni::setSection(const string &sec) {
    vector<string>::iterator tmp;
    bool flag=false;
    tmp=line_Of_File.begin();
    for(auto & i: line_Of_File){
        if(i==sec){
            flag=true;
            break;
        }
        tmp++;
    }
    if(flag== false) {
        line_Of_File.insert(tmp, " ");
        line_Of_File.insert(tmp + 1, sec);
        cout << "insert ok" << endl;
    }
    else
        cout << "section already exist!"<<endl;

}

void ReadFileIni::setParameter(const string &param, string section) {
    vector<string>::iterator tmp;
    tmp=line_Of_File.begin();
    for(auto &i:line_Of_File){
        if(i==section)
            line_Of_File.insert(tmp+1,param);
        else
            tmp++;
    }


}
