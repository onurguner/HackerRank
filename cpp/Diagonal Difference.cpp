#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    
    int sum1=0, sum2=0;
    
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
           if (a_i == a_j)
               sum1+=a[a_i][a_j];
           if ((a_i+a_j)==n-1)
               sum2+=a[a_i][a_j];
       }
    }
    int diff = (sum1 > sum2) ? sum1-sum2 : sum2-sum1;
    cout << diff;
    
    return 0;
}
