#include "Header.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;
template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}
void deleteData(int*& ptr) {
	delete[] ptr;
	return;
}
void copyAndGenerateData(int*& src_arr, int& size, int dataSizeType, int dataType, int*& selectionsort_arr, int*& insertionsort_arr, int*& bubblesort_arr, int*& heapsort_arr, int*& mergesort_arr,
	int*& quicksort_arr, int*& radixsort_arr, int*& shakersort_arr, int*& shellsort_arr, int*& countingsort_arr, int*& flashsort_arr) {
	int dataSize[6] = { 10000, 30000,50000,100000,300000,500000 };
	size;
	switch (dataSizeType) {
	case 0:
		size = dataSize[dataSizeType];
		break;
	case 1:
		size = dataSize[dataSizeType];
		break;
	case 2:
		size = dataSize[dataSizeType];
		break;
	case 3:
		size = dataSize[dataSizeType];
		break;
	case 4:
		size = dataSize[dataSizeType];
		break;
	case 5:
		size = dataSize[dataSizeType];
		break;
	default:
		printf("Error: Unknown data size type!\n");
		return;
	}
	src_arr = new int[size];
	GenerateData(src_arr, size, dataType);
	selectionsort_arr = new int[size];
	copy(src_arr, src_arr + size, selectionsort_arr);

	insertionsort_arr = new int[size];
	copy(src_arr, src_arr + size, insertionsort_arr);

	bubblesort_arr = new int[size];
	copy(src_arr, src_arr + size, bubblesort_arr);

	heapsort_arr = new int[size];
	copy(src_arr, src_arr + size, heapsort_arr);

	mergesort_arr = new int[size];
	copy(src_arr, src_arr + size, mergesort_arr);

	quicksort_arr = new int[size];
	copy(src_arr, src_arr + size, quicksort_arr);

	radixsort_arr = new int[size];
	copy(src_arr, src_arr + size, radixsort_arr);

	shakersort_arr = new int[size];
	copy(src_arr, src_arr + size, shakersort_arr);

	shellsort_arr = new int[size];
	copy(src_arr, src_arr + size, shellsort_arr);

	countingsort_arr = new int[size];
	copy(src_arr, src_arr + size, countingsort_arr);

	flashsort_arr = new int[size];
	copy(src_arr, src_arr + size, flashsort_arr);

}
