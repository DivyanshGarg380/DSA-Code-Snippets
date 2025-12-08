#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int cnt = 0;
        while( x > 0){
            if(x & 1) cnt++;
            x >>= 1;
        }
        return cnt;
}

// TC: O(logN)
// SC: O(1)

