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

bool areEqual(int* pHeights) {
    if (pHeights[0] == pHeights[1] && pHeights[0] == pHeights[2])
        return true;
    return false;
}

int minHeight(int* pHeights) {
    int minH = INT_MAX;
    for (int i=0;i<3;i++) {
         if (pHeights[i] < minH) 
             minH = pHeights[i];
    }
    return minH;
}

int main(){
    int n1;
    int n2;
    int n3;       
    cin >> n1 >> n2 >> n3;    
    
    int heights[] = {0, 0, 0};
    int index[] = {0, 0, 0};
    
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
       heights[0] +=h1[h1_i];
    }    
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
        heights[1] +=h2[h2_i];
    }    
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
        heights[2] +=h3[h3_i];
    }
    
    int minheight = minHeight(heights);
    
    while(!areEqual(heights)) {
        for (int i=0;i<3;i++) {
            if (heights[i] > minheight) {                
                if (i==0 && index[i] < n1) {
                    heights[i] -= h1[index[i]];                    
                }
                else if (i==1 && index[i] < n2) {
                    heights[i] -= h2[index[i]];
                }
                else if (i==2 && index[i] < n3) {
                    heights[i] -= h3[index[i]];
                }
                index[i]++;
                minheight = minHeight(heights);
            }            
        }
    }
    
    printf("%d\n", minheight);
    return 0;
}