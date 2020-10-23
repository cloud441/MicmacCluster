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
        if (!fileManager::verifyDir(cur_path))
            return 0;

        exec::execTapioca(cur_path, opt);
        exec::execTapas(cur_path, opt);

        if (!parse::isLogFailure("../log/tapas.log"))
        {
            //std::string split_image = parse::imageToSplit("../log/tapas.log");


            std::string subset_1 = cur_path + '/' + "set-1";
            std::string subset_2 = cur_path + '/' + "set-2";

            mkdir(subset_1.c_str(), ACCESSPERMS);
            mkdir(subset_2.c_str(), ACCESSPERMS);

            //fileManager::copyFiles(split_image, subset_1, true);
            //fileManager::copyFiles(split_image, subset_2, false);

            //int return_val_1 = clusterize(subset_1, opt);
            //int return_val_2 = clusterize(subset_2, opt);
            //return (return_val_1 || return_val_2);
        }
        else
            exec::execAperiCloud(cur_path, opt);

        return 0;
    }


} //namespace cluster
