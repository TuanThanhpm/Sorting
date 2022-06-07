#pragma once
#include <algorithm>
#include <math.h>
#include <vector>

//Tuong tu typedef struct 
using List = std::vector<int>;

struct Sort {
	void Selection_sort(List& arr);
	void Insertion_sort(List& arr);
	void Bubble_sort(List& arr);
	void Shaker_sort(List& arr);
	void Shell_sort(List & arr);
	void Heap_sort(List& arr);
	void Merge_sort(List& arr, int first, int last);
	void Quick_sort(List& arr, int first, int last);
	void Counting_sort(List& arr);
	void Radix_sort(List& arr);
	void Flash_sort(List& arr);

	// mot so ham chua co du tham so nen mn lam ham nao thi sua ham do
};