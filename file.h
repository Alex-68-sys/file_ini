//
// Created by Alessandro on 06/06/2021.
//

#ifndef FILE_INI_FILE_H
#define FILE_INI_FILE_H
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


class leggi_file{
public:
    leggi_file() {};
    ~leggi_file() { };
    bool apri(string);
    void leggi();
    int stampa();

private:
    fstream in;
    vector<string> mat;

};


#endif //FILE_INI_FILE_H
