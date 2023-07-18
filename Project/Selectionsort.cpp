#include"Header.h"

void selectionSort(int a[], int n, unsigned long long& time, unsigned long long& comparison) {
	time = 0;
	auto start = chrono::high_resolution_clock::now();
	comparison = 0;

	for (int i = 0; ++comparison && i < n - 1; i++) {
		int min = i;

		for (int j = i + 1; ++comparison && j < n; j++) {
			if (++comparison && a[j] < a[min]) {
				min = j;
			}
		}

		if (++comparison && min != i)
			swap(a[i], a[min]);
	}

	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}