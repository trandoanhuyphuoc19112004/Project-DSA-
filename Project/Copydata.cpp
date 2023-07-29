#include "Header.h"
#include "Gerenatedata.h"
#include "Cmdheader.h"
void deleteData(int*& ptr) {
	delete[] ptr;
	return;
}
// void copyAndGenerateData(int*& src_arr, int& size, int dataSizeType, int dataType, int*& selectionsort_arr, int*& insertionsort_arr, int*& bubblesort_arr, int*& heapsort_arr, int*& mergesort_arr,
// 	int*& quicksort_arr, int*& radixsort_arr, int*& shakersort_arr, int*& shellsort_arr, int*& countingsort_arr, int*& flashsort_arr) {
// 	int dataSize[6] = { 10000, 30000,50000,100000,300000,500000 };
// 	size;
// 	switch (dataSizeType) {
// 	case 0:
// 		size = dataSize[dataSizeType];
// 		break;
// 	case 1:
// 		size = dataSize[dataSizeType];
// 		break;
// 	case 2:
// 		size = dataSize[dataSizeType];
// 		break;
// 	case 3:
// 		size = dataSize[dataSizeType];
// 		break;
// 	case 4:
// 		size = dataSize[dataSizeType];
// 		break;
// 	case 5:
// 		size = dataSize[dataSizeType];
// 		break;
// 	default:
// 		printf("Error: Unknown data size type!\n");
// 		return;
// 	}
// 	src_arr = new int[size];
// 	GenerateData(src_arr, size, dataType);
// 	selectionsort_arr = new int[size];
// 	copy(src_arr, src_arr + size, selectionsort_arr);

// 	insertionsort_arr = new int[size];
// 	copy(src_arr, src_arr + size, insertionsort_arr);

// 	bubblesort_arr = new int[size];
// 	copy(src_arr, src_arr + size, bubblesort_arr);

// 	heapsort_arr = new int[size];
// 	copy(src_arr, src_arr + size, heapsort_arr);

// 	mergesort_arr = new int[size];
// 	copy(src_arr, src_arr + size, mergesort_arr);

// 	quicksort_arr = new int[size];
// 	copy(src_arr, src_arr + size, quicksort_arr);

// 	radixsort_arr = new int[size];
// 	copy(src_arr, src_arr + size, radixsort_arr);

// 	shakersort_arr = new int[size];
// 	copy(src_arr, src_arr + size, shakersort_arr);

// 	shellsort_arr = new int[size];
// 	copy(src_arr, src_arr + size, shellsort_arr);

// 	countingsort_arr = new int[size];
// 	copy(src_arr, src_arr + size, countingsort_arr);

// 	flashsort_arr = new int[size];
// 	copy(src_arr, src_arr + size, flashsort_arr);

// }

bool readfile(const char* filename, int *&arr, int &size)
{
    ifstream filein; 
    filein.open(filename); 
    if(!filein)
    {
        cout << "Cannot open file " << filename << endl;
		return false; 
    }
    filein >> size; 
	if (size > 1000000)
	{
		cout << "Unvalid size " << endl; 
		filein.close();
		return false; 
	}
    arr = new int [size]; 
	int idx = 0; 
    while(!filein.eof())
    {
        filein >> arr[idx++]; 
    }
    filein.close();
	return true; 
}

void savefile(const char* filename, int *arr, int size)
{
	ofstream fileout; 
	fileout.open(filename, ios :: trunc);
	if(!fileout)
	{
		cout << "Cannot open file " << filename << endl;
        return; 
	}
	fileout << size << endl; 
	for (int i = 0; i < size; i++)
		fileout << arr[i] << " ";
	fileout.close(); 
}

void copyAndGenerateData(int*& src_arr, int& size, int dataType) 
{
	src_arr = new int[size];
	GenerateData(src_arr, size, dataType);
}