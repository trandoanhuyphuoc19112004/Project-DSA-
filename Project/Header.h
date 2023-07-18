#pragma once
#include <chrono>
using namespace std; 
void bubbleSort(int a[], int n, unsigned long long& time, unsigned long long& comparison); 
void insertionSort(int a[], int n, unsigned long long& time, unsigned long long& comparison); 
void countingsort(int array[], int n, unsigned long long& time, unsigned long long& comparison); 
void flashSort(int array[], int n, unsigned long long& time, unsigned long long& comparisons); 
int getMax(int a[], int n, unsigned long long& cnt); 
void radixSort(int array[], int n , unsigned long long& time, unsigned long long& comparison);
void selectionSort(int a[], int n, unsigned long long& time, unsigned long long& comparison); 
void shakerSort(int a[], int n, unsigned long long& time, unsigned long long& comparison); 
void shellSort(int arr[], int size, unsigned long long& time, unsigned long long& comparison); 