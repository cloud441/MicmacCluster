#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "opt_parser.hpp"
#include "exec_cmd.hpp"
#include "parser.hpp"
#include "file_manager.hpp"

namespace cluster
{

    int clusterize(std::string cur_path, Option opt);

}; //namespace cluster
