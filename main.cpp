/*
* File Created by Alessandro Bardossi
*
*/
#include "file.h"
#include "version.h"

using namespace std;

/*
 * ReadFileIni::OpenFileIni(string s)
 * apre il file specificato nel parametro nameOfFileinput
 */
bool ReadFileIni::OpenFileIni(string name_of_file_input) {
    string str(name_of_file_input);
    string fileExt = name_of_file_input.substr(name_of_file_input.find_last_of(".") + 1);
        if (fileExt!= "ini") {
            cout << "Error extension file" << endl;
            return false;
        }
     File_in_input.open(name_of_file_input);
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

/*
 * main function
 */

int main() {
    string name_file_ini;
    cout << "File ini version: " << VERSION << endl;

    cout << "Insert a name_file_ini of file ini" << endl;
    cin >> name_file_ini;
    ReadFileIni file_ini;
    if(!file_ini.OpenFileIni(name_file_ini))
    {
       cout << "Some errors occured!"<<endl;
       return 2;
    }
    file_ini.ReadOpenFile();
    file_ini.VideoVisualize();
    file_ini.SaveOpenFile(name_file_ini);
    return 0;

}
