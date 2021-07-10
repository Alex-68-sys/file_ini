//
// Created by Alessandro on 06/06/2021.
//

#ifndef FILE_INI_FILE_H
#define FILE_INI_FILE_H
using namespace std;
#include <vector>

class leggi_file{
public:
    leggi_file() = default;
    ~leggi_file() = default;
    void apri(string);
    void leggi();
    int stampa();

private:
    fstream in;
    vector<string> mat;

};


#endif //FILE_INI_FILE_H
