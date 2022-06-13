#include "Sorting_Algorithm.h"


int Sorting::get_algorithm(std::string sort_method)
{
    std::string Algorithms[] = {"selection-sort",
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

func_ptr Sorting::get_algorithm_address(int alg)
{
    void (*Algorithms[11])(List&) = {
        Selection_sort,
        Insertion_sort,
        Bubble_sort,
        Shaker_sort,
        Shell_sort,
        Heap_sort,
        Merge_sort,
        Quick_sort,
        Counting_sort,
        Radix_sort,
        Flash_sort
	};
    return Algorithms[alg];
}

void Sorting::Selection_sort(List& arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i) {
		// At this point, arr[0..i-1] is sorted, and its
		// entries are smaller than those in arr[i..n-1].
		int minIdx = i;
		// Select the smallest entry in arr[i..n-1]
		for (int j = i + 1; j < n; ++j)
			if (arr[j] < arr[minIdx])
				minIdx = j;
		// Swap the smallest entry, arr[minIdx], with arr[i]
		std::swap(arr[minIdx], arr[i]);
	}
}

void Sorting::Insertion_sort(List& arr){
	int n=arr.size();
	for (int i = 1; i < n; ++i){
	// Find the right position in the sorted region arr[0..i-1]
	// for arr[i]; shift, if necessary, to make room
		int key = arr[i];
		int j = i-1;
		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
	arr[j + 1] = key;
	}
}

void Sorting::Bubble_sort(List& arr){
	int n = arr.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
}

void Sorting::Shaker_sort(List& arr){
	int n= arr.size();
	int i, j, k;
   	for(i = 0; i < n;) {
      	for(j = i+1; j < n; j++) {
         	if(arr[j] < arr[j-1])
            	std::swap(arr[j], arr[j-1]);
      	}	
      	n--;
      	for(k = n-1; k > i; k--) {
         	if(arr[k] < arr[k-1])
            	std::swap(arr[k], arr[k-1]);
      	}
      	i++;
   	}
}

void Sorting::Shell_sort(List& arr){
	int n = arr.size();
	for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j = i;           
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
				j-= gap;
			}
            arr[j] = temp;
        }
    }
}

void Sorting::heapRebuild(int start, List& arr, int n){
	int leftChild = 2 * start + 1; // A left child must exist
	if (leftChild >= n) return;
	int largerChild = leftChild; // Make assumption about larger child
	int rightChild = 2 * start + 2; // A right child might not exist
	if (rightChild < n){ // Whether a right child exists
		// A right child exists; check whether it is larger
		if (arr[rightChild] > arr[largerChild])
			largerChild = rightChild; // Assumption was wrong

	}
	// If arr[start] is smaller than the larger child, swap values
	if (arr[start] < arr[largerChild]){
		std::swap(arr[largerChild], arr[start]);
		heapRebuild(largerChild, arr, n); // Recursion at that child
	}
}
void Sorting::Heap_sort(List& arr){
	int n=arr.size();
	// Build initial heap
	for (int index = (n - 1) / 2; index >= 0; index--)
		heapRebuild(index, arr, n);
	std::swap(arr[0], arr[n - 1]); // swap the largest element to the end
	int heapSize = n - 1; // Heap region size decreases by 1
	while (heapSize > 1) {
		heapRebuild(0, arr, heapSize);
		heapSize--;
		std::swap(arr[0], arr[heapSize]);
	}
}

void Sorting::merge(List& arr, int first, int mid, int last){
	int subArrayOne = mid - first + 1;
    int subArrayTwo = last - mid;
 
    // Create temp arrays
    int *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[first + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = first; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void Sorting::merge_sort(List& arr, int first, int last){
	if (first < last) {
		int mid = (first + last) / 2; // Index of midpoint
		merge_sort(arr, first, mid); // Sort left half
		merge_sort(arr, mid + 1, last); // Sort right half
		merge(arr, first, mid, last); // Merge the two halves
	}
}

void Sorting::Merge_sort(List& arr){
	merge_sort( arr, 0, arr.size() - 1);
}

void Sorting::quick_sort(List& arr, int first, int last) {
	int pivot = arr[(first + last) / 2];
	int i = first, j = last;
	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (i < j);
	if (first < j) quick_sort(arr, first, j);
	if (i < last) quick_sort(arr, i, last);
}

void Sorting::Quick_sort(List& arr) {
	quick_sort(arr,0,arr.size() - 1);
}

void Sorting::counting_sort(List& arr, int u){
	int *output = new int [arr.size()];  
    int *count = new int [u + 1] {0}, i; 

    for (i = 0; i < arr.size(); ++i) 
        ++count[arr[i]]; 

    for (i = 1; i <= u; ++i) 
        count[i] += count[i - 1]; 
  
    for (i = 0; i < arr.size(); ++i) { 
        output[count[arr[i]] - 1] = arr[i]; 
        --count[arr[i]]; 
    } 

    for (i = 0; i < arr.size(); ++i) 
        arr[i] = output[i]; 

	delete []output, count;

}

void Sorting::Counting_sort(List& arr){
	int n=arr.size();
	int u = (n< RAND_MAX) ? n : RAND_MAX; //is the max value
	counting_sort(arr,u);
}


void Sorting::Radix_sort(List& arr){
	int n = arr.size();
	int max_val = arr[0]; // get maximum value in the array
	for (int i = 1; i < n; ++i)
		if (arr[i] > max_val) max_val = arr[i];
	int digits = 0, div; // find the maximum number of digits
	do{
		digits++;
		div = max_val / pow(10, digits);
	} while (div > 0);
	int **tempArr = new int*[10]; // declare variables for temp store
	for (int i = 0; i < 10; ++i)
		tempArr[i] = new int[n];
	int tempCount[10];
	// form groups of numbers and combine groups
	for (int i = 0; i < digits ; ++i) {
		int exp = pow(10, i);
		for (int j = 0; j < 10; ++j) // reset the counting
			tempCount[j] = 0;
		for (int j = 0; j < n; ++j) { // form groups
			int idx = (arr[j] / exp) % 10;
			tempArr[idx][tempCount[idx]++] = arr[j];
		}
		int idx = 0; // combine groups
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < tempCount[j]; ++k)
				arr[idx++] = tempArr[j][k];
	}
}

void Sorting::Flash_sort(List& arr){

}