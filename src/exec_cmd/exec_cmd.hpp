#pragma once

#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string>
#include <cstring>
#include <fcntl.h>

#include "opt_parser.hpp"

#define STDOUT 1
#define CMD_OVERTIME 300
#define CMD_OVERTIME_TAPIOCA 5400

namespace exec
{

    void execTapioca(std::string cur_path, Option opt);
    void execTapas(std::string cur_path, Option opt);
    void execAperiCloud(std::string cur_path, Option opt);

}; // namespace exec
