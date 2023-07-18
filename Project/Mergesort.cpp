#include "Header.h"

void merge(int a[], int left, int mid, int right, unsigned long long& comparison) {
	int p = mid - left + 1, q = right - mid;
	int* b = new int[p], * c = new int[q];
	for (int i = 0; ++comparison && i < p; i++) {
		b[i] = a[left + i];
	}
	for (int j = 0; ++comparison && j < q; j++) {
		c[j] = a[mid + j + 1];
	}
	int i = 0, j = 0, k = left;
	while (++comparison && i < p && ++comparison && j < q) {
		if (c[j] <= b[i]) {
			a[k] = c[j];
			j++;
		}
		else {
			a[k] = b[i];
			i++;
		}
		k++;
		comparison++;
	}
	while (++comparison && i < p) {
		a[k] = b[i];
		i++;
		k++;
	}
	while (++comparison && j < q) {
		a[k] = c[j];
		j++;
		k++;
	}
	delete[] b;
	delete[] c;
}

void mergeSort(int a[], int begin, int end, unsigned long long& time, unsigned long long& comparison) {
	time = 0;
	comparison = 0;
	auto start = chrono::high_resolution_clock::now();
	if (++comparison && begin >= end) return;
	int mid = begin + (end - begin) / 2;
	mergeSort(a, begin, mid, time, comparison);
	mergeSort(a, mid + 1, end, time, comparison);
	merge(a, begin, mid, end, comparison);
	auto finish = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - start).count();
}