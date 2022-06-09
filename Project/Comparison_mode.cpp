#include "Comparison_mode.h"

void CM::sort_factors(List& arr,int argc, char** argv){
    AM* am = nullptr;

    int Time_1, Time_2;
    //Calculate time of first sort
    Time_1 = am->Running_time(arr,argv[2]);
    //Calculate time of second sort
    Time_2 = am->Running_time(arr,argv[3]);
    std::cout<<"Running time: "<<Time_1<<" | "<<Time_2<<std::endl;

    int comp_1, comp_2;
    //Calculate the number of comparisons of first sort
    comp_1= am->Number_Of_Comparisons(arr,argv[2]);
    //Calculate the number of comparisons of second sort
    comp_2 = am->Number_Of_Comparisons(arr,argv[3]);
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

    std::cout<<"---------------------------"<<std::endl;
    sort_factors(arr,argc,argv);

}
