#include <iostream>
#include <cstdio>
#include <cstddef>
#include "file.h"

using namespace std;

/*****
 * leggi_file()
 * Costruttore
 */
leggi_file::leggi_file(){
    //mat = new string[30];
}

/*****
 * ~leggi_file()
 * Distruttore
 */
leggi_file::~leggi_file(){
    cout << "Distruttore, libera la memoria dell'array!";
    //delete mat;
}


int leggi_file::apri(char * f,const char * m) {
    fp=fopen(f,m);
    if(fp==NULL) {
        cout << "error opening file" << endl;
        return 1;
    }else{
        cout << "file opened\n" << endl;
        return 0;
    }

}

int leggi_file::leggi() {

    int count=0;
    char buffer[200];
    while(!feof(fp)){
        cout << "lettura...." << endl;
        fscanf(fp,"%s",buffer);
        mat.push_back(buffer);
        count++;

    }
    fclose(fp);
    return count;
}

int leggi_file::stampa(int value){
    int ciclo;
    cout << "stampa a video... "<< endl;

    for(ciclo=0; ciclo < value; ciclo++) {
            cout << " - " << mat[ciclo] << endl;
            //free(buffer[ciclo]);
    }
    return 0;
}



int main(int argc, char **argv) {
    if(argv[1]==NULL){
        cout <<"no parameter....."<<endl;
        return 1;
    }else {
        const char *m = "r+";
        leggi_file *o;
        o = new leggi_file();
        int i;
        o->apri(argv[1], m);
        i = o->leggi();
        cout << "\nNumero righe: " << i << "\n";
        o->stampa(i);
        std::cout << "\nall done!" << std::endl;
        delete o;
        return 0;
    }
}
