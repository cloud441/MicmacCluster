#pragma once

#include <string>

class Option
{
    private:
        bool is_help_ = false;
        std::string dirname_ = "../data";

    public:
        Option(int argc, char ** argv);

        bool is_help_get();
        std::string dirname_get();
};
