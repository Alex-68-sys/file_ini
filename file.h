//
// Created by Alessandro on 06/06/2021.
//

#ifndef FILE_INI_FILE_H
#define FILE_INI_FILE_H
using namespace std;
#include <vector>

class leggi_file{
public:
    leggi_file() ;
    ~leggi_file();
    int apri(char * f,const char * m);
    int leggi();
    int stampa(int value);

private:
    FILE *fp;
    vector<string> mat;

};


#endif //FILE_INI_FILE_H
