#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int nIndex, nQueries, nType, nValue;
    
    std::stack<int> sEnqueue;
    std::stack<int> sDequeue;
    
    cin >> nQueries;
    
    for (nIndex = 0; nIndex < nQueries; nIndex++) {
        cin >> nType;
        if (nType == 1) {
            cin >> nValue;
            sEnqueue.push(nValue);
        }
        else if (nType == 2) {
            if (sDequeue.empty()) {
                while(!sEnqueue.empty()) {
                    sDequeue.push(sEnqueue.top());
                    sEnqueue.pop();
                }
            }         
            sDequeue.pop();
        }
        else if (nType == 3) {
            if (sDequeue.empty()) {
                while(!sEnqueue.empty()) {
                    sDequeue.push(sEnqueue.top());
                    sEnqueue.pop();
                }
            }
            printf("%d\n", sDequeue.top());
        }
    }
    
    return 0;
}