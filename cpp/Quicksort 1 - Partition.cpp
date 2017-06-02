#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(vector <int>  ar) {
    for (int i=0; i<ar.size(); i++) {
        cout << ar[i] << " ";
    }
    cout<<"\n";
}
    
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void partition(vector <int>  ar) {
   // Enter code for partitioning and printing here. 
    int start = 0, end = ar.size() - 1;
    
    swap(ar[0], ar[end]);
   
    int pIndex = start;
    int pivot = ar[end];
    for (int i = start; i < end; i++) {
		if (ar[i] <= pivot) {
			swap(ar[i], ar[pIndex]);
			pIndex++;
		}
    }
    swap(ar[pIndex], ar[end]);
    
    printArray(ar);
}

int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
    
     for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

   partition(_ar);
   
   return 0;
}