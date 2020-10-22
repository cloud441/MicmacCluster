#pragma once

#include <string>

class Option
{
    private:
        bool is_help_ = false;

    public:
        Option(int argc, char ** argv);

        bool is_help_get();
};
