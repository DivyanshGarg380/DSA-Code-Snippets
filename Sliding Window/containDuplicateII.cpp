#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int>seen;
    for(int i = 0; i < nums.size(); i++){
        if(seen.find(nums[i]) != seen.end() && i - seen[nums[i]] <= k) return true;
        seen[nums[i]] = i;
    }
    return false;
}

// TC: O(N)
// SC: O(map.size()) ~ O(N) -> Worst case
 