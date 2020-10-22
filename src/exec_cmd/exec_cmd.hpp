#pragma once

#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <string>
#include <cstring>

#include "opt_parser.hpp"

namespace exec
{

    void execTapioca(std::string cur_path, Option opt);
    void execTapas();
    void execApericloud();

};
