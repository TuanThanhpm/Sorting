#pragma once
#include <algorithm>
#include <math.h>
#include <vector>

#define MAX_SIZE 10000
using List = std::vector<int>;

struct NoOFCompare {
	void Selection_sort(List& arr, long long int &count_compare);

	void Insertion_sort(List& arr, long long int &count_compare);

	void Bubble_sort(List& arr, long long int &count_compare);

	void Shaker_sort(List& arr, long long int &count_compare);

	void Shell_sort(List & arr, long long int &count_compare);

	void heapRebuild(int start, List& arr, int n, long long int &count_compare);
	void Heap_sort(List& arr, long long int &count_compare);

	void merge(List& arr, int first, int mid, int last, long long int &count_compare);
	void Merge_sort(List& arr, int first, int last, long long int &count_compare);

	void Quick_sort(List& arr, int first, int last, long long int &count_compare);

	void Counting_sort(List& arr, int u, long long int &count_compare);

	void Radix_sort(List& arr, long long int &count_compare);
	
	void Flash_sort(List& arr, long long int &count_compare);

	// mot so ham chua co du tham so nen mn lam ham nao thi sua ham do
};