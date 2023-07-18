#include"Header.h"

void shellSort(int arr[], int size, unsigned long long& time, unsigned long long& comparison) {
	time = 0;
	comparison = 0;
	auto start = chrono::high_resolution_clock::now();
	for (int interval = size / 2; ++comparison && interval > 0; interval /= 2) {
		for (int i = interval; ++comparison && i < size; i += 1) {
			int temp = arr[i];
			int j;
			for (j = i; (++comparison && j >= interval) && (++comparison && arr[j - interval] > temp); j -= interval) {
				arr[j] = arr[j - interval];
			}
			arr[j] = temp;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}