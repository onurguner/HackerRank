#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    float nP=0, nN=0, nZ=0;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
        if (arr[arr_i] > 0)
            nP++;
        else if (arr[arr_i] < 0)
            nN++;
        else
            nZ++;
    }
    
    printf("%f\n", nP / n);
    printf("%f\n", nN / n);
    printf("%f\n", nZ / n);
    
    return 0;
}