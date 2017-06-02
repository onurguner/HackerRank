#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int N, int *arr) {
	int i, j, shift = 0;
	int value;
	for (i = 1; i<N; i++)
	{
		value = arr[i];
		j = i;
		while (j>0 && value<arr[j-1])
		{
			arr[j] = arr[j-1];
            shift++;
			j = j - 1;
		}
		arr[j] = value;
	}
    cout << shift;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int arr_size = 0;
    cin >> arr_size;
    int arr[arr_size];
    for (int i=0; i<arr_size; i++) {
        cin >> arr[i];
    }
    insertionSort(arr_size, arr);
    return 0;
}