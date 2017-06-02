#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int* A, int start, int end, int val) {
    if (start > end) {
        return -1;
    }
    
    int mid = (start + end) / 2;
    if (A[mid] == val) {
        return mid;
    }
    else if (val < A[mid]) {
        return binary_search(A, start, mid-1, val);
    }
    else {
        return binary_search(A, mid+1, end, val);
    }
}

    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iValue, iSize, iIndex;
    
    cin >> iValue;
    cin >> iSize;
    
    int A[iSize];
    for (iIndex = 0; iIndex < iSize; iIndex++) {
        cin >> A[iIndex];
    }    
    iIndex = binary_search(A, 0, iSize-1, iValue);
    cout << iIndex;
    return 0;
}