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

    /*cout << "Insert a name of file ini" << endl;
    cin >> name_file_ini;*/
    name_file_ini="test.ini";
    ReadFileIni file_ini;
    if(!file_ini.OpenFileIni(name_file_ini))
    {
       cout << "Some errors occurred!"<<endl;
       return 2;
    }
    string section,param;
    //file_ini.readFile();
    section=file_ini.readSection("[section3]");
    cout <<"section: " << section << endl;
    param=file_ini.readParameter("parameter2=value2","[section2]");
    cout <<"parameter: " << param << endl;
    //file_ini.setSection("[section 4]", name_file_ini);
    //file_ini.saveFile(name_file_ini);
    return 0;

}
