#include "Cmdheader.h"
void (*SORT_ALGO[11])(int *a, int size, unsigned long long &time, unsigned long long &comparison) = {selectionSort, insertionSort, bubbleSort, heapSort, mergeSort, quickSort, radixSort, shakerSort, shellSort, countingSort, flashSort};
bool checkAlgorithm1(string name[], int number,  string inputname1)
{
    bool flag = false; 
   
    // Check inputname1 
    for (int i = 0; i < number; i++)
    {
        if (name[i] == inputname1)
            {
                flag = true; 
                break; 
            }
    }
    if (flag)
        return true;
    return false; 
}

bool checkAlgorithm2(string name[], int number,  string inputname1, string inputname2)
{
    bool flag1 = false; 
    bool flag2 = false; 
    // Check inputname1 
    for (int i = 0; i < number; i++)
    {
        if (name[i] == inputname1)
            {
                flag1 = true; 
                break; 
            }
    }
    // Check inputname2
     for (int i = 0; i < number; i++)
    {
        if (name[i] == inputname2)
            {
                flag2 = true; 
                break; 
            }
    }
    if (flag1 && flag2)
        return true;
     return false; 
}

// Ref: https://github.com/tonip1z/Lab03_DSA_Group03/blob/master/SOURCE/Experiment.cpp
int getAlgoId(const char* algo_name)
{
    if (strcmp(algo_name, "selection-sort") == 0)
        return 0;
    if (strcmp(algo_name, "insertion-sort") == 0)
        return 1;
    if (strcmp(algo_name, "bubble-sort") == 0)
        return 2;
    if (strcmp(algo_name, "heap-sort") == 0)
        return 3;
    if (strcmp(algo_name, "merge-sort") == 0)
        return 4;
    if (strcmp(algo_name, "quick-sort") == 0)
        return 5;
    if (strcmp(algo_name, "radix-sort") == 0)
        return 6;
    if (strcmp(algo_name, "shaker-sort") == 0)
        return 7;
    if (strcmp(algo_name, "shell-sort") == 0)
        return 8;
    if (strcmp(algo_name, "counting-sort") == 0)
        return 9;
    if (strcmp(algo_name, "flash-sort") == 0)
        return 10;
    
    return -1;
}

int getinputorderId(char* order_name)
{
    if (strcmp(order_name, "-rand") == 0)
        return 0;
    if (strcmp(order_name, "-sorted") == 0)
        return 1;
    if (strcmp(order_name, "-rev") == 0)
        return 2;
    if (strcmp(order_name, "-nsorted") == 0)
        return 3;
    return -1;
}

void Comparison_inputfile(const char* filename, string name_algo1, string name_algo2)
{
    unsigned long long time1, time2; 
    unsigned long long compare1, compare2;

    int algoID1 = getAlgoId(name_algo1.c_str());
    int algoID2 = getAlgoId(name_algo2.c_str()); 

    int *arr1 = nullptr;
    int *arr2 = nullptr; 

    int size1 = 0, size2 = 0; 

    cout << "COMPARE MODE:" << endl; 
    cout << "Algorithm: " << name_algo1 << "|" << name_algo2 << endl;

    bool flag1 =  readfile(filename, arr1, size1); 
    bool flag2 = readfile(filename, arr2, size2);
    if (!flag1 || !flag2)
        return; 

    (*SORT_ALGO[algoID1])(arr1, size1, time1, compare1); 
    (*SORT_ALGO[algoID2])(arr2, size2, time2, compare2); 

    cout << "Input size:" << size1 << endl; 
    cout << "-------------------------" << endl; 
    cout << "Running time:" << time1 << "|" << time2 << endl;
    cout << "Comparisons:" << compare1 << "|" << compare2 << endl; 

    delete [] arr1; 
    delete [] arr2; 
}

void Comparison_inputsize_order(string name_algo1, string name_algo2, int inputsize, char* inputorder)
{
    unsigned long long time1, time2; 
    unsigned long long compare1, compare2;

    int algoID1 = getAlgoId(name_algo1.c_str());
    int algoID2 = getAlgoId(name_algo2.c_str()); 

    int *arr1 = nullptr; 
    int *arr2 = nullptr; 
    int order_index = getinputorderId(inputorder); 


    if (order_index == -1)
    {
        cout << "Unvalid order" << endl; 
        return; 
    }

    copyAndGenerateData(arr1, inputsize, order_index); 
    copyAndGenerateData(arr2, inputsize, order_index);

    savefile("input.txt", arr1, inputsize); 

    (*SORT_ALGO[algoID1])(arr1, inputsize, time1, compare1); 
    (*SORT_ALGO[algoID2])(arr2, inputsize, time2, compare2); 

    cout << "COMPARE MODE:" << endl; 
    cout << "Algorithm: " << name_algo1 << "|" << name_algo2 << endl;
    cout << "Input size:" << inputsize << endl; 

    cout << "Input order:" << inputorder << endl; 
    cout << "-------------------------" << endl; 
    cout << "Running time:" << time1 << "|" << time2 << endl;
    cout << "Comparisons:" << compare1 << "|" << compare2 << endl; 

    delete [] arr1; 
    delete [] arr2; 
}