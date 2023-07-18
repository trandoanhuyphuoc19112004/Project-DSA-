#include"Header.h"

void shakerSort(int a[], int n, unsigned long long& time, unsigned long long& comparison) {
	time = 0;
	int L = 0, R = n - 1;
	auto start = chrono::high_resolution_clock::now();
	while (++comparison && L < R) {
		for (int i = L; ++comparison && i < R; ++i)
			if (++comparison && a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		--R;
		for (int i = R - 1; ++comparison && i >= L; --i)
			if (++comparison && a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		++L;
	}
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}