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

int getoutputparamID(char* param) {
    if (strcmp(param, "-comp") == 0)
        return 0;
    else if (strcmp(param, "-time") == 0)
        return 1;
    else if (strcmp(param, "-both") == 0)
        return 2;
    else
        return -1;
}

string printInputOrder(int order_index) {
    switch (order_index) {
    case 0: return "Randomize";
    case 1: return "Sorted";
    case 2: return "Reversed";
    case 3: return "Nearly Sorted";
    }
}

void Command_Line_1(const char* filename, string name_algo, char* output_param) {
    unsigned long long time, comparison;
    int algoID = getAlgoId(name_algo.c_str());
    int* arr = nullptr;
    int size = 0;
    int param_index = getoutputparamID(output_param);
    cout << "ALGORITHM MODE:" << endl;
    cout << "Algorithm: " << name_algo << endl;
    bool flag = readfile(filename, arr, size);
    if (!flag)
        return;

    (*SORT_ALGO[algoID])(arr, size, time, comparison);
    cout << "Input file: " << filename << endl;
    cout << "Input size: " << size << endl;
    cout << "-------------------------" << endl;
    if (param_index==2) {
        cout << "Running time: " << time << endl;
        cout << "Comparison: " << comparison << endl;
    }
    else if (param_index == 1) {
        cout << "Running time: " << time << endl;
    }
    else if (param_index == 0) {
        cout << "Comparison: " << comparison << endl;
    }

    delete[] arr;
}

void Command_Line_2(string name_algo, int inputSize, char* inputOrder, char* output_param) {
    unsigned long long time, compare;
    int* arr = nullptr;
    int algoID = getAlgoId(name_algo.c_str());
    int order_index = getinputorderId(inputOrder);
    int param_index = getoutputparamID(output_param);
    if (order_index == -1)
    {
        cout << "Unvalid order" << endl;
        return;
    }
    copyAndGenerateData(arr, inputSize, order_index);
    cout << "ALGORITHM MODE:" << endl;
    cout << "Algorithm: " << name_algo << endl;
    (*SORT_ALGO[algoID])(arr, inputSize, time, compare);
    cout << "Input size: " << inputSize << endl;
    cout << "Input order: "<<printInputOrder(order_index)<<endl;
    //printInputOrder(order_index);
    cout << "-------------------------" << endl;
    if (param_index == 2) {
        cout << "Running time: " << time << endl;
        cout << "Comparison: " << compare << endl;
    }
    else if (param_index == 1) {
        cout << "Running time: " << time << endl;
    }
    else if (param_index == 0) {
        cout << "Comparison: " << compare << endl;
    }
    delete[] arr;
}

void Command_Line_3(string name_algo, int input_size, char* output_parameter) {
    unsigned long long time1, time2, time3, time4;
    unsigned long long compare1, compare2, compare3, compare4;
    int algoID = getAlgoId(name_algo.c_str());
    int output_Index = 0;
    if (strcmp(output_parameter, "-comp")==0)
        output_Index = 0;
    else if (strcmp(output_parameter, "-time")==0)
        output_Index = 1;
    else if (strcmp(output_parameter, "-both")==0)
        output_Index = 2;
    else
        output_Index = -1;
    if (output_Index == -1) {
        cout << "Unvalid output parameter!!!" << endl;
        return;
    }

    int* arr1 = NULL;
    int* arr2 = NULL;
    int* arr3 = NULL;
    int* arr4 = NULL;

    copyAndGenerateData(arr1, input_size, 0);
    copyAndGenerateData(arr2, input_size, 1);
    copyAndGenerateData(arr3, input_size, 2);
    copyAndGenerateData(arr4, input_size, 3);

    (*SORT_ALGO[algoID])(arr1, input_size, time1, compare1);
    (*SORT_ALGO[algoID])(arr2, input_size, time2, compare2);
    (*SORT_ALGO[algoID])(arr3, input_size, time3, compare3);
    (*SORT_ALGO[algoID])(arr4, input_size, time4, compare4);

    if (output_Index == 1) {
        cout << "ALGORITHM MODE:" << endl;
        cout << "Algorithm: " << name_algo << endl;
        cout << "Input size: " << input_size << endl << endl;

        cout << "Input order: Randomize" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << time1 << endl;
        cout << "Comparison (if required): " << endl << endl;

        cout << "Input order: Nearly Sorted" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << time4 << endl;
        cout << "Comparison (if required): " << endl << endl;

        cout << "Input order: Sorted" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << time2 << endl;
        cout << "Comparison (if required): " << endl << endl;

        cout << "Input order: Reversed" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << time3 << endl;
        cout << "Comparison (if required): " << endl << endl;
    }
    else if (output_Index == 0) {
        cout << "ALGORITHM MODE:" << endl;
        cout << "Algorithm: " << name_algo << endl;
        cout << "Input size: " << input_size << endl << endl;

        cout << "Input order: Randomize" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << endl;
        cout << "Comparison (if required): " << compare1 << endl << endl;

        cout << "Input order: Nearly Sorted" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << endl;
        cout << "Comparison (if required): " << compare4 << endl << endl;

        cout << "Input order: Sorted" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << endl;
        cout << "Comparison (if required): " << compare2 << endl << endl;

        cout << "Input order: Reversed" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << endl;
        cout << "Comparison (if required): " << compare3 << endl << endl;
    }
    else if (output_Index == 2) {
        cout << "ALGORITHM MODE:" << endl;
        cout << "Algorithm: " << name_algo << endl;
        cout << "Input size: " << input_size << endl << endl;

        cout << "Input order: Randomize" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << time1 << endl;
        cout << "Comparison (if required): " << compare1 << endl << endl;

        cout << "Input order: Nearly Sorted" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << time4 << endl;
        cout << "Comparison (if required): " << compare4 << endl << endl;

        cout << "Input order: Sorted" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << time2 << endl;
        cout << "Comparison (if required): " << compare2 << endl << endl;

        cout << "Input order: Reversed" << endl;
        cout << "---------------------------" << endl;
        cout << "Running time (if required): " << time3 << endl;
        cout << "Comparison (if required): " << compare3 << endl << endl;
    }
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
}

void Command_Line_4(const char* filename, string name_algo1, string name_algo2)
{
    unsigned long long time1, time2;
    unsigned long long compare1, compare2;

    int algoID1 = getAlgoId(name_algo1.c_str());
    int algoID2 = getAlgoId(name_algo2.c_str());

    int* arr1 = nullptr;
    int* arr2 = nullptr;

    int size1 = 0, size2 = 0;

    cout << "COMPARE MODE:" << endl;
    cout << "Algorithm: " << name_algo1 << "|" << name_algo2 << endl;

    bool flag1 = readfile(filename, arr1, size1);
    bool flag2 = readfile(filename, arr2, size2);
    if (!flag1 || !flag2)
        return;

    (*SORT_ALGO[algoID1])(arr1, size1, time1, compare1);
    (*SORT_ALGO[algoID2])(arr2, size2, time2, compare2);

    cout << "Input size: " << size1 << endl;
    cout << "Input file: " << filename << endl;
    cout << "-------------------------" << endl;
    cout << "Running time: " << time1 << "|" << time2 << endl;
    cout << "Comparisons: " << compare1 << "|" << compare2 << endl;

    delete[] arr1;
    delete[] arr2;
}

void Command_Line_5(string name_algo1, string name_algo2, int inputsize, char* inputorder)
{
    unsigned long long time1, time2;
    unsigned long long compare1, compare2;

    int algoID1 = getAlgoId(name_algo1.c_str());
    int algoID2 = getAlgoId(name_algo2.c_str());

    int* arr1 = nullptr;
    int* arr2 = nullptr;
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

    cout << "Input order: " << printInputOrder(order_index) << endl;
    cout << "-------------------------" << endl;
    cout << "Running time:" << time1 << "|" << time2 << endl;
    cout << "Comparisons:" << compare1 << "|" << compare2 << endl;

    delete[] arr1;
    delete[] arr2;
}
