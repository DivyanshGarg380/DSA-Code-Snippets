#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int>prefix;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1,0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

// Time: O(n) constructor, O(1) per query
// Space: O(n)