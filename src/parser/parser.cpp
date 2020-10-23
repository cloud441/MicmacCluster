#include "parser.hpp"


namespace parse
{

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
        while(std::getline(stream, line_tmp))
            line = line_tmp;

        stream.close();
        return (line[0] != '*');
    }

} // namespace parse
