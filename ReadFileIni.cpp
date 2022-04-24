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
    return true;

}
/*
 * ReadFileIni::readFile()
 * legge il file aperto
 */
void ReadFileIni::readFile() {

    string buffer;
    while(getline(File_in_input, buffer))
        line_Of_File.push_back(buffer);
    File_in_input.close();
}


void ReadFileIni::saveFile(string& nameFileOutput) {

    File_in_output.open (nameFileOutput, std::ios::out);
    ostream os(&File_in_output);
    for(auto & i : line_Of_File)
        os << i << "\n";
    cout <<"File Saved!"<<endl;
    File_in_output.close();
}

vector<string> ReadFileIni::readSection(string& section_input) {
    string tmp;
    while(getline(File_in_input,tmp)){
        if (tmp[0]=='['){
            if(tmp==section_input){
                section.push_back(tmp);
            }
        }
    }
    return section;
}

vector<string> ReadFileIni::readParameter(string& param) {
    string tmp;
    while(getline(File_in_input,tmp)){
        if(tmp[0]=='['){
            int i=1;
            while (tmp[i]!=']')
                i++;
        }
        if(tmp==param) {
            parameter.push_back(tmp);
        }
    }
    return parameter;
}

void ReadFileIni::setSection(string& sec) {

}

void ReadFileIni::setParameter(string& param) {

}
