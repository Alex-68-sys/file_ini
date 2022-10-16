//
// Created by Alessandro on 19/04/2022.
//
#include "gtest/gtest.h"

#include "../ReadfileIni.h"

TEST(ReadFileIni,defaultreadSection){
    string name_file_ini="test.ini";
    ReadFileIni file_ini;
    ASSERT_EQ("[section3]",file_ini.readSection("[section3]"));
}