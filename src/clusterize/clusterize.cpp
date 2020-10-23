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

        if (parse::isLogFailure("../log/tapas.log"))
        {
            std::string split_image = parse::imageToSplit("../log/tapas.log");

            struct dirent *entry;
            DIR * dir = opendir(cur_path);

            if (!dir)
            {
                std::cerr << "Error in directory name of recursive clusterizing." << std::endl;
                return 1;
            }

            //std::string subset_1 = cur_path + '/' + "set-1";
            //std::string subset_2 = cur_path + '/' + "set-2";
            //exec::execMkdir(subset_1);
            //exec::execMkdir(subset_2);

            //copyFiles(split_image, subset_1, true);
            //copyFiles(split_image, subset_2, false);

            //int return_val_1 = clusterize(subset_1, opt);
            //int return_val_2 = clusterize(subset_2, opt);
            //return (return_val_1 || return_val_2);
        }
        else
            exec::execAperiCloud(cur_path, opt);

        return 0;
    }


} //namespace cluster
