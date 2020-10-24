#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <dirent.h>

#define MIN_FILE_NB 4


namespace fileManager
{

    bool verifyDir(std::string dirname);
    void moveFiles(std::string split_image, std::string dirname);
    void moveCloud(std::string dirname, std::string output_dirname);
    bool isBoundaryImage(std::string dirname, std::string image);

}; // namespace fileManager
