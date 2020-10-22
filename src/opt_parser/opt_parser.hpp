#pragma once

#include <string>

class Option
{
    private:
        bool isHelp_ = false;
        std::string dirname_ = "../data";
        std::string detectMode_ = "MulScale";
        std::string matchingMode_ = "FraserBasic";

    public:
        Option(int argc, char ** argv);

        bool isHelp_get();
        std::string dirname_get();
        std::string detectMode_get();
        std::string matchingMode_get();
};
