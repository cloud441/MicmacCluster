#include "file_manager.hpp"

namespace fileManager
{

    /*
    **  verifyDir(): verify that the directory matchs prerequites of clusterizing.
    **      prerequites:
    **          - the directory exist
    **          - it contain at least 5 images.
    */
    bool verifyDir(std::string dirname)
    {
        struct dirent *entry;
        DIR * dir = opendir(dirname.c_str());
        int nb_file = 0;

        if (!dir)
        {
            std::cerr << "Error in directory name of recursive clusterizing." << std::endl;
            return false;
        }

        while((entry = readdir(dir)) != NULL)
        {
            if (entry->d_type == DT_REG)
            {
                std::string filename = std::string(entry->d_name);
                if (filename.substr(filename.find_last_of(".") + 1) == "JPG")
                    nb_file++;
            }
        }

        return (nb_file >= MIN_FILE_NB);
    }

} // namespace fileManager
