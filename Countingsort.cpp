#include "Header.h"

void countingsort(int array[], int size, unsigned long long &time,  unsigned long long &comparison_countingsort)
{
    auto start = chrono::high_resolution_clock::now();;
    int max = array[0];

    for (int i = 1; ++comparison_countingsort && i < size; i++) {
        if (++comparison_countingsort && array[i] > max)
        {
            max = array[i];
            
        }
    }
    int* ptr_count = new int[max + 1]; 
    int* ptr_output = new int[size]; 
    // Initialize count array with all zeros.
    for (int i = 0; ++comparison_countingsort && i <= max; ++i) {
        ptr_count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; ++comparison_countingsort && i < size; i++) {
        ptr_count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1;  ++comparison_countingsort && i <= max; i++) {
        ptr_count[i] += ptr_count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; ++comparison_countingsort && i >= 0; i--) {
        ptr_output[ptr_count[array[i]] - 1] = array[i];
        ptr_count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; ++comparison_countingsort && i < size; i++) {
        array[i] = ptr_output[i];
    }
    auto end = chrono::high_resolution_clock::now();
    time = chrono :: duration_cast<chrono::microseconds> (end - start).count();
    delete[] ptr_count; 
    delete[] ptr_output; 
}