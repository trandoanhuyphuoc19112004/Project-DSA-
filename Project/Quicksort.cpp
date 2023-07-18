#include"Header.h"
// Ref: https://www.algolist.net/Algorithms/Sorting/Quicksort
void quickSort(int arr[], int left, int right, unsigned long long& comparison) 
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	/* recursion */
	if (left < j)
		quickSort(arr, left, j, comparison);
	if (i < right)
		quickSort(arr, i, right, comparison);
}


