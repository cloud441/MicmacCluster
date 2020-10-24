#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>

#define MIN_FILE_NB 5

namespace fileManager
{

    bool verifyDir(std::string dirname);
    void copyFiles(std::string split_image, std::string dir, bool is_set_1);

}; // namespace fileManager
