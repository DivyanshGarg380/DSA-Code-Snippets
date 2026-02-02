#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int total = 0;
        int curr = 0;

        for(int i = 2; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                curr++;
                total += curr;
            }else{
                curr = 0;
            }
        }

        return total;
    }
};

// TC: O(N)
// SC: O(1)