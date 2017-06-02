#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct compare {
    bool operator()(const int& l, const int& r)	{
		return l > r;
	}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nN, nK, nValue;
    
    std::priority_queue<int, std::vector<int>, compare> minHeap;
    
    cin >> nN >> nK;    
    for (int i=0; i<nN; i++) {
        cin >> nValue;        
        minHeap.push(nValue);
    }
    
    int nCounter = 0;
    while (minHeap.size() > 1 && minHeap.top() < nK) {
        int nFirst = minHeap.top();
        minHeap.pop();
        int nSecond = minHeap.top();
        minHeap.pop();
        int nCookie = nFirst + 2 * nSecond;
        minHeap.push(nCookie);
        nCounter++;
    }
    if (minHeap.top() >= nK) {
        printf("%d\n", nCounter);
    }
    else {
        printf("%d\n", -1);
    }
    
    return 0;
}