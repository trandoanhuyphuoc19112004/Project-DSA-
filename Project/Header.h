#pragma once
#include <chrono>
#include<iostream>
using namespace std;
void bubbleSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);
void insertionSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);
void countingsort(int array[], int n, unsigned long long& time, unsigned long long& comparison);
void flashSort(int array[], int n, unsigned long long& time, unsigned long long& comparisons);
int getMax(int a[], int n, unsigned long long& cnt);
void radixSort(int array[], int n, unsigned long long& time, unsigned long long& comparison);
void selectionSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);
void shakerSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);
void shellSort(int arr[], int size, unsigned long long& time, unsigned long long& comparison);
void heapsort(int arr[], int n, unsigned long long& time, unsigned long long& comparison);
void max_heapify(int arr[], int size, int i, unsigned long long& comparison);
void merge(int a[], int left, int mid, int right, unsigned long long& comparison);
void mergeSort(int a[], int begin, int end, unsigned long long& time, unsigned long long& comparison);
int partition(int arr[], int left, int right, unsigned long long& comparison);
void quicksort(int arr[], int left, int right, unsigned long long& comparison); 

void copyAndGenerateData(int*& src_arr, int& size, int dataSizeType, int dataType, int*& selectionsort_arr, int*& insertionsort_arr, int*& bubblesort_arr, int*& heapsort_arr, int*& mergesort_arr,
	int*& quicksort_arr, int*& radixsort_arr, int*& shakersort_arr, int*& shellsort_arr, int*& countingsort_arr, int*& flashsort_arr);
void deleteData(int*& ptr);