#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "opt_parser.hpp"
#include "exec_cmd.hpp"

namespace cluster
{

    int clusterize(std::vector<std::string> set, Option opt);

};
