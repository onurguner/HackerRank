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
    for (int j = 0; j<ar.size(); j++) {
     cout << ar[j] << " ";
    }
    cout << "\n";
}
void insertionSort(vector <int>  ar) {
    int iSize = ar.size();
    int iEnd = ar[iSize-1];
    for (int i = iSize-2; i>=0; i--) {
        if (iEnd < ar[i]) {
            ar[i+1] = ar[i];
            printArray(ar);
            if (i == 0) {
                ar[i] = iEnd;
                printArray(ar);
            }
        }
        else {
            ar[i+1] = iEnd;
            printArray(ar);
            break;
        }      
    }
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

    insertionSort(_ar);
    return 0;
}