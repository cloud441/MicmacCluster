#include "exec_cmd.hpp"

namespace exec
{

    void execTapioca()
    {
        pid_t pid;
        int status;

        if ((pid = fork()) < 0)
        {
            std::cerr << "The tapioca command fork failed." << std::endl;
            exit(1);
        }
        if (!pid)
        {
            char *args[7] = { "mm3d", "Tapioca", "MulScale", "../data/.*JPG", "600", "1500", NULL };
            execvp("mm3d", args);
        }
        else
            while (wait(&status) != pid);
    }

}
