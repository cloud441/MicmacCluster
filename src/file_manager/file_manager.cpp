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



    /*
    **  moveFiles(): mov all the images from dirname into the two subset cluster.
    **      Because of a alphabetical order in image listing, we separate the cluster
    **      by cutting at the split_image that raise an error.
    */
    void moveFiles(std::string split_image, std::string dirname)
    {
        struct dirent **entry_list;
        int nb_file = scandir(dirname.c_str(), &entry_list, NULL, alphasort);
        bool is_set_one = false;

        if (nb_file == -1)
        {
            std::cerr << "Error in directory name of recursive clusterizing." << std::endl;
            return;
        }

        while(nb_file--)
        {
            if (entry_list[nb_file]->d_type == DT_REG)
            {
                std::string filename = std::string(entry_list[nb_file]->d_name);
                if (filename.substr(filename.find_last_of(".") + 1) == "JPG")
                {
                    std::string oldname = dirname + "/" + filename;
                    std::string subset = is_set_one ? "set-1" : "set-2";
                    std::string newname = dirname + "/" + subset + "/" + filename;

                    rename(oldname.c_str(), newname.c_str());

                    if (filename == split_image)
                        is_set_one = true;
                }
            }

            free(entry_list[nb_file]);
        }

        free(entry_list);
    }



    /*
    **  findNumberCloud(): numerate the output cloud file according to the dirname.
    */
    static int findNumberCloud(std::string dirname)
    {
        if (dirname == "../data")
            return 0;

        int nb_cloud = 0;

        char *token = strtok((char *)dirname.c_str(), "/");
        token = strtok(NULL, "/");

        while ((token = strtok(NULL, "/")))
        {
            nb_cloud *= 10;
            if (std::string(token) == "set-1")
                nb_cloud += 1;
            else
                nb_cloud += 2;
        }

        return nb_cloud;
    }



    /*
    **  moveCloud(): Move the generated cloud into the outputCloud/ durectory.
    */
    void moveCloud(std::string dirname)
    {
        std::string old_path = dirname + "/" + "AperiCloud_Arbitrary.ply";
        int nb_cloud = findNumberCloud(dirname);
        std::string new_path = std::string("../outputCloud/") + "AperiCloud_cluster_" + std::to_string(nb_cloud) + ".ply";
        rename(old_path.c_str(), new_path.c_str());
    }



    /*
    **  firstImage(): Return the first cluster image name.
    */
    static std::string firstImage(std::string dirname)
    {
        struct dirent **entry_list;
        int nb_file = scandir(dirname.c_str(), &entry_list, NULL, alphasort);
        std::string first_image;

        if (nb_file == -1)
        {
            std::cerr << "Error in directory name of recursive clusterizing." << std::endl;
            exit(1);
        }

        while (nb_file--)
        {
            std::string filename = entry_list[nb_file]->d_name;
            if (entry_list[nb_file]->d_type == DT_REG
                    && filename.substr(filename.find_last_of(".") + 1) == "JPG")
            {
                first_image = filename;
            }

            free(entry_list[nb_file]);
        }
        free(entry_list);

        return first_image;
    }



    /*
    **  lastImage(): Return the last cluster image name.
    */
    static std::string lastImage(std::string dirname)
    {
        struct dirent **entry_list;
        int nb_file = scandir(dirname.c_str(), &entry_list, NULL, alphasort);
        std::string last_image;

        if (nb_file == -1)
        {
            std::cerr << "Error in directory name of recursive clusterizing." << std::endl;
            exit(1);
        }

        for (int i = 0; i < nb_file; i++)
        {
            std::string filename = entry_list[i]->d_name;
            if (entry_list[i]->d_type == DT_REG
                    && filename.substr(filename.find_last_of(".") + 1) == "JPG")
            {
                last_image = filename;
            }

            free(entry_list[i]);
        }
        free(entry_list);

        return last_image;
    }



    /*
    **  checkBoundaryImage(): check if the image in first or last into the cluster.
    **      This check is necessary to avoid border case in cluster split.
    */
    bool checkBoundaryImage(std::string dirname, std::string image)
    {
        std::string first_image = firstImage(dirname);
        std::string last_image = lastImage(dirname);

        return (last_image == image || first_image == image);
    }



    /*
    **  moveBoundaryImage(): move the boundary image into the special boundary_error_set directory.
    */
    void moveBoundaryImage(std::string dirname, std::string image)
    {
        std::string old_path = dirname + "/" + image;
        std::string new_path = "../data/boundary_error_set/" + image;
        rename(old_path.c_str(), new_path.c_str());
    }

} // namespace fileManager
