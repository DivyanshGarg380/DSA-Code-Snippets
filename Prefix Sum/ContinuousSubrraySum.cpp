#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        unordered_map<int, int> mp;
        int prefix = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int remainder = k == 0 ? prefix : prefix % k;
            if(mp.count(remainder)){
                if(i - mp[remainder] > 1) return true;
            }else{
                mp[remainder] = i;
            }
        }
        return false;
    }
};

// TC: O(N)
// SC: O(N)