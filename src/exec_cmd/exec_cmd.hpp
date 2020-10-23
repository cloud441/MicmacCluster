#pragma once

#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <string>
#include <cstring>
#include <fcntl.h>

#include "opt_parser.hpp"

#define STDOUT 1
#define CMD_OVERTIME 180  //If a command execution is longer than 3min, it stops and is considered as error.

namespace exec
{

    void execTapioca(std::string cur_path, Option opt);
    void execTapas(std::string cur_path, Option opt);
    void execApericloud();

};
