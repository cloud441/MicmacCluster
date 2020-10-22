#include "clusterizer.hpp"


static int cloudBuilding(Option opt)
{
    //Vectorize the set and send to clusterize
    cluster::clusterize(std::vector<std::string>(), opt);
    return 0;
}



int main(int argc, char **argv)
{
    Option opt = Option(argc, argv);
    if (opt.is_help_get())
        return 0;

    return cloudBuilding(opt);
}
