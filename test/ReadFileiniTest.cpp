//
// Created by Alessandro on 19/04/2022.
//
#include "gtest/gtest.h"

#include "../ReadfileIni.h"

TEST(ReadFileIni,defaultreadSection){
    string name_file_ini="test.ini";
    string section;
    ReadFileIni test_file_ini;
    ASSERT_TRUE(test_file_ini.OpenFileIni(name_file_ini));
    section=test_file_ini.readSection("[section1]");
    ASSERT_EQ("[section1]",section);
}

TEST(ReadFileIni,readSectionfault){
    string name_file_ini="test.ini";
    string section;
    ReadFileIni test_file_ini;
    ASSERT_TRUE(test_file_ini.OpenFileIni(name_file_ini));
    ASSERT_EQ("not found",test_file_ini.readSection("[section5]"));
}

