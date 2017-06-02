#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printArray(vector <int>  &ar, int start, int end) {
    for (int i=start; i<=end; i++) {
        cout << ar[i] << " ";
    }
    cout<<"\n";
}

int partition(vector <int> &ar, int start, int end) {
    vector<int> left, right;
	int i = 0, pivot = ar[start];
	for (i = start + 1; i <= end; i++) {
		if (ar[i] <= pivot) {
			left.push_back(ar[i]);
		}
		else if (ar[i] > pivot) {
			right.push_back(ar[i]);
		}
	}
	int pIndex = start;
	for (i = 0; i < left.size(); i++) {
		ar[pIndex + i] = left[i];
	}
	pIndex += i;
	ar[pIndex] = pivot;
	for (i = 0; i < right.size(); i++) {
		ar[pIndex + i + 1] = right[i];
	}
	return pIndex;
}

void quickSort(vector <int> &ar, int start, int end) {
    if (start < end) {
        int pIndex = partition(ar, start, end);
        quickSort(ar, start, pIndex-1);
        quickSort(ar, pIndex+1, end);    
        
        printArray(ar, start, end);
    }    
}

void quickSort(vector <int> &arr) {
   // Complete this function
    quickSort(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}