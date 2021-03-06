#include "parser.hpp"


namespace parse
{
    /*
    **  isLogFailure(): Parse the filename logfile to match the error case.
    **      The idea is that MicMac command output finish by a '*' line if
    **      no error occured.
    */
    bool isLogFailure(std::string filename)
    {
        std::string line;
        std::string line_tmp;
        std::ifstream stream;
        stream.open(filename);
        if (!stream.is_open())
        {
            std::cerr << "Error in loading: " << filename << std::endl;
            exit(1);
        }
        while (std::getline(stream, line_tmp))
            line = line_tmp;

        stream.close();
        return (line[0] != '*');
    }



    /*
    **  imageToSplit(): parse the logfile to find the unlinked image name.
    */
    std::string imageToSplit(std::string logfile)
    {
        std::string line;
        std::ifstream stream;
        stream.open(logfile);

        if(!stream.is_open())
        {
            std::cerr << "Error in loading: " << logfile << std::endl;
            exit(1);
        }

        while (std::getline(stream, line) && line.substr(0, 3) != "NUM");


        stream.close();
        return line.substr(line.find_last_of(" ") + 1);
    }

} // namespace parse
