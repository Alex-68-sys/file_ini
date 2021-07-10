#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "file.h"

using namespace std;

/*
 * leggi_file::apri(string s)
 * apre il file specificato nel parametro s
 */
void leggi_file::apri(string s) {
    in.open(s);
}
/*
 * leggi_file::leggi()
 * legge il file aperto e restituisce l'indice di lettura
 */
void leggi_file::leggi() {

    string buffer;
    while(getline(in,buffer))
        mat.emplace_back(buffer);
}

/*
 * leggi_file::stampa()
 * stampa il file a video
 */
int leggi_file::stampa(){
    int ciclo;

    for(ciclo=0; ciclo < mat.size(); ciclo++) {
            cout << " - " << mat[ciclo] << endl;
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
        file_text->apri(argv[1]);
        file_text->leggi();
        file_text->stampa();
        delete file_text;
        return 0;
    }
}
