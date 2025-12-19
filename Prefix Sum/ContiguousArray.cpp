#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = -1;
        int prefix = 0;
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) prefix--;
            else prefix++;
            if(mp.count(prefix)){
                maxLen = max(maxLen, i - mp[prefix]);
            }else{
                mp[prefix] = i;
            }
        }
        return maxLen;
    }
};

// TC: O(N)
// SC: O(N)