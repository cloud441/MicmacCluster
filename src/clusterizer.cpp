#include "clusterizer.hpp"

/*
**  cloudBuilding(): Build all of the cloud of the data set.
**          This function is a wrapper on clusterize(), that is
**          the main algorithm of the project.
*/
static int cloudBuilding(Option opt)
{
    //Vectorize the set and send to clusterize

    cluster::clusterize(opt.dirname_get(), opt);

    return 0;
}



int main(int argc, char **argv)
{
    Option opt = Option(argc, argv);
    if (opt.isHelp_get())
        return 0;

    return cloudBuilding(opt);
}
