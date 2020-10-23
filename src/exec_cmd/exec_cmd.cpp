#include "exec_cmd.hpp"

namespace exec
{

    /*
    **  openLogFile():Open a file for logging the command execution.
    **      The function also switch file descriptor of stdout and the file
    **      to allow redirecting command output to the file.
    */
    static int openLogFile(char *filename)
    {
        int fd = open(filename, O_WRONLY);
        if (fd == -1)
        {
            std::cerr << "Error in loading log file: '"
                      << filename << "'" << std::endl;
            exit(1);
        }

        if (dup2(fd, STDOUT) == -1)
        {
            std::cerr << "Error in duplicating file descriptor with: '"
                      << filename << "'" << std::endl;
            exit(1);
        }
        return fd;
    }


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
            int fd = openLogFile("../log/tapioca.log");
            execvp("mm3d", args);
            close(fd);
        }
        else
            while (wait(&status) != pid);

        if (error)
            exit(2);
    }

}
