#include"Header.h"

int main()
{
	int size = 0;
	unsigned long long cp = 0;
	unsigned long long time = 0;
	int* selectionsort_arr;
	int* insertionsort_arr;
	int* bubblesort_arr;
	int* heapsort_arr;
	int* mergesort_arr;
	int* quicksort_arr;
	int* radixsort_arr;
	int* shakersort_arr;
	int* shellsort_arr;
	int* countingsort_arr;
	int* flashsort_arr;
	int* arr;
	copyAndGenerateData(arr, size, 0, 0, selectionsort_arr, insertionsort_arr, bubblesort_arr, heapsort_arr, mergesort_arr, quicksort_arr, radixsort_arr, shakersort_arr, shellsort_arr, countingsort_arr, flashsort_arr);
	// Display output
	
	cout << ">Comparision and time using<" << endl;
	cout << "============================" << endl;
	selectionSort(selectionsort_arr, size, time, cp);
	cout << "Selection sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;

	insertionSort(insertionsort_arr, size, time, cp);
	cout << "Insertion sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;

	cout << "============================" << endl;
	bubbleSort(bubblesort_arr, size, time, cp); 
	cout << "Bubble sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;
	
	heapsort(heapsort_arr, size, time, cp); 
	cout << "Heap sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;

	time = 0; 
	cp = 0;
	auto start = chrono::high_resolution_clock::now();
	mergeSort(mergesort_arr,0, size - 1,  cp); 
	auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
	cout << "Merge sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;

	time = 0; 
	cp = 0;
	auto go = chrono::high_resolution_clock::now();
	quickSort(quicksort_arr, 0, size - 1, cp); 
	auto finish = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(finish - go).count();
	cout << "quick sort" << endl;
	cout << "comparision: " << cp << endl;
	cout << "time using (micro second): " << time << endl;
	cout << "============================" << endl;

	radixSort(flashsort_arr, size, time, cp);
	cout << "Radix sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;

	shakerSort(shakersort_arr, size, time, cp); 
	cout << "Shaker sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;

	shellSort(shellsort_arr, size, time, cp); 
	cout << "Shell sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;

	countingsort(countingsort_arr, size, time, cp); 
	cout << "Counting sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;

	flashSort(flashsort_arr, size, time, cp); 
	cout << "Flash sort" << endl;
	cout << "Comparision: " << cp << endl;
	cout << "Time using (micro second): " << time << endl;
	cout << "============================" << endl;

	deleteData(selectionsort_arr);
	deleteData(insertionsort_arr);
	deleteData(bubblesort_arr);
	deleteData(heapsort_arr);
	deleteData(mergesort_arr);
	deleteData(quicksort_arr);
	deleteData(radixsort_arr);
	deleteData(shakersort_arr);
	deleteData(shellsort_arr);
	deleteData(countingsort_arr);
	deleteData(flashsort_arr);
	deleteData(arr);
}