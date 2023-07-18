#include"Header.h"

void insertionSort(int a[], int n, unsigned long long& time, unsigned long long& comparison) {
	time = 0;
	auto start = chrono::high_resolution_clock::now();
	comparison = 0;
	int i, j, key;

	for (i = 1; ++comparison && i < n; i++) {
		key = a[i];
		j = i - 1;

		while (++comparison && j >= 0
			&& ++comparison && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = key;
	}

	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}