#include "Algorithm_Mode.h"
#include "Sorting_Algorithm.h"
#include "Data_Generator.h"

int AM::get_algorithm(std::string sort_method)
{
    std::vector<std::string> Algorithms = {
                        "selection-sort",
                        "insertion-sort",
                        "bubble-sort",
                        "shaker-sort",
                        "shell-sort",
                        "heap-sort",
                        "merge-sort",
                        "quick-sort",
                        "counting-sort",
                        "radix-sort",
                        "flash-sort"};
    for (int i = 0; i < 11; i++)
        if (sort_method == Algorithms[i])
            return i;

    return -1;
}

void AM::execute_Sorting(List& arr, std::string sort_method, int pos) {

	Sorting* s = nullptr;
	int n = arr.size();
	int u = (n< RAND_MAX) ? n : RAND_MAX; //is the max value
    switch(pos){
        case 0: s->Selection_sort(arr); break;
        case 1: s->Insertion_sort(arr); break;
        case 2: s->Bubble_sort(arr); break;
        case 3: s->Shaker_sort(arr); break;
        case 4: s->Shell_sort(arr); break;
        case 5: s->Heap_sort(arr); break;
        case 6: s->Merge_sort(arr,0,n-1); break;
        case 7: s->Quick_sort(arr,0,n-1); break;
        case 8: s->Counting_sort(arr,u); break;
        case 9: s->Radix_sort(arr); break;
        case 10: s->Flash_sort(arr); break;
    }
} 

double AM::Running_time(List& arr, std::string sort_method) {
    int pos = get_algorithm(sort_method);
    if(pos == -1){
        std::cout<<"Unknown sort method"<<std::endl;
        exit(0);
    }
    Sorting* s = nullptr;
    
    //https://helpex.vn/question/do-thoi-gian-thuc-thi-cua-mot-ham-trong-c-60939b17f45eca37f4be15a3
	using std::chrono::high_resolution_clock;
	using std::chrono::duration_cast;
	using std::chrono::duration;
	using std::chrono::milliseconds;

	auto t1 = high_resolution_clock::now();
	execute_Sorting(arr, sort_method, pos);
	auto t2 = high_resolution_clock::now();

	 /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

	return ms_int.count();
}

void AM::execute_Sorting_Comparison(List& arr,std::string sort_method,int pos, unsigned long long& count_compare){
    NoOFCompare* noc = nullptr;
	int n = arr.size();
	int u = (n< RAND_MAX) ? n : RAND_MAX; //is the max value

    switch(pos){
        case 0: noc->Selection_sort(arr,count_compare); break;
        case 1: noc->Insertion_sort(arr,count_compare); break;
        case 2: noc->Bubble_sort(arr,count_compare); break;
        case 3: noc->Shaker_sort(arr,count_compare); break;
        case 4: noc->Shell_sort(arr,count_compare); break;
        case 5: noc->Heap_sort(arr,count_compare); break;
        case 6: noc->Merge_sort(arr, 0, n - 1,count_compare); break;
        case 7: noc->Quick_sort(arr,0,n-1, count_compare); break;
        case 8: noc->Counting_sort(arr, u,count_compare); break;
        case 9: noc->Radix_sort(arr,count_compare); break;
        case 10: noc->Flash_sort(arr,count_compare); break;
    }
}

unsigned long long AM::Number_Of_Comparisons(List& arr, std::string sort_method){
    int pos = get_algorithm(sort_method);
    if(pos == -1){
        std::cout<<"Unknown sort method"<<std::endl;
        exit(0);
    }

    unsigned long long count_compare = 0;
    //Calculate the number of comparisons of sort follow sort_method
    execute_Sorting_Comparison(arr,sort_method,pos, count_compare);
    return count_compare;
}

void AM::Mode(int argc, char** argv){
    if(strcmp(argv[1],"-a") == 0)
        std::cout<<"ALGORITHM MODE"<<std::endl;
    else if(strcmp(argv[1],"-c") == 0)
        std::cout<<"COMPARE MODE"<<std::endl;
    else{
        std::cout<<"Unknown mode"<<std::endl;
        exit(0);
    } 
}

void AM::Algorithm_name(int argc, char** argv) {

    if(strcmp(argv[1],"-a") == 0)
        std::cout<<"Algorithm: "<<argv[2]<<std::endl;
    else if(strcmp(argv[1],"-c") == 0)
        std::cout<<"Algorithm: "<<argv[2]<<" | "<<argv[3]<<std::endl;
    
}

int AM::Input_size(int argc, char** argv){
    int size;
    if(strcmp(argv[1],"-a") == 0)
        size = atoi(argv[3]);
    else if(strcmp(argv[1],"-c") == 0)
        size = atoi(argv[4]);

    //size must be smaller than or equal to 1000000
    if(size <= 1000000) 
        return size;
    else{
        std::cout<<"Size is out of range.";
        exit(0);
    }
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
    else return;

    //Convert string to cstring
    char * order = new char [s.length()+1];
    strcpy_s (order,s.length()+1, s.c_str());

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
    else {
        std::cout<<"unknown sort order"<<std::endl;
        exit(0);
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
        exit(0);
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

void AM::Output_parameter(List& arr, std::string s,int argc, char** argv){
    //Convert string to cstring
    char * type = new char [s.length()+1];
    strcpy_s (type,s.length()+1, s.c_str());
    //get the sort method from cmdline arguments
    std::string sort_method = argv[2];
    if(strcmp(type,"-time") == 0  ){
        std::cout<<"Running time: "<<Running_time(arr, sort_method) <<" ms\n";
    }
    else if(strcmp(type,"-comp") == 0 ){
        std::cout <<"Comparisons: "<< Number_Of_Comparisons(arr, sort_method) <<std::endl;
    }
    else if(strcmp(type,"-both") == 0   ){
        std::cout<<"Running time: "<<Running_time(arr, sort_method) <<" ms\n";
        std::cout <<"Comparisons: "<< Number_Of_Comparisons(arr, sort_method) <<std::endl;
    }
    else{
        std::cout <<"Unknown output parameter."<<std::endl;
        exit(0);
    }
}

void AM:: Write_file_1(List arr, std::string FileName){
    std::fstream FileOut;
    FileOut.open(FileName,std::ios::out);
    FileOut<<arr.size()<<std::endl;
    for(auto &i : arr)
        FileOut<<i<<" ";
    FileOut.close();
}

void AM::Command_1(int argc, char** argv){
    Mode(argc,argv);
    Algorithm_name(argc,argv);
    //Initialize array
    List arr;
    Given_Input_File(arr,argc,argv);

    std::cout<<"---------------------------"<<std::endl;
    //Access an suitable type (time, comparisons or both)
    std::string type = argv[4];
    Output_parameter(arr,type,argc,argv);
    //Write file which sorted data
    Write_file_1(arr,"output.txt");
}

void AM::Command_2(int argc, char** argv){
    Mode(argc,argv);
    Algorithm_name(argc,argv);
    std::cout<<"Input size: "<<Input_size(argc,argv)<<std::endl;
    //Initialize array
    List arr;
    Input_order(arr, argc, argv);
    //Write file which generating data
    Write_file_1(arr,"_input.txt");
    std::cout<<"---------------------------"<<std::endl;
    //Access an suitable type (time, comparisons or both)
    std::string type = argv[5];
    Output_parameter(arr,type,argc,argv);
    //Write file which sorted data
    Write_file_1(arr,"output.txt");
    
}

void AM::Command_3(int argc, char** argv){
    Data* data = nullptr;
    Mode(argc,argv);
    Algorithm_name(argc,argv);
    //Size of array
    int n = Input_size(argc,argv);
    std::cout<<"Input size: "<<n<<std::endl;
    std::string FileName;
    for(int i=0; i<4;i++){
        //Initialize array
        List arr;
        arr.assign(n, 0);

        std::cout<<"\nInput order: ";
        if(i == 0) {
            std::cout<<"randomized "<<std::endl;
            FileName = "input_1.txt";
        }
        else if(i == 1) {
            std::cout<<"sorted "<<std::endl;
            FileName = "input_3.txt";
        }
        else if(i == 2) {
            std::cout<<"reverse sorted "<<std::endl;
            FileName = "input_4.txt";
        }
        else {
            std::cout<<"nearly sorted "<<std::endl;
            FileName = "input_2.txt";
        }
        data->GenerateData(arr,n,i);
        Write_file_1(arr,FileName);

        std::cout<<"---------------------------"<<std::endl;
        //Access an suitable type (time, comparisons or both)
        std::string type = argv[4];
        Output_parameter(arr,type,argc,argv);
    }
}
