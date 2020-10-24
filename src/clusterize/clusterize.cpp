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
        {
            std::cout << "Not enough image in cluster: " << cur_path << std::endl;
            return 1;
        }

        std::cout << "\nTapioca is running in set " << cur_path << "\n...\n";
        exec::execTapioca(cur_path, opt);
        std::cout << "Tapioca finished.\nTapas is running in set " << cur_path << "\n...\n";
        exec::execTapas(cur_path, opt);
        std::cout << "Tapas finished." << "\n";

        if (parse::isLogFailure("../log/tapas.log"))
        {
            std::string split_image = parse::imageToSplit("../log/tapas.log");
            if (fileManager::isBoundaryImage(cur_path, split_image))
            {
                std::cout << "Boundary image in cluster: " << cur_path << '\n';
                return 1;
            }

            std::string subset_1 = cur_path + '/' + "set-1";
            std::string subset_2 = cur_path + '/' + "set-2";

            mkdir(subset_1.c_str(), ACCESSPERMS);
            mkdir(subset_2.c_str(), ACCESSPERMS);

            fileManager::moveFiles(split_image, cur_path);

            int return_val_1 = clusterize(subset_1, opt);
            int return_val_2 = clusterize(subset_2, opt);
            return (return_val_1 || return_val_2);
        }
        else
        {
            std::cout << "AperiCloud is running..." << "\n";
            exec::execAperiCloud(cur_path, opt);
            fileManager::moveCloud(cur_path, "../outputCloud");
            std::cout << "AperiCloud finished." << std::endl;
        }

        return 0;
    }


} //namespace cluster
