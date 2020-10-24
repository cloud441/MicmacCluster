#pragma once


#include <iostream>
#include <string>
#include <fstream>

namespace parse
{

    bool isLogFailure(std::string filename);
    std::string imageToSplit(std::string logfile);

}; // namespace parse
