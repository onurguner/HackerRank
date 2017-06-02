#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n;
    cin >> q;
    
    std::vector<int> S[n];    
    int lastAns = 0, x, y, t, temp, size;
    
    for (int i=0; i<q; i++) {
        cin >> t;
        cin >> x;
        cin >> y;
        
        int index = (x ^ lastAns) % n;
        if (t == 1) {
            S[index].push_back(y);
        }
        else if (t == 2) {
            size = S[index].size();
            lastAns = S[index].at(y%size);
            printf("%d\n", lastAns);            
        }
    }
    
    return 0;
}