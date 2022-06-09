#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>

#define MAX_SIZE 10000
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
	void Merge_sort(List& arr, int first, int last);

	int partition(List& arr, int start, int end);
	void Quick_sort(List& arr);

	void Counting_sort(List& arr, int u);

	void Radix_sort(List& arr);
	
	void Flash_sort(List& arr);

	// mot so ham chua co du tham so nen mn lam ham nao thi sua ham do
};