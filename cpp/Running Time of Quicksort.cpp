#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int iInsertionSortSwaps = 0, iQuickSortSwaps = 0;

void insertionSort(int *arr, int N) {
	int i, j;
	int value;
	for (i = 1; i<N; i++)
	{
		value = arr[i];
		j = i;
		while (j>0 && value<arr[j-1])
		{
			arr[j] = arr[j-1];
            iInsertionSortSwaps++;
			j = j - 1;
		}
		arr[j] = value;
	}
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int start, int end) {
    int pIndex = start;
    int pivot = arr[end];
    for (int i=start; i<end; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            iQuickSortSwaps++;
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    iQuickSortSwaps++;
    return pIndex;
}

void quickSort(int *arr, int start, int end) {
    if (start < end) {
        int pIndex = partition(arr, start, end);        
        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr_size;
    cin >> arr_size;
    int arr1[arr_size];
    int arr2[arr_size];
    for (int i=0; i<arr_size; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    
    insertionSort(arr1, arr_size);
    quickSort(arr2, 0, arr_size-1);
    
    cout << (iInsertionSortSwaps - iQuickSortSwaps);
    
    return 0;
}