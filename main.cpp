/*
* File Created BY Alessandro Bardossi
*
*/
#include "file.h"
#include "version.h"

using namespace std;

/*
 * ReadFileIni::OpenFileIni(string s)
 * apre il file specificato nel parametro name
 */
bool ReadFileIni::OpenFileIni(string) {
    string str(name);
    string fileExt = name.substr(name.find_last_of(".") + 1);
        if (fileExt!= "ini") {
            cout << "Error extension file" << endl;
            return false;
        }
     File_in_input.open(name);
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
    int ciclo;

    for(ciclo=0; ciclo < line_Of_File.size(); ciclo++) {
            cout << " " << line_Of_File[ciclo] << endl;
    }
    return 0;
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
        ReadFileIni *file_ini_text;
        file_ini_text = new ReadFileIni();
        if(!file_ini_text->OpenFileIni(argv[1]))
        {
            cout << "Some errors occured!"<<endl;
            return 2;
        }
        file_ini_text->ReadOpenFile();
        file_ini_text->VideoVisualize();
        delete file_ini_text;
        return 0;
    }
}
