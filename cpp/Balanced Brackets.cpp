#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isOpening(char c) {
    if (c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

bool isClosing(char c) {
    if (c == ')' || c == '}' || c == ']')
        return true;
    return false;
}

bool arePair(char first, char second) {
    if (first == '(' && second == ')')
        return true;
    if (first == '{' && second == '}')
        return true;
    if (first == '[' && second == ']')
        return true;
    return false;
}

bool isBalanced(string exp) {
    std::stack<char> s;
    int n = exp.length();
    for (int i=0;i<n;i++) {
            
            if (isOpening(exp[i]) == true) {
                s.push(exp[i]);
            }
            else if (isClosing(exp[i]) == true) {
                if (s.empty() || !arePair(s.top(), exp[i])) {
                    return false;
                }
                s.pop();
            }
    }
    
    return s.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        
        if (isBalanced(s) == true)
            printf("%s\n", "YES");
        else
            printf("%s\n", "NO");        
    }
    return 0;
}