#include"Header.h"
// Ref: https://www.algolist.net/Algorithms/Sorting/Quicksort
void quickSortCompare(int arr[], int left, int right, unsigned long long& comparison) 
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (++ comparison && i <= j) {
		while (++comparison && arr[i] < pivot)
			i++;
		while (++comparison && arr[j] > pivot)
			j--;
		if (++comparison && i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	/* recursion */
	if (++comparison && left < j)
		quickSortCompare(arr, left, j, comparison);
	if (++comparison && i < right)
		quickSortCompare(arr, i, right, comparison);
}

void quickSort(int arr[], int n, unsigned long long& time, unsigned long long& comparison)
{
	time = 0;
	comparison = 0;
	auto start = chrono::high_resolution_clock::now();
	quickSortCompare(arr, 0, n - 1, comparison);
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}

