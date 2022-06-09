#include "Sorting_Algorithm.h"

//dinh nghia cac ham sort trong nay
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

void Sorting::Shell_sort(List& arr){}

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
	int first1 = first, last1 = mid; // The first subarray
	int first2 = mid + 1, last2 = last; // The second subarray
	// Copy the smaller element into the temp array
	int tempArr[MAX_SIZE]; // Temporary array
	int index = first1; // Next available location in tempArr
	while ((first1 <= last1) && (first2 <= last2)) {
		// At this point, tempArr[first..index-1] is in order
		if (arr[first1] <= arr[first2])
			tempArr[index++] = arr[first1++];
		else
			tempArr[index++] = arr[first2++];

	}
	while (first1 <= last1) // Finish the first subarray, if necessary
		tempArr[index++] = arr[first1++];
	while (first2 <= last2) // Finish the second subarray, if necessary
		tempArr[index++] = arr[first2++];
	// Copy the result back into the original array
	for (index = first; index <= last; ++index)
		arr[index] = tempArr[index];
}
void Sorting::Merge_sort(List& arr, int first, int last){
	if (first < last) {
		int mid = (first + last) / 2; // Index of midpoint
		Merge_sort(arr, first, mid); // Sort left half
		Merge_sort(arr, mid + 1, last); // Sort right half
		merge(arr, first, mid, last); // Merge the two halves
	}
}

void Sorting::Quick_sort(List& arr, int first, int last){
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
	if (first < j) Quick_sort(arr, first, j);
	if (i < last) Quick_sort(arr, i, last);
}

void Sorting::Counting_sort(List& arr, int u){

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