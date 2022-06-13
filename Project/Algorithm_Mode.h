#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "Sorting_Algorithm.h"
#include "NoOFComparisons.h"

using List = std::vector<int>;


struct AM{
    //Test
    /* int get_algorithm(std::string userAlg);
    func_ptr get_algorithm_address(int alg); */

    //Execute suitable function based on sort method which is cmdline argument
    void Parameter_Of_Sorting(List& arr,std::string sort_method);

    //Based on sorting algorithm to calculate time of executing function
	double Running_time(List& arr, std::string sort_method);

    //Execute suitable function based on sort method which is cmdline argument
    void Parameter_Of_Sorting_Comparison(List& arr,std::string sort_method,unsigned long long& count_compare);
    //Based on sorting algorithm to calculate the number of comparisons of executing function
	unsigned long long Number_Of_Comparisons(List& arr, std::string sort_method);
    
    //Input arguments
    void Mode(int argc, char** argv);
    void Algorithm_name(int argc, char** argv);
    int Input_size(int argc, char** argv);
    //Types of data
    void Input_order(List& arr, int argc, char** argv);
    //Get the data from the input file (txt file)
    void Given_Input_File(List& arr,int argc, char** argv);
    //Time or comparisons or both
    void Output_parameter(List& arr,std::string s, int argc, char** argv);

    //Writing file for cmd 1 2 3 5 - sorted array or generate input
    void Write_file_1(List arr, std::string FileName);

    //– Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
    void Command_1(int argc, char** argv);
    //– Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
    void Command_2(int argc, char** argv);
    //– Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
    void Command_3(int argc, char** argv);
};
