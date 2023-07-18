#include "Header.h"

// Ref: https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp
void flashSort(int array[], int n, unsigned long long &time, unsigned long long &comparisons)
{
	auto start = chrono::high_resolution_clock::now();
	time = 0;
	comparisons = 0;
	int minVal = array[0];
	int max = 0;
	int m = int(0.45 * n); // So lop 
	// Phan lop 
    int* ptr = new int[m]; 
	for (int i = 0; ++comparisons && i < m; i++)
		ptr[i] = 0;
	for (int i = 1; ++comparisons && i < n; i++)
	{
		if (++comparisons && array[i] < minVal)
			minVal = array[i];
		if (++comparisons && array[i] > array[max])
			max = i;
	}
	if (++comparisons && array[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (array[max] - minVal);
	for (int i = 0; ++comparisons && i < n; i++)
	{
		int k = int(c1 * (array[i] - minVal));
		++ptr[k]; // Dem so luong cac phan tu cua cac lop theo quy luat k = int((m - 1) * (a[i]-minVal) / (a[max] - minVal))
	}
	for (int i = 1; ++comparisons && i < m; i++)
		ptr[i] += ptr[i - 1]; // Tim vi tri ket thuc cua phan lop thu J 
    // Hoan vi toan cuc 
	swap(array[max], array[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++comparisons && nmove < n - 1)
	{
		while (++comparisons && j > ptr[k] - 1)
		{
			j++;
			k = int(c1*(array[j] - minVal));
		}
		flash = array[j];
		if (++comparisons && k < 0) break;
		while (++comparisons && j != ptr[k])
		{
			k = int(c1*(flash - minVal));
			int hold = array[t = --ptr[k]];
			array[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] ptr;
	unsigned long long trash = 0;
	unsigned long long compare = 0; 
    // Sap xep cuc bo 
	insertionSort(array, n, trash, compare);
	comparisons += compare; 
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds> (end - start).count();
}