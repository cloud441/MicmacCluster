#pragma once

#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <string>
#include <cstring>
#include <fcntl.h>

#include "opt_parser.hpp"

#define STDOUT 1

namespace exec
{

    void execTapioca(std::string cur_path, Option opt);
    void execTapas();
    void execApericloud();

};
