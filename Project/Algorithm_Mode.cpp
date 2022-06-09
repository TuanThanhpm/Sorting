#include "Algorithm_Mode.h"
#include "Sorting_Algorithm.h"
#include "Data_Generator.h"

void AM::Parameter_Of_Sorting(List arr, std::string sort_method) {
	Sorting* s = nullptr;
	int n = arr.size();
	int u = 0; //is the max value
	if (sort_method == "selection-sort")
		return s->Selection_sort(arr);
	else if (sort_method == "insertion-sort")
		return s->Insertion_sort(arr);
	else if (sort_method == "bubble-sort")
		return s->Bubble_sort(arr);
	else if (sort_method == "shaker-sort")
		return s->Shaker_sort(arr);
	else if (sort_method == "shell-sort")
		return s->Shell_sort(arr);
	else if (sort_method == "heap-sort")
		return s->Heap_sort(arr);
	else if (sort_method == "merge-sort")
		return s->Merge_sort(arr, 0, n - 1);
	else if (sort_method == "quick-sort")
		return s->Quick_sort(arr);
	else if (sort_method == "counting-sort")
		return s->Counting_sort(arr, u);
	else if (sort_method == "radix-sort")
		return s->Radix_sort(arr);
	else if (sort_method == "flash-sort")
		return s->Flash_sort(arr);
}

double AM::Running_time(List arr, std::string sort_method) {
	clock_t start, end;
	double duration;
	//Time of function
	start = clock();
	Parameter_Of_Sorting(arr, sort_method);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	return duration;
}

void AM::Parameter_Of_Sorting_Comparison(List arr,std::string sort_method, long int& count_compare){
    NoOFCompare* noc = nullptr;
	int n = arr.size();
	int u = 0; //is the max value
	if (sort_method == "selection-sort")
		return noc->Selection_sort(arr,count_compare);
	else if (sort_method == "insertion-sort")
		return noc->Insertion_sort(arr,count_compare);
	else if (sort_method == "bubble-sort")
		return noc->Bubble_sort(arr,count_compare);
	else if (sort_method == "shaker-sort")
		return noc->Shaker_sort(arr,count_compare);
	else if (sort_method == "shell-sort")
		return noc->Shell_sort(arr,count_compare);
	else if (sort_method == "heap-sort")
		return noc->Heap_sort(arr,count_compare);
	else if (sort_method == "merge-sort")
		return noc->Merge_sort(arr, 0, n - 1,count_compare);
	else if (sort_method == "quick-sort")
		return noc->Quick_sort(arr, count_compare);
	else if (sort_method == "counting-sort")
		return noc->Counting_sort(arr, u,count_compare);
	else if (sort_method == "radix-sort")
		return noc->Radix_sort(arr,count_compare);
	else if (sort_method == "flash-sort")
		return noc->Flash_sort(arr,count_compare);
}

long int AM::Number_Of_Comparisons(List arr, std::string sort_method){
    long int count_compare = 0;
    //Calculate the number of comparisons of sort follow sort_method
    Parameter_Of_Sorting_Comparison(arr,sort_method, count_compare);
    return count_compare;
}

void AM::Mode(int argc, char** argv){
    if(strcmp(argv[1],"-a") == 0)
        std::cout<<"ALGORITHM MODE"<<std::endl;
    if(strcmp(argv[1],"-c") == 0)
        std::cout<<"COMPARE MODE"<<std::endl;
}

void AM::Algorithm_name(int argc, char** argv) {
    if(strcmp(argv[1],"-a") == 0)
        std::cout<<"Algorithm: "<<argv[2]<<std::endl;
    if(strcmp(argv[1],"-c") == 0)
        std::cout<<"Algorithm: "<<argv[2]<<" | "<<argv[3]<<std::endl;
    
}

int AM::Input_size(int argc, char** argv){
    int size;
    if(strcmp(argv[1],"-a") == 0)
        size = atoi(argv[3]);
    else if(strcmp(argv[1],"-c") == 0)
        size = atoi(argv[4]);
    if(size <= 1000000) return size;
    else std::cout<<"Out of range.";
    return 0;
}

void AM::Input_order(List& arr, int argc, char** argv){
    Data* data= nullptr;
    int n = Input_size(argc, argv);
    //Initialize array
    arr.assign(n,0);
    //Get input order from cmdline arguments
    std::string s;
    if(strcmp(argv[1],"-a") == 0)
        s = argv[4];
    else if(strcmp(argv[1],"-c") == 0)
        s = argv[5];
    //Convert string to cstring
    char * order = new char [s.length()+1];
    std::strcpy (order, s.c_str());
    //Compare to order to choose datatype 
    int datatype;
    std::cout<<"Input order: ";
    if(strcmp(order,"-rand") == 0){
        std::cout<<"randomized "<<std::endl;
        datatype = 0;
    }
    else if(strcmp(order,"-nsorted") == 0){
        std::cout<<"nearly sorted "<<std::endl;
        datatype = 3;
    }
    else if(strcmp(order,"-sorted") == 0){
        std::cout<<"sorted "<<std::endl;
        datatype = 1;
    }
    else if(strcmp(order,"-rev") == 0){
        std::cout<<"reverse sorted "<<std::endl;
        datatype = 2;
    }
    //use datatype to execute a suitable function
    data->GenerateData(arr,n,datatype);
         
}

void AM::Given_Input_File(List& arr, int argc, char** argv){
    //Get the file name follow any mode
    std::string FileName;
    if(strcmp(argv[1],"-a") == 0)
        FileName = argv[3];
    else if(strcmp(argv[1],"-c") == 0)
        FileName = argv[4];
    std::cout <<"Input file: "<< FileName << std::endl;

    //Open your input file to get data
    std::fstream fileIn;
    fileIn.open(FileName, std::ios::in);
    //Check file is exist or not
    if(!fileIn){
        std::cout<<"Can't open file "<<FileName;
        return;
    }
    else{

        int n; // number of elements in array
        int value; 
        fileIn >> n;
        std::cout<<"Input size: "<<n<<std::endl;
        //Copy data and push in L array
        while(!fileIn.eof()){
            fileIn>>value;
            arr.push_back(value);
        }
    }
    fileIn.close();
}

void AM::Output_parameter(List& arr, int argc, char** argv){
    //get the sort method from cmdline arguments
    std::string sort_method = argv[2];
    if(strcmp(argv[4],"-time") == 0 /*  || strcmp(argv[5],"-time" ) == 0 */){
        std::cout <<"Running time: "<< Running_time(arr, sort_method) <<std::endl;
    }
    else if(strcmp(argv[4],"-comp") == 0 /* || strcmp(argv[5],"-comp") == 0 */){
        std::cout <<"Comparisons: "<< Number_Of_Comparisons(arr, sort_method) <<std::endl;
    }
    else if(strcmp(argv[4],"-both") == 0 /* || strcmp(argv[5],"-both") == 0 */){
        std::cout <<"Running time: "<< Running_time(arr, sort_method)<<std::endl;
        std::cout <<"Comparisons: "<< Number_Of_Comparisons(arr, sort_method) <<std::endl;
    }
}
void AM::Command_1(int argc, char** argv){
    Mode(argc,argv);
    Algorithm_name(argc,argv);
    //Initialize array
    List arr;
    Given_Input_File(arr,argc,argv);
    std::cout<<"---------------------------"<<std::endl;
    Output_parameter(arr,argc,argv);
}

void AM::Command_2(int argc, char** argv){
    Mode(argc,argv);
    Algorithm_name(argc,argv);
    std::cout<<"Input size: "<<Input_size(argc,argv)<<std::endl;
    //Initialize array
    List arr;
    Input_order(arr, argc, argv);
    std::cout<<"---------------------------"<<std::endl;
    Output_parameter(arr,argc,argv);
}

void AM::Command_3(int argc, char** argv){
    Data* data = nullptr;
    Mode(argc,argv);
    Algorithm_name(argc,argv);
    //Size of array
    int n = Input_size(argc,argv);
    std::cout<<"Input size: "<<n<<std::endl;

    for(int i=0; i<4;i++){
        //Initialize array
        List arr;
        arr.assign(n, 0);

        std::cout<<"\nInput order: ";
        if(i == 0) std::cout<<"randomized "<<std::endl;
        else if(i == 1) std::cout<<"sorted "<<std::endl;
        else if(i == 2) std::cout<<"reverse sorted"<<std::endl;
        else std::cout<<"nearly sorted"<<std::endl;
        data->GenerateData(arr,n,i);

        std::cout<<"---------------------------"<<std::endl;
        Output_parameter(arr,argc,argv);
    }
}
