#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, x, q;
    cin >> n;
    
    std::stack<int> s1;
    std::stack<int> s2;
    s2.push(0);
    
    for (int i=0; i<n; i++) {
        cin >> q;
        if (q == 1) {
            cin >> x;
            /*if (s1.empty())
                s1.push(x);
            else
                s1.push(max(x, s1.top()));*/
            s1.push(x);            
            if (x >= s2.top()) 
                s2.push(x);
        }
        else if (q == 2) {
            if (!s1.empty()) {
                if (s1.top() == s2.top())
                    s2.pop();
                s1.pop();
            }
        }
        else if (q == 3) {
            if (!s2.empty())
                printf("%d\n", s2.top());
            //printf("%d\n", s1.top());
        }
    }
    return 0;
}