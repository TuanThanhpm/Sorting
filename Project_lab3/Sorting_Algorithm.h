#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
#include <iostream>

//Tuong tu typedef struct 
using List = std::vector<int>;


struct Sorting {
	

	void Selection_sort(List& arr);

	void Insertion_sort(List& arr);

	void Bubble_sort(List& arr);

	void Shaker_sort(List& arr);

	void Shell_sort(List & arr);

	void heapRebuild(int start, List& arr, int n);
	void Heap_sort(List& arr);

	void merge(List& arr, int first, int mid, int last);
	void merge_sort(List& arr, int first, int last);
	//typedef merge-sort function
	void Merge_sort(List& arr);

	void quick_sort(List& arr, int first, int last);
	//typedef quick_sort function
	void Quick_sort(List& arr);

	void counting_sort(List& arr, int u);
	//typedef quick_sort function
	void Counting_sort(List& arr);

	void Radix_sort(List& arr);
	
	void Flash_sort(List& arr);

};

