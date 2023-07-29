#include"Header.h"
#include "Cmdheader.h"
#include "Gerenatedata.h"
#include "Copydata.h"
int main(int argc, char **argv)
{
	 bool flag = true; 
	string arrAlgorithm[11] = {"selection-sort", "bubble-sort", "counting-sort", "insertion-sort", "shaker-sort", "shell-sort", "quick-sort", "radix-sort", "heap-sort", "flash-sort", "merge-sort"};
 
	if (argc <=4 )
	{
		flag = false; 
	}
	else if (argc == 5)
	{
		if (!strcmp(argv[1], "-a")) 
		{
			if (!strcmp(argv[4], "-comp") || !strcmp(argv[4], "-both") || !strcmp(argv[4], "-time")) 
			{
				//Command Line 1
				if (argv[3][strlen(argv[3] - 1)] < '0' || argv[3][strlen(argv[3] - 1)] > '9') 
				{
					string name_algo = argv[2];
					char* output_param = argv[4];
					const char* filename = (const char*)argv[3];
					flag = checkAlgorithm1(arrAlgorithm, 11, name_algo);
					if (flag)
						Command_Line_1(filename, name_algo, output_param);
				}
				//Command Line 3
				else {
					string name_algo1 = argv[2];
					int size = stoi(argv[3]);
					char* output_Parameter = argv[4];
					flag = checkAlgorithm1(arrAlgorithm, 11, name_algo1);
					if (flag && size <= 1000000) {
						Command_Line_3(name_algo1, size, output_Parameter);
					}
				}
			}
		}
		// Command Line 4
		else if(!strcmp(argv[1], "-c"))
		{
			string name_algo1 = argv[2]; 
			string name_algo2 = argv[3];
			const char* filename = (const char*)argv[4];
			flag = checkAlgorithm2(arrAlgorithm, 11, name_algo1, name_algo2);
			if (flag)
			{
				Command_Line_4(filename, name_algo1, name_algo2); 
			}
		}
	}
	else if (argc == 6)
	{
		//Command Line 5
		if(!strcmp(argv[1], "-c"))
		{
			string name_algo1 = argv[2]; 
			string name_algo2 = argv[3];
			int size = stoi(argv[4]);
			flag = checkAlgorithm2(arrAlgorithm, 11, name_algo1, name_algo2);
			if (flag && size < 1000000)
			{
				Command_Line_5(name_algo1, name_algo2, size, argv[5]);
			}
		}
		//Command Line 2
		else if (!strcmp(argv[1], "-a")) {
			string name_algo = argv[2];
			int size = stoi(argv[3]);
			flag = checkAlgorithm1(arrAlgorithm, 11, name_algo);
			if (flag && size < 1000000) {
				Command_Line_2(name_algo, size, argv[4], argv[5]);
			}
		}

	}
	if(!flag)
	{
		cout << "Syntax error " << endl;
		exit(0); 
	}
}
	// int size = 0;
	// unsigned long long cp = 0;
	// unsigned long long time = 0;
	// // int* selectionsort_arr;
	// // int* insertionsort_arr;
	// // int* bubblesort_arr;
	// // int* heapsort_arr;
	// // int* mergesort_arr;
	// // int* quicksort_arr;
	// // int* radixsort_arr;
	// // int* shakersort_arr;
	// // int* shellsort_arr;
	// // int* countingsort_arr;
	// // int* flashsort_arr;
	// int* arr;
	// copyAndGenerateData(arr, size, 0, 1);
	// savefile("Text.txt", arr, size); 
	// deleteData(arr);

	// Display output
	
	// cout << ">Comparision and time using<" << endl;
	// cout << "============================" << endl;
	// selectionSort(selectionsort_arr, size, time, cp);
	// cout << "Selection sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// insertionSort(insertionsort_arr, size, time, cp);
	// cout << "Insertion sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;

	// cout << "============================" << endl;
	// bubbleSort(bubblesort_arr, size, time, cp); 
	// cout << "Bubble sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;
	
	// heapSort(heapsort_arr, size, time, cp); 
	// cout << "Heap sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// mergeSort(mergesort_arr, size, time, cp);
	// cout << "Merge sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// quickSort(quicksort_arr, size, time, cp); 
	// cout << "Quick sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// radixSort(flashsort_arr, size, time, cp);
	// cout << "Radix sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// shakerSort(shakersort_arr, size, time, cp); 
	// cout << "Shaker sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// shellSort(shellsort_arr, size, time, cp); 
	// cout << "Shell sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// countingSort(countingsort_arr, size, time, cp); 
	// cout << "Counting sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// flashSort(flashsort_arr, size, time, cp); 
	// cout << "Flash sort" << endl;
	// cout << "Comparision: " << cp << endl;
	// cout << "Time using (micro second): " << time << endl;
	// cout << "============================" << endl;

	// deleteData(selectionsort_arr);
	// deleteData(insertionsort_arr);
	// deleteData(bubblesort_arr);
	// deleteData(heapsort_arr);
	// deleteData(mergesort_arr);
	// deleteData(quicksort_arr);
	// deleteData(radixsort_arr);
	// deleteData(shakersort_arr);
	// deleteData(shellsort_arr);
	// deleteData(countingsort_arr);
	// deleteData(flashsort_arr);



	