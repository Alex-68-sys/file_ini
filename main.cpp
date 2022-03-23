/*
* File Created BY Alessandro Bardossi
*
*/
#include "file.h"

using namespace std;

/*
 * leggi_file::apri(string s)
 * apre il file specificato nel parametro name
 */
bool leggi_file::apri(const string name) {
    string str(name);
    string fileExt = name.substr(name.find_last_of(".") + 1);
        if (fileExt!= "ini") {
            cout << "Error extension file" << endl;
            return false;
        }
     in.open(name);
     return true;

}
/*
 * leggi_file::leggi()
 * legge il file aperto
 */
void leggi_file::leggi() {

    string buffer;
    while(getline(in,buffer))
        mat.push_back(buffer);
}

/*
 * leggi_file::stampa()
 * stampa il file a video
 */
int leggi_file::stampa(){
    int ciclo;

    for(ciclo=0; ciclo < mat.size(); ciclo++) {
            cout << " " << mat[ciclo] << endl;
    }
    return 0;
}

/*
 * main function
 */

int main(int argc, char **argv) {
    if(argv[1]==nullptr || argc==0){
        cout <<"no parameter....."<<endl;
        return 1;
    }else {
        leggi_file *file_text;
        file_text = new leggi_file();
        if(!file_text->apri(argv[1]))
        {
            cout << "Some errors occured!"<<endl;
            return 2;
        }
        file_text->leggi();
        file_text->stampa();
        delete file_text;
        return 0;
    }
}
