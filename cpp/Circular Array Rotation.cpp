#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int ar_size, rotation, query_size;
    cin >> ar_size >> rotation >> query_size;
    rotation = rotation % ar_size;
    int arr[ar_size];
    for (int i=0; i<ar_size; i++) {
        cin >> arr[i];
    }
    int index;
    for (int j=0; j<query_size; j++) {
        cin >> index;
        cout << arr[(index + ar_size - rotation) % ar_size] << "\n";
    }
    
    return 0;
}