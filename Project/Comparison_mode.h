#pragma once
#include "Sorting_Algorithm.h"
#include "Algorithm_Mode.h"

using List = std::vector<int>;
//comparison mode
struct CM{
    //output parameter in comparison mode
    void sort_factors(List& arr, int argc, char**argv);
    void Command_4(int argc, char** argv);
    void Command_5(int argc, char** argv);
};
