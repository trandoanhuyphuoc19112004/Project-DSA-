#include"Header.h"

void heapsort(int arr[], int n, unsigned long long& time, unsigned long long& comparison) {
	auto start = chrono::high_resolution_clock::now();
	time = 0;
	comparison = 0;
	for (int i = n / 2 - 1; ++comparison && i >= 0; i--) {
		max_heapify(arr, n, i, comparison);
	}
	for (int i = n - 1; ++comparison && i > 0; i--) {
		swap(arr[i], arr[0]);
		max_heapify(arr, i, 0, comparison);
	}
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}

void max_heapify(int arr[], int size, int i, unsigned long long& comparison) {
	int left = 2 * i + 1,
		right = 2 * i + 2,
		largest = i;
	if (++comparison && left < size && ++comparison && arr[left] > arr[largest]) {
		largest = left;
	}
	if (++comparison && right < size && ++comparison && arr[right] > arr[largest]) {
		largest = right;
	}
	if (++comparison && largest != i) {
		swap(arr[i], arr[largest]);
		max_heapify(arr, size, largest, comparison);
	}
}