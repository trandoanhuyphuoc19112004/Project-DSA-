#include"Header.h"

void shakerSort(int a[], int n, unsigned long long& time, unsigned long long& comparison) {
	auto start = chrono::high_resolution_clock::now();
	time = 0;
	comparison = 0;
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++comparison && Left < Right)
	{
		for (int i = Left; ++comparison && i < Right; i++)
		{
			if (++comparison && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; ++comparison && i > Left; i--)
		{
			if (++comparison && a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}