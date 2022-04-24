/*
* File Created by Alessandro Bardossi
*
*/

/*
 * main function
 */
#include "ReadFileIni.h"
#include "version.h"

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
    file_ini.readFile();
    file_ini.VideoVisualize();
    file_ini.saveFile(name_file_ini);
    return 0;

}
