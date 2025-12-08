#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        int result = 0;
        for( int x : nums){
            result ^= x;
        }
        return result;
}

// TC: O(n)
// SC: O(1)