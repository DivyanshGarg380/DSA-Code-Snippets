#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int bit = 0; bit < 32; bit++){
            int count = 0;
            for(int num: nums){
                if(num & (1 << bit)) count++;
            }
            if(count % 3 != 0){
                result |= (1<<bit);
            }
        }
        return result;
}

// TC: O(32 * N) ~ O(N)
// SC: O(1)

// Approach 2
int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
}

// TC: O(N)
// SC: O(1)