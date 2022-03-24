/*
* File Created BY Alessandro Bardossi
*
*/
#include "file.h"
#include "version.h"

using namespace std;

/*
 * Read_File_INI::Open_File(string s)
 * apre il file specificato nel parametro name
 */
bool Read_File_INI::Open_File(string) {
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
 * Read_File_INI::Read_Open_File()
 * legge il file aperto
 */
void Read_File_INI::Read_Open_File() {

    string buffer;
    while(getline(File_in_input, buffer))
        line_Of_File.push_back(buffer);
    File_in_input.close();
}

/*
 * Read_File_INI::stampa()
 * Video_Visualize il file a video
 */
int Read_File_INI::Video_Visualize(){
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
        Read_File_INI *file_ini_text;
        file_ini_text = new Read_File_INI();
        if(!file_ini_text->Open_File(argv[1]))
        {
            cout << "Some errors occured!"<<endl;
            return 2;
        }
        file_ini_text->Read_Open_File();
        file_ini_text->Video_Visualize();
        delete file_ini_text;
        return 0;
    }
}
