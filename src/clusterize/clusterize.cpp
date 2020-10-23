#include "clusterize.hpp"

namespace cluster
{

    /*
    **  Clusterize(): build separated cloud points with cluster method.
    **      It means that if Micmac couldn't build the cloud with the entire set,
    **      We split it at the unlinkable image of the set, and proceed to build
    **      two clouds separately.
    */

    int clusterize(std::string cur_path, Option opt)
    {
        exec::execTapioca(cur_path, opt);
        exec::execTapas(cur_path, opt);
        // run Tapas and log return in tapas.log

        // if tapas failed with image error infos, split set
        // and call recursively in two set.

        // if works, run apericloud or forest.
        return 0;
    }


}
