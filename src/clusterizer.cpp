#include "clusterizer.hpp"

/*
**  cloudBuilding(): Build all of the cloud of the data set.
**          This function is a wrapper on clusterize(), that is
**          the main algorithm of the project.
*/
static int cloudBuilding(Option opt)
{
    mkdir("../outputCloud", ACCESSPERMS);
    std::string boundary_dirname = opt.dirname_get() + "/boundary_error_set";
    mkdir(boundary_dirname.c_str(), ACCESSPERMS);
    return cluster::clusterize(opt.dirname_get(), opt);
}



int main(int argc, char **argv)
{
    Option opt = Option(argc, argv);
    if (opt.isHelp_get())
        return 0;

    return cloudBuilding(opt);
}
