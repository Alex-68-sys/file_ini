//
// Created by Alessandro on 05/04/2022.
//

#include "ReadFileIni.h"

using namespace std;

/*
 * ReadFileIni::OpenFileIni(string s)
 * apre il file specificato nel parametro nameOfFileinput
 */
bool ReadFileIni::OpenFileIni(string namefile) {
    string str(namefile);
    string fileExt = namefile.substr(namefile.find_last_of(".") + 1);
    if (fileExt!= "ini") {
        cout << "Error extension file" << endl;
        return false;
    }
    File_in_input.open(namefile);
    return true;

}
/*
 * ReadFileIni::ReadOpenFile()
 * legge il file aperto
 */
void ReadFileIni::ReadOpenFile() {

    string buffer;
    while(getline(File_in_input, buffer))
        line_Of_File.push_back(buffer);
    File_in_input.close();
}

/*
 * ReadFileIni::stampa()
 * VideoVisualize il file a video
 */
int ReadFileIni::VideoVisualize(){
    int cicle;
    for(cicle=0; cicle < line_Of_File.size(); cicle++) {
        cout << " " << line_Of_File[cicle] << endl;
    }
    return 0;
}

void ReadFileIni::SaveOpenFile(string name_of_file_output) {

    File_in_output.open (name_of_file_output, std::ios::out);
    ostream os(&File_in_output);
    for(auto & i : line_Of_File)
        os << i << "\n";
    cout <<"File Saved!"<<endl;
    File_in_output.close();
}
