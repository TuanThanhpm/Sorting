#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Sorting_Algorithm.h"
#include "NoOFComparisons.h"

using List = std::vector<int>;

struct AM{
    void Parameter_Of_Sorting(List arr,std::string sort_method);
	double Running_time(List arr, std::string sort_method);

    void Parameter_Of_Sorting_Comparison(List arr,std::string sort_method, long long int& count_compare);
	long long int Number_Of_Comparisons(List arr, std::string sort_method);
    
    void Mode(int argc, char** argv);
    void Algorithm_name(int argc, char** argv);
    int Input_size(int argc, char** argv);
    void Input_order(List& arr, int argc, char** argv);
    void Given_Input_File(List& arr,int argc, char** argv);
    void Output_parameter(List& arr,int argc, char** argv);
    void Command_1(int argc, char** argv);
    void Command_2(int argc, char** argv);
    void Command_3(int argc, char** argv);
};
