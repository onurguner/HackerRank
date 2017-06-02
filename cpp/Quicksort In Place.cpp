#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int *arr, int start, int end) {
    for (int i=start; i<=end; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
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
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quickSort(int *arr, int start, int end, int arr_size) {
    if (start < end) {
        int pIndex = partition(arr, start, end);        
        printArray(arr, 0, arr_size - 1);
        quickSort(arr, start, pIndex - 1, arr_size);
        quickSort(arr, pIndex + 1, end, arr_size);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr_size;
    cin >> arr_size;
    
    int arr[arr_size];
    for (int i=0; i<arr_size; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, arr_size-1, arr_size);
    
    return 0;
}