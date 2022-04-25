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

string ReadFileIni::readSection(string& section_input) {
    string tmp;
    while(getline(File_in_input,tmp)){
        if (tmp[0]=='['){
            if(tmp==section_input){
                cout << "Section found!" << endl;
                section=tmp;
            }
        }
        if(tmp[0] == '#' || tmp.empty())
            continue;
    }
    return section;
}

string ReadFileIni::readParameter(string& param_input) {
    string tmp;
    while(getline(File_in_input,tmp)){
        if(tmp[0]=='['){
           continue;
        }
        if(tmp[0] == '#' || tmp.empty())
            continue;
        if(tmp==param_input) {
            cout << "Parameter found!" << endl;
            parameter=tmp;
        }
    }
    return parameter;
}

void ReadFileIni::setSection(string& sec,string& Fileinoutput) {
    File_in_output.open (Fileinoutput, std::ios::out);
    ostream os(&File_in_output);
    string tmp;
   for(int i=0;i<line_Of_File.size();i++){
        if(line_Of_File[0]=="["){
            if(line_Of_File[i]!=sec) {
                os << sec;
                i--;
            }
        }else{
            os << line_Of_File[i];
        }
    }

}

void ReadFileIni::setParameter(string& param) {

}
