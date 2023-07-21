#pragma once
#include <chrono>
#include<iostream>
using namespace std;
void bubbleSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);

void insertionSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);

void countingSort(int array[], int n, unsigned long long& time, unsigned long long& comparison);

void flashSort(int array[], int n, unsigned long long& time, unsigned long long& comparisons);

int getMax(int a[], int n, unsigned long long& cnt);
void radixSort(int array[], int n, unsigned long long& time, unsigned long long& comparison);

void selectionSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);

void shakerSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);

void shellSort(int arr[], int size, unsigned long long& time, unsigned long long& comparison);

void heapSort(int arr[], int n, unsigned long long& time, unsigned long long& comparison);
void max_heapify(int arr[], int size, int i, unsigned long long& comparison);

void merge(int a[], int left, int mid, int right, unsigned long long& comparison);
void mergeSortCompare(int a[], int begin, int end, unsigned long long& comparison);
void mergeSort(int a[], int n, unsigned long long& time, unsigned long long& comparison);

void quickSortCompare(int arr[], int left, int right, unsigned long long& comparison);
void quickSort(int arr[], int n, unsigned long long& time, unsigned long long& comparison);

