//
// Created by Alessandro on 05/04/2022.
//

#include <jconfig.h>
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

int ReadFileIni::saveFile(const string& nameFileOutput) {
    int flag=0;
    File_in_output.open (nameFileOutput, std::ios::out);
    ostream os(&File_in_output);
    for(auto & i : line_Of_File)
        os << i << "\n";
    cout <<"File Saved!"<<endl;
    flag=1;
    File_in_output.close();
    return flag;
}

string ReadFileIni::readSection(const string &section_input) const{
    string tmp;
    string section;
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
    if(section=="not found")
        throw runtime_error("error");
    return section;
}

string ReadFileIni::readParameter(const string &param_input,const string &section) const {
    string j;
    string parameter;
    boolean flag= true;
    int k=0;
    for(auto & i : line_Of_File) {
         if (i == section) {
             int k2=k;
             while (flag) {
                 j = line_Of_File[k2];
                 if (j == "#") {
                     parameter="";
                     flag=false;
                 }
                 if (j == param_input) {
                     //cout << "Parameter found!" << endl;
                     parameter = j;
                     flag=false;
                 } else
                     parameter="not found";
             k2++;
             }

         }
         else
            k++;
    }
    if(parameter=="not found")
        throw runtime_error("error");
    return parameter;
}

bool ReadFileIni::setSection(const string &sec) {
    vector<string>::iterator tmp;
    bool success=false;
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
        line_Of_File.insert(tmp, "#");
        line_Of_File.insert(tmp + 1, sec);
        cout << "insert ok" << endl;
        success=true;
    }
    else {
        cout << "section already exist!" << endl;
        success=false;
    }
    return success;
}

bool ReadFileIni::setParameter(const string &param, const string &section) {
    vector<string>::iterator tmp;
    bool success=false;
    tmp=line_Of_File.begin();
    for(auto &i:line_Of_File) {
        if (i == section) {
            line_Of_File.insert(tmp + 1, param);
            success=true;
            break;
        }else{
            tmp++;
            success=false;
        }
    }
    if(success)
        cout <<"found"<< endl;
    else
        cout <<"not found" << endl;

    return success;
}
