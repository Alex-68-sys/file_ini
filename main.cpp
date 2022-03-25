/*
* File Created BY Alessandro Bardossi
*
*/
#include "file.h"
#include "version.h"

using namespace std;

/*
 * ReadFileIni::OpenFileIni(string s)
 * apre il file specificato nel parametro nameOfFileinput
 */
bool ReadFileIni::OpenFileIni(string nameOfFileinput) {
    string str(nameOfFileinput);
    string fileExt = nameOfFileinput.substr(nameOfFileinput.find_last_of(".") + 1);
        if (fileExt!= "ini") {
            cout << "Error extension file" << endl;
            return false;
        }
     File_in_input.open(nameOfFileinput);
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

void ReadFileIni::SaveOpenFile(string name) {

    File_in_output.open (name,std::ios::out);
    ostream os(&File_in_output);
    for(int cicle=0;cicle<line_Of_File.size();cicle++)
      os << line_Of_File[cicle]<<"\n";
    File_in_output.close();
}

/*
 * main function
 */

int main(int argc, char **argv) {
    cout << "File ini version: " << VERSION << endl;
    if(argv[1]==nullptr || argc==0){
        cout <<"no parameter....."<<endl;
        cout <<"use file_ini file_in_input.ini" <<endl;
        return 1;
    }else {
        ReadFileIni *file_ini;
        file_ini = new ReadFileIni();
        if(!file_ini->OpenFileIni(argv[1]))
        {
            cout << "Some errors occured!"<<endl;
            return 2;
        }
        file_ini->ReadOpenFile();
        file_ini->VideoVisualize();
        file_ini->SaveOpenFile(argv[1]);
        delete file_ini;
        return 0;
    }
}
