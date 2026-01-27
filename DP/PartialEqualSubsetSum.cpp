#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[201][10001];
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x: nums) sum += x;

        if(sum % 2) return false;
        memset(dp, -1, sizeof(dp));
        return solve(nums.size()-1, sum/2, nums);
    }

    bool solve(int i, int target, vector<int>& nums){
        if(target == 0) return true;
        if(i < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool notTake = solve(i-1, target, nums);
        bool take = false;
        if(nums[i] <= target){
            take = solve(i-1, target - nums[i], nums);
        }
        return dp[i][target] = take || notTake;
    }
};

// TC: O(n*sum)
// SC: O(n*sum)