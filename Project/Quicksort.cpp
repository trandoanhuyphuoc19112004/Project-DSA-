#include"Header.h"

int partition(int arr[], int left, int right, unsigned long long& comparison) {
	int pivot = right;
	right--;
	while (++comparison && left <= right) {
		while (++comparison && arr[left] < arr[pivot] && ++comparison && left <= right) left++;
		while (++comparison && arr[left] > arr[pivot] && ++comparison && left <= right) right--;
		if (++comparison && left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	swap(arr[left], arr[pivot]);
	return left;
}
void quicksort(int arr[], int left, int right, unsigned long long& time, unsigned long long& comparison) {
	auto start = chrono::high_resolution_clock::now();
	if (++comparison && left >= right) return;
	int pivot = partition(arr, left, right, comparison);
	quicksort(arr, left, pivot - 1, time, comparison);
	quicksort(arr, pivot + 1, right, time, comparison);
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}