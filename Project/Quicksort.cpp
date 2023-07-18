#include"Header.h"
// Ref: https://www.algolist.net/Algorithms/Sorting/Quicksort
void quickSort(int arr[], int left, int right, unsigned long long& comparison) 
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
	if (left < j)
		quickSort(arr, left, j, comparison);
	if (i < right)
		quickSort(arr, i, right, comparison);
}


