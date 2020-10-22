#include "opt_parser.hpp"

#include <boost/program_options.hpp>
#include <iostream>


using namespace boost::program_options;

Option::Option(int argc, char ** argv)
{
    try {
        options_description desc("Allowed options");
        desc.add_options()("help,h", "show usage");

        variables_map map;
        store(parse_command_line(argc, argv, desc), map);

        if (map.count("help"))
        {
            is_help_ = true;
            std::cout << desc << std::endl;
        }

    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


bool Option::is_help_get()
{
    return is_help_;
}

std::string Option::dirname_get()
{
    return dirname_;
}
