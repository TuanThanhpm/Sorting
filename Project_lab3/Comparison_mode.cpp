#include "Comparison_mode.h"

void CM::sort_factors(List& arr,int argc, char** argv){
    AM* am = nullptr;
    //Initialize virtual array
    List A, B, C, D;
    double time_1, time_2;
    //Calculate time of first sort
    A=arr;
    time_1 = am->Running_time(A,argv[2]);
    //Calculate time of second sort
    B=arr;
    time_2 = am->Running_time(B,argv[3]);

    int comp_1, comp_2;
    //Calculate the number of comparisons of first sort
    C=arr;
    comp_1= am->Number_Of_Comparisons(C,argv[2]);
    //Calculate the number of comparisons of second sort
    D=arr;
    comp_2 = am->Number_Of_Comparisons(D,argv[3]);

    //Display running time and the number of comparisons in both sorting algorithm
    std::cout <<"Running time: " << time_1 << " | " << time_2 << std::endl;
    std::cout<<"Comparisons: "<<comp_1<<" | "<<comp_2<<std::endl;
    
}
void CM::Command_4(int argc, char** argv){
    AM* am = nullptr;
    //Initialize array
    List arr;
    am->Mode(argc,argv);
    am->Algorithm_name(argc,argv);
    am->Given_Input_File(arr,argc,argv);

    std::cout<<"---------------------------"<<std::endl;
    sort_factors(arr,argc,argv);

}

void CM::Command_5(int argc, char** argv){
    AM* am = nullptr;
    //Initialize array
    List arr;
    am->Mode(argc,argv);
    am->Algorithm_name(argc,argv);
    std::cout<<"Input size: "<< am->Input_size(argc,argv) <<std::endl;
    am->Input_order(arr,argc,argv);
    am->Write_file_1(arr,"_input.txt");

    std::cout<<"---------------------------"<<std::endl;
    sort_factors(arr,argc,argv);

}
