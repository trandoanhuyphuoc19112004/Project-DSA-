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
	// Get maximum element
	unsigned long long one = 0;
	unsigned long long two = 0;
	int max = getMax(array, n, one);

	// Apply counting sort to sort elements based on place value.
	unsigned long long temp_nothing = 0; 
	for (int place = 1; max / place > 0; place *= 10)
		countingsort(array, n, temp_nothing,  two);
	comparison = one + two;
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}
