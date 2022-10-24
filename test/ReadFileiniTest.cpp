//
// Created by Alessandro on 19/04/2022.
//
#include "gtest/gtest.h"

#include "../ReadfileIni.h"

TEST(ReadFileIni,defaultreadSection){
    string name_file_ini="test.ini";
    ReadFileIni test_file_ini;
    ASSERT_TRUE(test_file_ini.OpenFileIni(name_file_ini));
    ASSERT_EQ("[section1]",test_file_ini.readSection("[section1]"));
}

TEST(ReadFileIni,readSectionfault){
    string name_file_ini="test.ini";
    ReadFileIni test_file_ini;
    ASSERT_TRUE(test_file_ini.OpenFileIni(name_file_ini));
    ASSERT_EQ("not found",test_file_ini.readSection("[section5]"));
}

TEST(ReadFileIni,defaultreadParameter){
    string name_file_ini="test.ini";
    ReadFileIni test_file_ini;
    ASSERT_TRUE(test_file_ini.OpenFileIni(name_file_ini));
    ASSERT_EQ("parameter2=value2",test_file_ini.readParameter("parameter2=value2","[section1]"));
}
TEST(ReadFileIni,readParameterfault){
    string name_file_ini="test.ini";
    ReadFileIni test_file_ini;
    ASSERT_TRUE(test_file_ini.OpenFileIni(name_file_ini));
    ASSERT_EQ("not found",test_file_ini.readParameter("parameter3=value3","[section1]"));
}