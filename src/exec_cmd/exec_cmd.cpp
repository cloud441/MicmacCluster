#include "exec_cmd.hpp"

namespace exec
{

    void execTapioca(std::string cur_path, Option opt)
    {
        pid_t pid;
        int status;
        bool error = false;

        if ((pid = fork()) < 0)
        {
            std::cerr << "The tapioca command fork failed." << std::endl;
            exit(1);
        }
        if (!pid)
        {
            char pattern[cur_path.size() + 8];
            strcpy(pattern, (cur_path + "/.*JPG").c_str());

            char *args[7] = { "mm3d", "Tapioca", (char *)opt.detectMode_get().c_str(),
                            pattern, NULL, NULL, NULL };
            if (opt.detectMode_get() == "MulScale")
            {
                args[4] = "600";
                args[5] = "1500";
            }
            else if (opt.detectMode_get() == "All")
                args[4] = "1500";
            else
            {
                args[3] = NULL;
                error = true;
            }

            execvp("mm3d", args);
        }
        else
            while (wait(&status) != pid);

        if (error)
            exit(2);
    }

}
