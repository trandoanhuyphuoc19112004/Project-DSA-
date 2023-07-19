#include"Header.h"
int getMax(int a[], int n, unsigned long long& cnt) 
{
	int max = a[0];
	for (int i = 1; ++cnt && i < n; i++) {
		if (++cnt && a[i] > max)
			max = a[i];
	}
	return max; //maximum element from the array  
}
void radixSort(int array[], int n, unsigned long long& time, unsigned long long& comparison) 
{
	auto start = chrono::high_resolution_clock::now();
	time = 0;
	comparison = 0;
	// Get maximum element
	unsigned long long one = 0;
	int max = getMax(array, n, comparison);

	// Apply counting sort to sort elements based on place value.
	unsigned long long temp_nothing = 0; 
	for (int place = 1; ++comparison && max / place > 0; place *= 10)
		countingSort(array, n, temp_nothing,  one);
	comparison = comparison  + one;
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}
