#include "Header.h"

void bubbleSort(int a[], int n, unsigned long long& time, unsigned long long& comparison) {
	time = 0;
	comparison = 0;
	auto start = chrono::high_resolution_clock::now();
	comparison = 0;

	for (int i = 0; ++comparison && i < n - 1; i++) {
		for (int j = 0; ++comparison && j < n - 1 - i; j++) {
			if (++comparison && a[j + 1] < a[j])
				swap(a[j + 1], a[j]);
		}
	}

	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}