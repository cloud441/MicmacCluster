#include "clusterizer.hpp"

/*
**  cloudBuilding(): Build all of the cloud of the data set.
**          This function is a wrapper on clusterize(), that is
**          the main algorithm of the project.
*/
static int cloudBuilding(Option opt)
{
    //Vectorize the set and send to clusterize
    DIR* directory;
    struct dirent *entry;
    std::vector<std::string> set;
    if (!(directory = opendir(opt.dirname_get().c_str())))
    {
        std::cerr << "Directory name: " << "'" << opt.dirname_get() << "'"
                  << " is a wrong location" << std::endl;
        return 1;
    }

    while((entry = readdir(directory)))
    {
        if (entry->d_type == DT_REG)
            set.push_back(std::string(entry->d_name));
    }

    cluster::clusterize(set, opt);

    closedir(directory);
    return 0;
}



int main(int argc, char **argv)
{
    Option opt = Option(argc, argv);
    if (opt.is_help_get())
        return 0;

    return cloudBuilding(opt);
}
