#include "opt_parser.hpp"

#include <boost/program_options.hpp>
#include <iostream>


using namespace boost::program_options;
/*
**  Option(): option class constructor, that parse the option into a set.
*/
Option::Option(int argc, char ** argv)
{
    try {
        options_description desc("Allowed options");
        desc.add_options()("help,h", "show usage")
                        ("detect,d", value<std::string>(), "mode of Tapioca detection")
                        ("matching,m", value<std::string>(), "mode of Tapas matching")
                        ("data", value<std::string>(), "Specify the location of data directory.\
                         By default, the location is set to '../data/'");

        variables_map map;
        store(parse_command_line(argc, argv, desc), map);

        if (map.count("detect"))
            detectMode_ = map["detect"].as<std::string>();

        if (map.count("matching"))
            matchingMode_ = map["matching"].as<std::string>();


        if (map.count("data"))
            dirname_ = map["data"].as<std::string>();

        if (map.count("help"))
        {
            isHelp_ = true;
            std::cout << desc << std::endl;
        }

    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


bool Option::isHelp_get()
{
    return isHelp_;
}

std::string Option::dirname_get()
{
    return dirname_;
}

std::string Option::detectMode_get()
{
    return detectMode_;
}

std::string Option::matchingMode_get()
{
    return matchingMode_;
}
