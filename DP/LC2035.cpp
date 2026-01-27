#include <bits/stdc++.h>
using namespace std;

/*
    Problem: 2035. Partition Array Into Two Arrays to Minimize Sum Difference
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        if(nums[0] <= totalSum) dp[0][nums[0]] = true; // RTE here 

        for(int i = 1; i < n; i++){
            for(int target = 1; target <= totalSum; target++){
                bool notTaken = dp[i-1][target];

                bool take = false;
                if(nums[i] <= target){
                    take = dp[i-1][target-nums[i]];
                }

                dp[i][target] = take || notTaken;
            }
        }

        int mini = 1e9;
        for(int s1 = 0; s1 <= totalSum; s1++){
            if(dp[n-1][s1]){
                int s2 = totalSum - s1;
                int diff = abs(s1-s2);
                mini = min(mini, diff);
            }
        }

        return mini;
    }
};

// T.C: O(N*sum)
// S.C: O(N*sum)

// Will give RTE on Leetcode due to high memory usage -> Optimize Later