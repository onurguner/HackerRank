#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int check_prime(int x){
    int i;
    for(i=2;x%i!=0;i++);
        if(x==i) {
            return x;
        }
        else {
            return 0;
        }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nPlates, qIteration;
    cin >> nPlates >> qIteration;
    
    std::stack<int> sPlates;
    std::vector<std::stack<int>> vPiles;
    
    int nIndex = 0, nPlateNum = 0;
    for (nIndex = 0; nIndex < nPlates; nIndex++) {
        cin >> nPlateNum;
        sPlates.push(nPlateNum);
    }
    vPiles.push_back(sPlates);
    
    int nPrime = 1;
    for (nIndex = 0; nIndex < qIteration; nIndex++) {
        for(int i=nPrime+1;;i++) {
            if((nPrime = check_prime(i)) != 0)
                break;               
        }
        
        sPlates = vPiles.back();
        vPiles.pop_back();
        
        std::stack<int> sDivisible;
        std::stack<int> sNotDivisible;
        while (!sPlates.empty()) {
            nPlateNum = sPlates.top();
            sPlates.pop();            
            if (nPlateNum % nPrime == 0)
                sDivisible.push(nPlateNum);
            else
                sNotDivisible.push(nPlateNum);
        }
        
        if (!sDivisible.empty())
            vPiles.push_back(sDivisible);
        if (!sNotDivisible.empty())
            vPiles.push_back(sNotDivisible);
    }
    
    for (nIndex = 0; nIndex < vPiles.size(); nIndex++) {
        sPlates = vPiles[nIndex];
        while (!sPlates.empty()) {
            printf("%d\n", sPlates.top());
            sPlates.pop();
        }
    }
    return 0;
}
